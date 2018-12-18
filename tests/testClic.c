#include <stdio.h>
#include "plateau.h"

/* TEST A DEBUGUER SI TEMPS
int main(){
	int xclic=4;
	int yclic=5;
	int xcentreCarte;
	int ycentreCarte;
	Vect2 posClic=newVect2(xclic,yclic);

	//def icone
	Icone I1;
	I1.image=(Image)11;
	I1.distance=2.0;
	I1.angle=45.0;
	I1.scale=2.0;
	I1.rotation=0;

	Icone I2;
	I2.image=22;
	I2.distance=2.0;
	I2.angle=-45.0;
	I2.scale=2.0;
	I2.rotation=0;

	//def carte
	Carte C;
	C.nbIcones=2;
	C.icones[0]=I1;
	C.icones[1]=I2;
	C.xcenter=3.0;
	C.ycenter=4.0;

	//def plateau
	Plateau P;
	P.haut=C;
	getCenterCard(UpperCard,&xcentreCarte, &ycentreCarte);
	Vect2 posCarte=newVect2(xcentreCarte,ycentreCarte);


	if (Clic_a_l_interieur(P, posCarte, posClic)!=22){
		printf("%d\n",Clic_a_l_interieur(P, posCarte, posClic));
		printf("Il y a un problème avec Clic_a_l'interieur\n");
	}
	else {
		printf("Tout va bien\n");
	}
	return 0;
}
*/
