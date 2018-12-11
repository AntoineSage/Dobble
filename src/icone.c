#include <icone.h>
#include "math.h"

bool estDansIcone(Icone I, carte C, int x, int y){
	bool dedans=false;
	float xcentre=C.xcenter+I.distance*cos((float)(I.angle));
	float ycentre=C.ycenter+I.distance*sin((float)(I.angle));
	if (sqrt((xcentre-x)^2+(ycentre-y)^2)<I.taille*0.5){
		dedans=true;
	}
	return dedans;
}

Icone nouvelIcone() {
    Icone icone;
        
    printf("Initialisation d'un nouvel icône \n ATTENTION, RIEN N'A ETE FAIT PENDANT L'INITIALISATION DU NOUVEL ICONE\n");

    return icone;
}
