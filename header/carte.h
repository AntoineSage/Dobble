#ifndef _CARTE_
#define _CARTE_

#include <icone.h>

#define NB_MAX_ICONES_CARTES 50

typedef struct {
    Icone icones[NB_MAX_ICONES_CARTES];
    int nbIcones;
	float xcenter,ycenter;
} Carte;

Carte nouvelleCarte();

#endif /* _CARTE_ */