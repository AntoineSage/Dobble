#include <carte.h>
#include <stdio.h>
#include <dobble-config.h>
#include <math.h>

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
		ic -> position = addVect2(ic -> position, ic -> speed);
		ic -> speed = addVect2(ic -> speed, ic -> acceleration);
	}

	// for(i = 0; i < carte -> nbIcones; i++) {
	// 	Icone* ic = (&(carte -> icones[i]));
	// }
}

void computeAcceleration(Icone* icone, Carte* carte, int index) {
	// Attraction vers le centre
	Vect2 acc = newVect2(- (&(icone -> position)) -> x, - (&(icone -> position)) -> y); // Attraction vers le centre
	float modAcc = 20 * moduleVect2(acc); //40
	if(modAcc < 30) { // Répulseur quand on est trop proche.
		modAcc = -modAcc;
	}

	acc = divideVect2(acc, modAcc); // module 2

	// Collision
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
		accTemp = divideVect2(accTemp, 0.01 * moduleVect2(accTemp));
	}

	// Frottement
	Vect2 accFrot = newVect2(-icone -> speed.x, -icone -> speed.y);
	accFrot = divideVect2(accFrot, 1.2);
	
	acc = addVect2(acc, accTemp);
	acc = divideVect2(acc, moduleVect2(acc));
	acc = addVect2(acc, accFrot);

	icone -> acceleration = acc;
}

int carteIsValid(Carte* carte) {
	int i;
	for(i = 0; i < carte -> nbIcones; i++) {
		Icone ic = carte -> icones[i];
		if(moduleSquaredVect2(ic.position) > pow((CARD_RADIUS - (ic.scale * ICON_SIZE) / 2), 2)) return 0;

		int j;
		for(j = 0; j < carte -> nbIcones; j++) {
			if(j != i) {
				Icone ic2 = carte -> icones[j];
				if(distanceSquaredBetween(ic.position, ic2.position) < pow(((ic.scale + ic2.scale) * ICON_SIZE / 2), 2)) return 0;
			}
		} 
	}

	return 1;
}

void setIconsInCard(Carte* carte) {
	int compteur = 0;	
	
	int i;
	for(i = 0; i < carte -> nbIcones; i++) {
		Icone* ic = &(carte -> icones[i]);
		scaleAleatoire(ic);
		rotationAleatoire(ic);
		positionAleatoire(ic);
	}

	while(!(carteIsValid(carte) && compteur > 100)) {
		if(compteur > 10000) { // Solution temporaire
			compteur = 0;
			positionAleatoireIcones(carte);
		}

		
		updateIcones(carte);

		compteur++;
	}
	printf("%d\n", compteur);
}