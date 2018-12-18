#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>

#include "dobble-config.h"
#include "dobble.h"
#include "graphics.h"
#include "time.h"
#include "plateau.h"
#include <fichierVersPlateau.h>

/// Etat du compte à rebous (lancé/non lancé)
static bool timerRunning = false;
static Plateau PlateauCourant;


void onMouseMove(int x, int y)
{
	printf("dobble: Position de la souris: (%3d %3d)\r", x, y);
	fflush(stdout);
}


void onMouseClick()
{
	printf("\ndobble: Clic de la souris.\n");

	if (timerRunning)
	{
		/*printf("\ndobble: Arrêt du compte à rebours.\n");
		stopTimer();
		timerRunning = false;*/
		int xmouse, ymouse;
		int xcentercard, ycentercard;

		getCardCenter(UpperCard,&xcentercard,&ycentercard);
		Vect2 centerCard = newVect2(xcentercard,ycentercard);

		SDL_GetMouseState(&xmouse, &ymouse);
		Vect2 posmouse=newVect2(xmouse,ymouse);
		if (PlateauCourant.imageCommune == Clic_a_l_interieur(PlateauCourant, centerCard, posmouse)){
			PlateauCourant.Score++;
			PlateauCourant.TempsRestant=PlateauCourant.TempsRestant+3;	
		}
		else{
			PlateauCourant.TempsRestant=PlateauCourant.TempsRestant-3;		
		}

	}
	else
	{
		printf("\ndobble: Démarrage du compte à rebours.\n");
		startTimer();
		timerRunning = true;
	}
}

void onTimerTick()
{
	printf("\ndobble: Tic du compte à rebours\n");
	PlateauCourant.TempsRestant=PlateauCourant.TempsRestant-1;
}


void renderSceneTemp()
{
	char title[100];

	// Efface le contenu de la fenêtre
	clearWindow();
	// Crée le titre qui sera affiché. Utile pour afficher le score.
	sprintf(title, "RICM3-Dobble    Score %d", 100);
	drawText(title, WIN_WIDTH / 2, 0, Center, Top);

	CardPosition currentCard = UpperCard;
	int cx, cy;

	// Dessin du fond de carte de la carte supérieure
	drawCardShape(currentCard, 5, 252, 252, 252, 155, 119, 170);
    int i;
    for(i = 0; i < PlateauCourant.haut.nbIcones; i++) {
        Icone ic = PlateauCourant.haut.icones[i];
        drawIconCartesien(currentCard, ic.image, ic.position.x, ic.position.y, ic.rotation, ic.scale, &cx, &cy);
    }

	// Dessin de la carte inférieure
	currentCard = LowerCard;

	// Dessin du fond de carte
	drawCardShape(currentCard, 5, 252, 252, 252, 155, 119, 170);

	// Affichage des icônes de la carte du bas (régulièrement en cercle)


	// Met au premier plan le résultat des opérations de dessin
	showWindow();
}

void renderScene()
{
	char title[100];

	// Efface le contenu de la fenêtre
	clearWindow();
	// Crée le titre qui sera affiché. Utile pour afficher le score.
	sprintf(title, "RICM3 - Dobble");
	drawText(title, WIN_WIDTH / 2, 10, Center, Top);

    drawText("Jouer", WIN_WIDTH / 2, WIN_HEIGHT / 2, Center, Middle);
    drawCircle(WIN_WIDTH / 2, WIN_HEIGHT / 2, 50, 0, 100, 0, 100);
	// Met au premier plan le résultat des opérations de dessin
	showWindow();
}

int main(int argc, char **argv)
{
	srand(time(NULL));

	if (!initializeGraphics())
	{
		printf("dobble: Echec de l'initialisation de la librairie graphique.\n");
		return 1;
	}

	if (loadIconMatrix(DATA_DIRECTORY "/Matrice8x10_Icones90x90.png") != 1)
	{
		printf("dobble: Echec du chargement des icônes.\n");
		return -1;
	}
	
    // PlateauCourant = fichierVersPlateau(DATA_DIRECTORY "/pg28.txt");
	// initCardsIconsPositions(&PlateauCourant);
    // PlateauCourant.haut = PlateauCourant.pioche[0];

	mainLoop();

	freeGraphics();


	return 0;
}
