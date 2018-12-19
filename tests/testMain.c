#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>

#include <dobble-config.h>
#include <dobble.h>
#include <graphics.h>
#include <time.h>
#include <plateau.h>
#include <fichierVersPlateau.h>
#include <automate.h>
#include <unistd.h>


/// Etat du compte à rebous (lancé/non lancé)
static bool timerRunning = false;

static Plateau PlateauCourant;
static Etat etatCourant;
static Vect2 mousePosition;

void onMouseMoveMenuDebut();
void onMouseMoveJeu();
void onMouseMoveMenuFin();

void onMouseClickMenuDebut();
void onMouseClickJeu();
void onMouseClickMenuFin();

void onTimerTickMenuDebut();
void onTimerTickJeu();
void onTimerTickMenuFin();

void renderSceneMenuDebut();
void renderSceneJeu();
void renderSceneMenuFin();

// --------------------------------------------------------------
// Global Behaviors
// --------------------------------------------------------------
void onMouseMove(int x, int y)
{
	mousePosition.x = x;
	mousePosition.y = y;
	switch (etatCourant)
    {
        case MenuDebut:
			onMouseMoveMenuDebut();
            return;
        case Jeu:
			onMouseMoveJeu();
			return;
		case MenuFin:
			onMouseMoveMenuFin();
			return;
        default:
            return;
    }

}

void onMouseClick()
{
    switch (etatCourant)
    {
        case MenuDebut:
			onMouseClickMenuDebut();
            return;
        case Jeu:
			onMouseClickJeu();
			return;
		case MenuFin:
			onMouseClickMenuFin();
			return;
        default:
            return;
    }
}

void onTimerTick()
{
	switch (etatCourant)
    {
        case MenuDebut:
            onTimerTickMenuDebut();
            return;

        case Jeu:
            onTimerTickJeu();
			return;
		
		case MenuFin:
			onTimerTickMenuFin();
			return;
		
        default:
            break;
    }
}

void renderScene()
{
    switch (etatCourant)
    {
        case MenuDebut:
            renderSceneMenuDebut();
            return;
        case Jeu:
            renderSceneJeu();
			return;
		
		case MenuFin:
			renderSceneMenuFin();
			return;
		
        default:
            break;
    }
}

// --------------------------------------------------------------
// MenuDebut behaviour
// --------------------------------------------------------------
#define MAIN_MENU_PLAY_POS_X WIN_WIDTH / 2
#define MAIN_MENU_PLAY_POS_Y WIN_HEIGHT / 2
#define MAIN_MENU_PLAY_RADIUS 50

void onMouseMoveMenuDebut() {}

void onMouseClickMenuDebut() {
	// Si l'on clique sur le bouton Jouer alors, lancer le jeu
	if(distanceSquaredBetween(mousePosition, newVect2(MAIN_MENU_PLAY_POS_X, MAIN_MENU_PLAY_POS_Y)) <= pow(MAIN_MENU_PLAY_RADIUS, 2)) {
		etatSuivant(&etatCourant, Play);
	}
}

void onTimerTickMenuDebut() {}

void renderSceneMenuDebut() {
	char title[100];

	// Efface le contenu de la fenêtre
	clearWindow();

	// Titre
	sprintf(title, "RICM3 - Dobble");
	drawText(title, WIN_WIDTH / 2, 10, Center, Top);

	// Bouton jouer
    drawText("Jouer", WIN_WIDTH / 2, WIN_HEIGHT / 2, Center, Middle);
    drawCircle(WIN_WIDTH / 2, WIN_HEIGHT / 2, 50, 0, 100, 0, 100);
	
	// Met au premier plan le résultat des opérations de dessin
	showWindow();
}

// --------------------------------------------------------------
// Jeu behaviour
// --------------------------------------------------------------
void onMouseMoveJeu() {}

