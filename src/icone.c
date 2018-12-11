#include <icone.h>
#include <stdio.h>
#include <math.h>

int estDansIcone(Icone I, int xcentreCarte, int ycentreCarte, int x, int y){
	int dedans=0;
	float xcentre=xcentreCarte+I.distance*cos((float)(I.angle));
	float ycentre=ycentreCarte+I.distance*sin((float)(I.angle));
	if (sqrt((xcentre-x)*(xcentre-x)+(ycentre-y)*(ycentre-y))<I.taille*0.5){
		dedans=1;
	}
	return dedans;
}

Icone nouvelIcone() {
    Icone icone;

    icone.image = 0; // Temp

    printf("Initialisation d'un nouvel icône \n ATTENTION, RIEN N'A ETE FAIS PENDANT L'INITIALISATION DU NOUVEL ICONE\n");

    return icone;
}
