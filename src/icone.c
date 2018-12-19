#include <icone.h>
#include <stdio.h>
#include <math.h>
#include <dobble-config.h>
#include <stdlib.h>

#define MAX_SPEED 5

int estDansIcone(Icone I, Vect2 centreCarte, Vect2 posClic){
	int dedans=0;

	// Si la distance entre posClic et centreCarte est inférieur au rayon de la carte, c'est qu'on a cliqué dedans
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

void positionAleatoire(Icone* icone) {
	// Fonction voué à changer dans le futur
	float distance = rand() % CARD_RADIUS;
	float angle = ((float)rand())/((float) RAND_MAX) * 2 * M_PI;

	icone -> position = newVect2(distance * cos(angle),\
								distance * sin(angle));
}

void scaleAleatoire(Icone* icone) {
	// Une valeur aléatoire entre 0.6 et 1.1
	icone -> scale = (((float)rand())/((float) RAND_MAX))/2 + 0.5;
}

void rotationAleatoire(Icone* icone) {
	// Une rotation aléatoire entre 0 et 360
	icone -> rotation = ((float)rand())/((float) RAND_MAX) * 360;
}

/*
void fromComplexToXY(Icone* icone) {
	// printf("Switched from complex to (x, y) mode.\n");
	icone -> position = newVect2(	icone -> distance * cos(icone -> angle * 2 * M_PI / 360),\
									icone -> distance * sin(icone -> angle * 2 * M_PI / 360));
}

void fromXYtoComplex(Icone* icone) {
	// printf("Switched from (x, y) to complex mode.\n");

	icone -> distance = moduleVect2(icone -> position);
	icone -> angle = (acos((&(icone -> position)) -> x / icone -> distance)) * 360 / (2 * M_PI);

	if ((&(icone -> position)) -> y < 0) {
		icone -> angle = 360 - icone -> angle;
	}
}

void updateIcone(Icone* icone) {
	icone -> position = addVect2(icone -> position, icone -> speed);
	icone -> speed = constraintVect2(addVect2(icone -> speed, icone -> acceleration), MAX_SPEED);
}
*/