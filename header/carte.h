#include <icone.h>

#define NB_MAX_ICONES_CARTES 50

typedef struct {
    Icone icones[NB_MAX_ICONES_CARTES];
    int nbIcones;
	float xcenter,ycenter;
} Carte;
