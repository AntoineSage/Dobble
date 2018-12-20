#include <carte.h>
#include <stdio.h>
#include <dobble-config.h>
#include <math.h>
#include <stdlib.h>

Carte nouvelleCarte()
{
	Carte carte;
	carte.nbIcones = 0;
	return carte;
}

void updateIcones(Carte* carte) {
	int i;

	for (i = 0; i < carte -> nbIcones; i++) // Pour chaque icone de la carte
	{
		Icone* ic = (&(carte -> icones[i]));

		// Mise à jour de l'accélération
		computeAcceleration(ic, carte, i);

		// Mise à jour de la position avec la vitesse
		ic -> position = addVect2(ic -> position, ic -> speed);

		// Mise à jour de la vitesse avec l'accélération
		ic -> speed = addVect2(ic -> speed, ic -> acceleration);
	}
}

void computeAcceleration(Icone* icone, Carte* carte, int index) {
	const float FORCE_ATTRATION_CENTRE = 0.2;
	const float DISTANCE_REPULSION_CENTRE = 30;

	const float FORCE_REPULSION_CARTE = 100;
	const float DISTANCE_REPULSION_CARTE = 4;

	const float FORCE_FROTTEMENT = 1.2;

	// Force d'attraction vers le centre
	Vect2 acc = newVect2(- (&(icone -> position)) -> x, - (&(icone -> position)) -> y); // Attraction vers le centre
	float modAcc = moduleVect2(acc);
	if(modAcc < DISTANCE_REPULSION_CENTRE) { // Répulseur quand on est trop proche du centre
		modAcc = -modAcc;
	}

	if(modAcc != 0) {
		acc = divideVect2(acc, modAcc / FORCE_ATTRATION_CENTRE); 
	}

	// Force de Collision entre deux icones
	int i;
	Vect2 accTemp = newVect2Zero();
	for(i = 0; i < carte -> nbIcones; i++) {
		if(i != index) {
			// Si deux icônes sont trop proches les uns des autres
			if(distanceSquaredBetween(icone -> position, carte -> icones[i].position) <= pow((icone -> scale + carte -> icones[i].scale)*(ICON_SIZE / 2) + DISTANCE_REPULSION_CARTE, 2)) {
				// Ajouter une force de répulsion
				accTemp = addVect2(accTemp, newVect2(icone -> position.x - carte -> icones[i].position.x, icone -> position.y - carte -> icones[i].position.y));
			}
		}
	}

	if(accTemp.x != 0 && accTemp.y != 0){
		accTemp = divideVect2(accTemp, moduleVect2(accTemp) / FORCE_REPULSION_CARTE);
	}

	// Force de frottement qui ralentit chaque icone opposé à la vitesse
	Vect2 accFrot = newVect2(-icone -> speed.x, -icone -> speed.y);
	accFrot = divideVect2(accFrot, FORCE_FROTTEMENT);
	
	// Somme des forces
	acc = addVect2(acc, accTemp);
	acc = divideVect2(acc, moduleVect2(acc));
	acc = addVect2(acc, accFrot);

	icone -> acceleration = acc;
}

int carteIsValid(Carte* carte) {
	int i;
	for(i = 0; i < carte -> nbIcones; i++) {
		Icone ic = carte -> icones[i];
		// Si la carte est hors des bords alors elle n'est pas valide
		if(moduleSquaredVect2(ic.position) > pow((CARD_RADIUS - ((ic.scale * ICON_SIZE) / 2)), 2)) return 0;

		int j;
		for(j = 0; j < carte -> nbIcones; j++) {
			if(j != i) {
				Icone ic2 = carte -> icones[j];
				// Si deux cartes ce superposent alors elle n'est pas valide
				if(distanceSquaredBetween(ic.position, ic2.position) < pow(((ic.scale + ic2.scale) * ICON_SIZE / 2), 2)) return 0;
			}
		} 
	}

	// Si aucune erreur a été détectée avant c'est que la carte est valide
	return 1;
}

void carteAleatoire(Carte* carte) {			
	float offset = ((float)rand())/((float) RAND_MAX) * 2 * M_PI;
		
	int i;
	for(i = 0; i < carte -> nbIcones; i++) {
		Icone* ic = &(carte -> icones[i]);
		scaleAleatoire(ic, carte -> nbIcones);
		rotationAleatoire(ic);
		positionAleatoire(ic, carte -> nbIcones, i, offset);
	}
}

void setIconsInCard(Carte* carte) {
	int compteur = 0;	

	// Initialisation aléatoire de chaque icone
	carteAleatoire(carte);

	// On les fait évoluer un minimum de 100 fois et tant qu'ils ne forment pas une carte valide
	while(!(carteIsValid(carte))) {
		/*
		Si on a fait autant d'évolutions sans que la carte ne soit valide, 
		c'est sûrement que la carte est bloquée dans un état où elle ne peut pas être valide.
		Donc on recommence depuis le début pour cette carte.
		C'est n'est pas la solution idéale, mais cela arrive rarement et permet de résoudre le problème.
		*/
		if(compteur > 1000) {
			compteur = 0;
			carteAleatoire(carte);
		}


		updateIcones(carte);

		compteur++;
	}
}

Image TrouverImageCommune(Carte* c1, Carte* c2) {
	int i;
	for(i = 0; i < c1 -> nbIcones; i++) { // Pour chaque icone de c1
		Image img = c1 -> icones[i].image;
		int j;
		for(j = 0; j < c2 -> nbIcones; j++) { 
			if(img == c2 -> icones[j].image) return img; // Si on trouve cet icone dans c2 alors c'est l'icone en commun
		}
	}

	fprintf(stderr, "Attention : aucune image commune aux deux cartes n'a été trouvé.\n");
	return -1;
}
