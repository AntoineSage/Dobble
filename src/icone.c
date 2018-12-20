#include <icone.h>
#include <stdio.h>
#include <math.h>
#include <dobble-config.h>
#include <stdlib.h>

#define MAX_SPEED 5

int estDansIcone(Icone I, Vect2 centreCarte, Vect2 posClic){
	int dedans=0;

	// Si la distance entre posClic et centreCarte est inférieure au rayon de la carte, c'est qu'on a cliqué dedans
	if (distanceSquaredBetween(addVect2(I.position, centreCarte), posClic) <  pow(I.scale * ICON_SIZE / 2, 2)){
		dedans=1;
	}
	return dedans;
}

Icone nouvelIcone() {
    Icone icone;

    icone.image = 0;
	icone.position = newVect2Zero();
	icone.speed = newVect2Zero();
	icone.acceleration = newVect2Zero();

    return icone;
}

void positionAleatoire(Icone* icone, int nbIcones, int i, int offset) {
	// Calcul en complexe car plus facile pour répartir équitablement autour du cercle
	float distance = rand() % CARD_RADIUS;
	float angle = 2 * M_PI * i / nbIcones; // Réparti équitablement autour du cercle

	// Conversion en cartésien
	icone -> position = newVect2(distance * cos(angle + offset),\
									distance * sin(angle + offset));
}

void scaleAleatoire(Icone* icone, int nbIcones) {
	// Un scale aléatoire qui varie en fonction du nombre d'icones :
	// Entre 0.5 et 1 pour 10 icones
	// Entre 1.2 et 1.7 pour 3 icones
	icone -> scale = (((float)rand())/((float) RAND_MAX))/2 + (0.5+(10-nbIcones)*0.1);

}

void rotationAleatoire(Icone* icone) {
	// Une rotation aléatoire entre 0 et 360
	icone -> rotation = ((float)rand())/((float) RAND_MAX) * 360;
}
