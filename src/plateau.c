#include <plateau.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

Image Clic_a_l_interieur(Plateau P, Vect2 centerCard, Vect2 posClic){
	
	int i;
	Image I=-1;
	Carte H=P.haut;
	for (i=0; i<H.nbIcones;i++){
		if (estDansIcone(H.icones[i],centerCard,posClic)==1){
			I=H.icones[i].image;
			break;
		}
	}
	return I;
}

Plateau nouveauPlateau() {
    Plateau plateau;
	int i;

    plateau.nbCartes = 0; // Temp

    printf("Initialisation d'un nouveau plateau \n ATTENTION, RIEN N'A ETE FAIS PENDANT L'INITIALISATION DU NOVUEAU TABLEAU\n");

	plateau.Score=0;
	plateau.TempsRestant=100;

	for (i=0;i<plateau.nbCartes;i++){
		plateau.Marques[i]=0;
	}
	plateau.nbCartesMarquees=0;

    return plateau;
}

void afficherPlateauPioche(Plateau* p) {
    int i;
    for(i = 0 ; i < p -> nbCartes; i++) {
        printf("Carte %d : ", i+1);
        
        Carte* carte = &(p -> pioche[i]);

        int j;
        for(j = 0; j < carte -> nbIcones; j++) {
            printf(" %d", (&(carte -> icones[j])) -> image);
        }

        printf("\n");
    }
}

Carte choisitCarteAleatoire(Plateau* P){
 
	if (P->nbCartesMarquees==P->nbCartes){
		int i;
		for (i=0;i<P->nbCartes;i++){
			P->Marques[i]=0;
		}
		P->nbCartesMarquees=0;
	}
	
    int indice=rand()%(P->nbCartes);    //entre 0 et nbCartes
	while (P->Marques[indice]==1){
		indice=rand()%(P->nbCartes);
	}
	P->nbCartesMarquees++;
	P->Marques[indice]=1;
	return P->pioche[indice];
}

void initCardsIconsPositions(Plateau* p) {
    int i;
    for(i = 0; i < p -> nbCartes; i++) {
        Carte* c = &(p -> pioche[i]);
		setIconsInCard(c);
    }
}

