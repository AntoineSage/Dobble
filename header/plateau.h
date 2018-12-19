#ifndef _PLATEAU_
#define _PLATEAU_

#include <carte.h>

#define NB_MAX_CARTES_PIOCHE 100

// Un plateau de jeu est représenté par 
// - Deux carte haut et bas qui ont une imageCommune
// - Une pioche dans laquelle il y a nbCartes Carte
// - Un score et un temps restant
typedef struct {
    Carte haut, bas;
    Image imageCommune;

    int Score;
    int TempsRestant;

    Carte pioche[NB_MAX_CARTES_PIOCHE];
    int nbCartes;
	//Pour le choix aleatoire sans remise de cartes dans la pioche 
	int nbCartesMarquees;
	int Marques[NB_MAX_CARTES_PIOCHE];
    int historique[3];
} Plateau;

// Renvoie un nouveau plateau initialisé à "zéro"
Plateau nouveauPlateau();

//void afficherPlateauPioche(Plateau* p);

// Initialise chaque carte de la pioche du plateau pour qu'elles soit valide (que les icones soit correctement placés)
void initCardsIconsPositions(Plateau* p);

// Renvoie l'image sur laquelle le joueur a cliqué (-1 si il n'a cliqué sur aucune image) 
// posClic est la position du clic du joueur
// centerCard est le centre de la carte, nécessaire car la position des icones sont exprimé en fonction du centre de la carte et non de la fenêtre
Image Clic_a_l_interieur(Plateau P, Vect2 centerCard, Vect2 posClic);

// Renvoie une carte aléatoire sans remise :
// On pioche aléatoirement jusqu'à ce que toutes les cartes ai été piochés.
// On remet la pioche à zéro une fois que tout a été pioché
Carte choisitCarteAleatoire(Plateau* P);

int lose(Plateau* plateau);

#endif /*_PLATEAU_*/
