#ifndef _ICONE_
#define _ICONE_

#include <Vect2.h>

typedef int Image;

// Un icone est représenté par sa position, sa taille (scale), sa rotation, son image
// Mais aussi une vitesse (speed) et une acceleration
//
// Idéalement il faut faudrait mettre ces deux derniers Vecteur dans une autre structure
// seulement utilisé à l'initialisation car ils ne servent qu'au lancement du programme pour générer les cartes aléatoirement
typedef struct {
    // Polaire
    // float distance;
    // float angle;

    // Cartésien
    Vect2 position;
    Vect2 speed;
    Vect2 acceleration;

    float scale;
    float rotation;
    
    Image image;
} Icone;


Icone nouvelIcone();

// Retourne 1 si posClic est à l'intérieur de l'icone I, 0 sinon
int estDansIcone(Icone I, Vect2 centreCarte, Vect2 posClic);

// Donne des valeurs aléatoire (non aberrente) au vecteur position de l'icone donnée
void positionAleatoire(Icone* icone);

// Donne un scale aléatoire mais cohérent par rapport au nombre d'icones sur la carte (uniquement pour 3 à 10 icones par carte).
void scaleAleatoire(Icone* icone, int nbIcones);

// Donne une rotation aléatoire entre 0 et 360
void rotationAleatoire(Icone* icone);

#endif /* _ICONE_ */
