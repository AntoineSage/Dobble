#include <plateau.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

Image Clic_a_l_interieur(Plateau P, Vect2 centerCard, Vect2 posClic){
	int i;
	Image I=-1;
	Carte H=P.haut;

	// Pour chaque icone
	for (i=0; i<H.nbIcones;i++){

		// Si l'on a cliqué sur l'icone
		if (estDansIcone(H.icones[i],centerCard,posClic)==1){
			// On le retourne
			I=H.icones[i].image;
			break;
		}
	}

	// Si I n'a pas été changé on renvoie -1 (indication qu'aucun icone n'a été cliqué)
	return I;
}

Plateau nouveauPlateau() {
    Plateau plateau;

    plateau.nbCartes = 0; 
	plateau.Score=0;
	plateau.TempsRestant=30;

	int i;
	for (i=0;i<plateau.nbCartes;i++){
		plateau.Marques[i]=0;
	}
	plateau.nbCartesMarquees=0;

    return plateau;
}


Carte choisitCarteAleatoire(Plateau* P){
	// Si l'on a pioché toutes les cartes
	if (P->nbCartesMarquees==P->nbCartes){
		int i;
		// On remet la pioche à zéro
		for (i=0;i<P->nbCartes;i++){
			P->Marques[i]=0;
		}

		for(i = 0; i < 3; i++) {
			P->Marques[P->historique[i]] = 1;
		}
		P->nbCartesMarquees=3;
	}
	
    int indice=rand()%(P->nbCartes);    //entre 0 et nbCartes

	// On cherche aléatoirement une carte qui n'a pas été déjà pioché
	while (P->Marques[indice]==1){
		indice=rand()%(P->nbCartes);
	}
	
	// On marque cette carte pour ne pas la piocher de nouveau juste après
	P->nbCartesMarquees++;
	P->Marques[indice]=1;

	// L'historique contient les indices des 3 dernieres cartes du plateau. Utile après une remise à 0
	// des cartes marquees (càd lorsque toutes les cartes ont été vues) pour éviter le risque d'avoir deux cartes
	// identiques à la suite: la premiere avant la remise à 0, la deuxieme après.
	// On suppose qu'il ne peut pas y avoir moins de 3 cartes sur le plateau
	P->historique[0] = P->historique[1];
	P->historique[1] = P->historique[2];
	P->historique[2] = indice;

	return P->pioche[indice];
}

void initCardsIconsPositions(Plateau* p) {
    int i;
	// Pour chaque carte de la pioche
    for(i = 0; i < p -> nbCartes; i++) {
        Carte* c = &(p -> pioche[i]);
		// Initialisation de la position des icones de cette carte pour que la carte soit valide
		setIconsInCard(c);
    }
}

int lose(Plateau* plateau) {
	// La partie est considéré comme terminée si il ne nous reste plus de temps
	return (plateau -> TempsRestant) <= 0;
}
