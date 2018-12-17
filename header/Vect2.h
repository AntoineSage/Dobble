

typedef struct {
    float x;
    float y;
} Vect2;

Vect2 newVect2(float x, float y);
Vect2 newVect2Zero();

float moduleVect2(Vect2 vect);
Vect2 divideVect2(Vect2 vect, float divider);
Vect2 addVect2(Vect2 vect1, Vect2 vect2);
Vect2 constraintVect2(Vect2 v, float max);
float distanceBetween(Vect2 v1, Vect2 v2);
