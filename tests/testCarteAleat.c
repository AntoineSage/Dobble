#include <plateau.h>
#include <dobble-config.h>

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main(){
	Plateau P=nouveauPlateau();
	P.nbCartes=3;
	Carte C1=nouvelleCarte();
	C1.nbIcones=1;
	Carte C2=nouvelleCarte();
	C2.nbIcones=2;
	Carte C3=nouvelleCarte();
	C3.nbIcones=3;
	P.pioche[0]=C1;
	P.pioche[1]=C2;
	P.pioche[2]=C3;
	srand(time(NULL));
	Carte C=choisitCarteAleatoire(&P);
	printf("Carte %d \n",C.nbIcones);
	printf("nb cartes marquees %d\n",P.nbCartesMarquees);
	printf("[%d] [%d] [%d]\n",P.Marques[0],P.Marques[1],P.Marques[2]);
	int i;
	for(i=0;i<20;i++){
		C=choisitCarteAleatoire(&P);
		printf("Carte %d \n",C.nbIcones);
		printf("nb cartes marquees %d\n",P.nbCartesMarquees);
		printf("[%d] [%d] [%d]\n",P.Marques[0],P.Marques[1],P.Marques[2]);
	}
	return 0;
}
