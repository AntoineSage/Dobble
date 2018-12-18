#ifndef _CARTE_
#define _CARTE_

#include <icone.h>

#define NB_MAX_ICONES_CARTES 50

typedef struct {
    Icone icones[NB_MAX_ICONES_CARTES];
    int nbIcones;
} Carte;

Carte nouvelleCarte();

void positionAleatoireIcones(Carte* carte);
void updateIcones(Carte* carte);
void computeAcceleration(Icone* icone, Carte* carte, int index);
int carteIsValid(Carte* carte);
void setIconsInCard(Carte* carte);

#endif /* _CARTE_ */
