#include <carte.h>
#include <stdio.h>
#include <dobble-config.h>

Carte nouvelleCarte()
{
	Carte carte;
	carte.nbIcones = 0; // temporaire

	printf("Initialisation d'une nouvelle carte \n ATTENTION, RIEN N'A ETE FAIS PENDANT L'INITIALISATION DE LA NOUVELLE CARTE\n");

	return carte;
}

void positionAleatoireIcones(Carte *carte)
{
	int i;
	for (i = 0; i < carte->nbIcones; i++)
	{
		positionAleatoire(&(carte->icones[i]));
		scaleAleatoire(&(carte->icones[i]));
		rotationAleatoire(&(carte->icones[i]));
		angleAleatoire(&(carte->icones[i]));
	}
}

void updateIcones(Carte* carte) {
	int i;
	for (i = 0; i < carte -> nbIcones; i++)
	{
		Icone* ic = (&(carte -> icones[i]));
		computeAcceleration(ic, carte, i);
	}

	for(i = 0; i < carte -> nbIcones; i++) {
		Icone* ic = (&(carte -> icones[i]));
		ic -> position = addVect2(ic -> position, ic -> speed);
		ic -> speed = constraintVect2(addVect2(ic -> speed, ic -> acceleration), 2);
	}
	// update position
	// update speed
	// constraint speed
}

void computeAcceleration(Icone* icone, Carte* carte, int index) {
	Vect2 acc = newVect2(- (&(icone -> position)) -> x, - (&(icone -> position)) -> y); // Attraction vers le centre
	float modAcc = 50 * moduleVect2(acc); //40
	if(modAcc < 50) { // Répulseur quand on est trop proche.
		modAcc = -modAcc;
	}

	acc = divideVect2(acc, modAcc); // module 2

	int i;
	Vect2 accTemp = newVect2Zero();
	for(i = 0; i < carte -> nbIcones; i++) {
		if(i != index) {
			if(distanceBetween(icone -> position, carte -> icones[i].position) <= (icone -> scale + carte -> icones[i].scale)*(ICON_SIZE / 2)) {
				accTemp = addVect2(accTemp, newVect2(icone -> position.x - carte -> icones[i].position.x, icone -> position.y - carte -> icones[i].position.y));
			}
		}
	}
	if(accTemp.x != 0 && accTemp.y != 0){
	accTemp = divideVect2(accTemp, 1 * moduleVect2(accTemp));
	}
	acc = addVect2(acc, accTemp);
	acc = divideVect2(acc, moduleVect2(acc));

	icone -> acceleration = acc;
}
