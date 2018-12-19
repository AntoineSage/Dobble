#include <Vect2.h>
#include <math.h>

Vect2 newVect2(float x, float y) {
	Vect2 vect;
	vect.x = x;
	vect.y = y;
	return vect;
}

float moduleVect2(Vect2 vect) {
    return(sqrt(moduleSquaredVect2(vect)));
}

float moduleSquaredVect2(Vect2 vect) {
    return(vect.x*vect.x + vect.y*vect.y);
}


Vect2 divideVect2(Vect2 vect, float divider) {
    // Si le divider est 0 alors on retourne le vecteur tel quel
    if(divider != 0) {
        return newVect2(vect.x / divider, vect.y  /divider);
    } else {
        return vect;
    }
}

Vect2 newVect2Zero() {
    return newVect2(0, 0);
}

Vect2 addVect2(Vect2 vect1, Vect2 vect2) {
    return newVect2(vect1.x + vect2.x, vect1.y + vect2.y);
}

// Vect2 constraintVect2(Vect2 v, float max) {
//     Vect2 vRet = newVect2(v.x, v.y);

//     if(v.x > max) vRet.x = max;
//     else if(v.x < -max) vRet.x = -max;
    
//     if(v.y > max) vRet.y = max;
//     else if(v.y < -max) vRet.y = -max;
//     return vRet;
// }

float distanceBetween(Vect2 v1, Vect2 v2) {
    return moduleVect2(newVect2(v1.x - v2.x, v1.y - v2.y));
}

float distanceSquaredBetween(Vect2 v1, Vect2 v2) {
    return moduleSquaredVect2(newVect2(v1.x - v2.x, v1.y - v2.y));
}