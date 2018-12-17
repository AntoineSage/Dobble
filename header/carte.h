#ifndef _CARTE_
#define _CARTE_

#include <icone.h>

#define NB_MAX_ICONES_CARTES 50

typedef struct {
    Icone icones[NB_MAX_ICONES_CARTES];
    int nbIcones;
	float xcenter,ycenter; // UTILISER LES FONCTIONS DU PROF GET_CARD_CENTER
} Carte;

Carte nouvelleCarte();

void positionAleatoireIcones(Carte* carte);
void updateIcones(Carte* carte);
void computeAcceleration(Icone* icone, Carte* carte, int index);

#endif /* _CARTE_ */
