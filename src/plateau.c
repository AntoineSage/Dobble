#include "plateau.h"

Image Clic_a_l_interieur(Plateau P, int xclic, int yclic){
	
	int i;
	Image I=-1;
	Carte H=P.haut;
	for (i=0; i<H.nbIcones;i++){
		if (estDansIcone(H.icones[i],xclic,yclic){
			I=H.icones[i].image;
		}
	}
	return I;
}
