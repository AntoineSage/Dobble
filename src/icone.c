#include <icone.h>
#include <stdio.h>
#include <math.h>
#include <dobble-config.h>
#include <stdlib.h>

#define MAX_SPEED 5

int estDansIcone(Icone I, int xcentreCarte, int ycentreCarte, int x, int y){ // UTLISER LES FONCTIONS DU PRF
	int dedans=0;
	float xcentre=xcentreCarte+I.distance*cos((float)(I.angle));
	float ycentre=ycentreCarte+I.distance*sin((float)(I.angle));
	if (sqrt((xcentre-x)*(xcentre-x)+(ycentre-y)*(ycentre-y))<I.scale*0.5){
		dedans=1;
	}
	return dedans;
}

Icone nouvelIcone() {
    Icone icone;

    icone.image = 0; // Temp
	icone.position = newVect2Zero();
	icone.speed = newVect2Zero();
	icone.acceleration = newVect2Zero();

    printf("Initialisation d'un nouvel icône \n ATTENTION, RIEN N'A ETE FAIS PENDANT L'INITIALISATION DU NOUVEL ICONE\n");

    return icone;
}

void positionAleatoire(Icone* icone) {
	icone -> distance = rand() % CARD_RADIUS;
	printf("Distance : %f\n", icone -> distance);
}

void scaleAleatoire(Icone* icone) {
	icone -> scale = (((float)rand())/((float) RAND_MAX))/2 + 0.6;
	printf("Scale : %f\n", icone -> scale);
}

void rotationAleatoire(Icone* icone) {
	icone -> rotation = ((float)rand())/((float) RAND_MAX) * 360;
	printf("Rotation : %f\n", icone -> rotation);
}

void angleAleatoire(Icone* icone) {
	icone -> angle = ((float)rand())/((float) RAND_MAX) * 360;
	printf("Angle : %f\n", icone -> angle);
}

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
