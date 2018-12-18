#ifndef _PLATEAU_
#define _PLATEAU_

#include <carte.h>

#define NB_MAX_CARTES_PIOCHE 100

typedef struct {
    Carte haut, bas;
    Carte pioche[NB_MAX_CARTES_PIOCHE];
    int nbCartes;

    Image imageCommune;

    int Score;
    float TempsRestant;
} Plateau;

Plateau nouveauPlateau();
void afficherPlateauPioche(Plateau* p);
void initCardsIconsPositions(Plateau* p);

Image Clic_a_l_interieur(Plateau P, Vect2 centerCard, Vect2 posClic);

#endif /*_PLATEAU_*/
