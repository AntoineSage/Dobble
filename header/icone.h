#ifndef _ICONE_
#define _ICONE_

typedef int Image;

typedef struct {
    float distance;
    float angle;
    float taille;
    float rotation;
    
    Image image;
} Icone;


Icone nouvelIcone();

bool estDansIcone(Icone I, carte C, int x, int y);

#endif /* _ICONE_ */
