// Un Vect2 est représenté simplement par une valeur x et une valeur y
typedef struct {
    float x;
    float y;
} Vect2;

// Renvoie un nouveau Vect2 (x, y)
Vect2 newVect2(float x, float y);

// Renvoie un nouveau Vect2 (0, 0)
Vect2 newVect2Zero();

// Renvoie le module de vect
float moduleVect2(Vect2 vect);

// Renvoie vect/divider si divider != 0, vect sinon
Vect2 divideVect2(Vect2 vect, float divider);

// Renvoie vect1 + vect2
Vect2 addVect2(Vect2 vect1, Vect2 vect2);

// Vect2 constraintVect2(Vect2 v, float max);

// Renvoie la distance entre v1 et v2 (le module aurait pu suffire, c'est juste pour le côté pratique de l'utilisation de cette fonction)
float distanceBetween(Vect2 v1, Vect2 v2);

// Renvoie le module au carré (permet d'éviter le calcul d'une racine)
float moduleSquaredVect2(Vect2 vect);

// Renvoie la distance au carré (permet d'éviter le calcul d'une racine)
float distanceSquaredBetween(Vect2 v1, Vect2 v2);
