#ifndef _ICONE_
#define _ICONE_

#include <Vect2.h>

typedef int Image;

typedef struct {
    // Polaire
    float distance;
    float angle;

    // Cartésien
    Vect2 position;
    Vect2 speed;
    Vect2 acceleration;

    float scale;
    float rotation;
    
    Image image;
} Icone;


Icone nouvelIcone();

int estDansIcone(Icone I, int xcentreCarte, int ycentreCarte, int x, int y);

void positionAleatoire(Icone* icone);
void scaleAleatoire(Icone* icone);
void rotationAleatoire(Icone* icone);
void angleAleatoire(Icone* icone);

void fromComplexToXY(Icone* icone);
void fromXYtoComplex(Icone* icone);

void updateIcone(Icone* icone);

#endif /* _ICONE_ */
