#include <icone.h>
#include "math.h"

bool estDansIcone(Icone I, int x, int y){
	bool dedans=false;
	float xcentre=I.distance*cos((float)(I.angle));
	float ycentre=I.distance*sin((float)(I.angle));
	if (sqrt((xcentre-x)^2+(ycentre-y)^2)<I.taille*0.5){
		dedans=true;
	}
	return dedans;
}