void onMouseClickJeu() {
	int xcentercard, ycentercard;

	getCardCenter(UpperCard,&xcentercard,&ycentercard);
	Vect2 centerCard = newVect2(xcentercard,ycentercard);

	// L'image sur laquelle le joueur a cliqué
	Image imageCliquee = Clic_a_l_interieur(PlateauCourant, centerCard, mousePosition);
	if (PlateauCourant.imageCommune == imageCliquee){ // Si c'est la bonne
		// Ajout de point et de temps
		PlateauCourant.Score++;
		PlateauCourant.TempsRestant=PlateauCourant.TempsRestant+3;

		// Piocher une nouvelle carte
		PlateauCourant.bas = PlateauCourant.haut;
		PlateauCourant.haut = choisitCarteAleatoire(&PlateauCourant);
		PlateauCourant.imageCommune = TrouverImageCommune(&(PlateauCourant.haut), &(PlateauCourant.bas));
	}
	else if (imageCliquee != -1) { // Si ce n'est pas la bonne et qu'il a bien cliqué sur une image
		// On enlève du temps
		PlateauCourant.TempsRestant=PlateauCourant.TempsRestant-3;
		
		// On vérifie que la partie n'est pas terminée
		if(lose(&PlateauCourant)) etatSuivant(&etatCourant, Perdu);
	}
	requestRedraw();
}
void onTimerTickJeu() {
	// On actualise le timer
	PlateauCourant.TempsRestant--;

	// On vérifie que la partie n'est pas terminée
	if(lose(&PlateauCourant)) etatSuivant(&etatCourant, Perdu);

	requestRedraw();
}

void renderSceneJeu() {
	char title[100];
	char timer[10];

	// Efface le contenu de la fenêtre
	clearWindow();

	// Titre
	sprintf(title, "RICM3-Dobble    Score %d", PlateauCourant.Score);
	drawText(title, WIN_WIDTH / 2, 10, Center, Top);

	// Timer
	sprintf(timer, "%d", PlateauCourant.TempsRestant);
	drawText(timer, WIN_WIDTH / 2, 40, Center, Top);

	// Carte supérieure
	CardPosition currentCard = UpperCard;

	drawCardShape(currentCard, 5, 252, 252, 252, 155, 119, 170);
    int i;
    for(i = 0; i < PlateauCourant.haut.nbIcones; i++) {
        Icone ic = PlateauCourant.haut.icones[i];
        drawIconCartesien(currentCard, ic.image, ic.position.x, ic.position.y, ic.rotation, ic.scale);
    }

	// Carte inférieure
	currentCard = LowerCard;

	drawCardShape(currentCard, 5, 252, 252, 252, 155, 119, 170);
    for(i = 0; i < PlateauCourant.bas.nbIcones; i++) {
        Icone ic = PlateauCourant.bas.icones[i];
        drawIconCartesien(currentCard, ic.image, ic.position.x, ic.position.y, ic.rotation, ic.scale);
    }

	// Met au premier plan le résultat des opérations de dessin
	showWindow();
}

// --------------------------------------------------------------
// MenuFin behaviour
// --------------------------------------------------------------

// Position et rayon des boutons
#define MENU_FIN_REJOUER_X WIN_WIDTH / 2
#define MENU_FIN_REJOUER_Y 5 * WIN_HEIGHT / 8
#define MENU_FIN_REJOUER_RADIUS 50

#define MENU_FIN_RETOUR_X WIN_WIDTH / 2
#define MENU_FIN_RETOUR_Y 5 * WIN_HEIGHT / 6
#define MENU_FIN_RETOUR_RADIUS 100

void onMouseMoveMenuFin() {}

void onMouseClickMenuFin() {
	Transition t = Rien;

	// Si l'on clique sur le bouton rejouer alors,rejouer
	if(distanceSquaredBetween(mousePosition, newVect2(MENU_FIN_REJOUER_X, MENU_FIN_REJOUER_Y)) <= pow(MENU_FIN_REJOUER_RADIUS, 2)) {
		t = Rejouer;
	}

	// Si l'on clique sur le bouton RetourMenu alors, retour au menu
	if(distanceSquaredBetween(mousePosition, newVect2(MENU_FIN_RETOUR_X, MENU_FIN_RETOUR_Y)) <= pow(MENU_FIN_RETOUR_RADIUS, 2)) {
		t = RetourMenu;
	}
	
	etatSuivant(&etatCourant, t);
}

void onTimerTickMenuFin() {}

