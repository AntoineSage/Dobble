#include <carte.h>

#define NB_MAX_CARTES_PIOCHE 100

typedef struct {
    Carte haut, bas;
    Carte pioche[NB_MAX_CARTES_PIOCHE];

    Image imageCommune;

    int Score;
    float TempsRestant;
} Plateau;