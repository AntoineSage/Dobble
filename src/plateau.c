#include <plateau.h>
#include <stdio.h>

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

    plateau.nbCartes = 0; // Temp

    printf("Initialisation d'un nouveau plateau \n ATTENTION, RIEN N'A ETE FAIS PENDANT L'INITIALISATION DU NOVUEAU TABLEAU\n");

	plateau.Score=0;
	plateau.TempsRestant=100;

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