void renderSceneMenuFin() {
	char title[100] = "RICM3 - Dobble";
	char score[10];
	char message[100] = "GAME OVER";

	// Efface le contenu de la fenêtre
	clearWindow();

	// Titre
	drawText(title, WIN_WIDTH / 2, 50, Center, Top);

	// Score
	sprintf(score, "Score : %d", PlateauCourant.Score);
	drawText(score, WIN_WIDTH / 2, 100, Center, Top);

	// Message de fin
	drawText(message, WIN_WIDTH / 2, 150, Center, Top);

	// Bouton Rejouer (en bas de la fenêtre pour ne pas cliquer malencontreusement dessus après avoir terminé une partie)
    drawText("Rejouer", MENU_FIN_REJOUER_X, MENU_FIN_REJOUER_Y, Center, Middle);
    drawCircle(MENU_FIN_REJOUER_X, MENU_FIN_REJOUER_Y, MENU_FIN_REJOUER_RADIUS, 0, 100, 0, 100);


	// Bouton Retour au menu (en bas de la fenêtre pour ne pas cliquer malencontreusement dessus après avoir terminé une partie)
	drawText("Retour au menu", MENU_FIN_RETOUR_X, MENU_FIN_RETOUR_Y , Center, Middle);
    drawCircle(MENU_FIN_RETOUR_X, MENU_FIN_RETOUR_Y, MENU_FIN_RETOUR_RADIUS, 0, 100, 0, 100);
	
	// Met au premier plan le résultat des opérations de dessin
	showWindow();
}

void InitJeu() {
	PlateauCourant.haut = choisitCarteAleatoire(&PlateauCourant);
	PlateauCourant.bas = choisitCarteAleatoire(&PlateauCourant);
	PlateauCourant.imageCommune = TrouverImageCommune(&(PlateauCourant.haut), &(PlateauCourant.bas));
	PlateauCourant.Score = 0;
	PlateauCourant.TempsRestant = 30;
	startTimer();
	timerRunning = true;
}

// --------------------------------------------------------------
// Main
// --------------------------------------------------------------
int main(int argc, char **argv)
{
	srand(time(NULL));

	if (!initializeGraphics())
	{
		printf("dobble: Echec de l'initialisation de la librairie graphique.\n");
		return 1;
	}

	if (loadIconMatrix(DATA_DIRECTORY "/Matrice12x10_Icons90x90_BandW.png") != 1)
	{
		printf("dobble: Echec du chargement des icônes.\n");
		return -1;
	}

	// Init de l'état courant de l'automate qui gère les différentes phases de jeu
	etatCourant = MenuDebut;

	// Lecture du fichier avec toutes les cartes
    PlateauCourant = fichierVersPlateau(DATA_DIRECTORY "/pg26.txt");
	
	// Initialisation des posiions aléatoires des icones sur les cartes (lent pour 9 et 10 icones, des optimisations sont encore nécessaire)
	initCardsIconsPositions(&PlateauCourant);
	
	mainLoop();

	freeGraphics();


	return 0;
}

// --------------------------------------------------------------
// Automate
// --------------------------------------------------------------
void etatSuivant(Etat* etatCourant, Transition t) {
    switch (*etatCourant)
    {
        case MenuDebut:
            switch (t)
            {
                case Play :
					Sortie(Jeu);
                    *etatCourant = Jeu;
					break;
            
                default:
					return;
            }
			break;
    
        case Jeu:
            switch (t)
            {
                case Quitter :
                case Perdu :
                case Gagner :
					Sortie(MenuFin);
                    *etatCourant =  MenuFin;
					break;
                default:
					return;
            }
			break;

        case MenuFin:
            switch (t)
            {
                case Rejouer :
					Sortie(Jeu);
                    *etatCourant = Jeu;
					break;
            
				case RetourMenu :
					Sortie(MenuDebut);
					*etatCourant = MenuDebut;
					break;
                default:
					return;
            }
			break;

        default :
			Sortie(MenuDebut);
            *etatCourant = MenuDebut;
			break;
    }

	requestRedraw();
}

void Sortie(Etat etatSuivant) {
    switch (etatSuivant)
    {
        case MenuDebut :
			break;
        case Jeu :
			InitJeu();
			break;
        case MenuFin :
			stopTimer();
			break;
        default :
			break;
    }
}

// TODO : 
// - Avoir le choix de quel fichier d'icone et de cartes ouvrir en paramètre du jeu
// - Vérification placement aléatoire
// - Compte-rendu
// - Suppression du code commenté inutile
// - Polish
// - d'autres icones (transparence du pack actuel)
// - mode de difficultés
// - highscores