#ifndef _CARTE_
#define _CARTE_

#include <icone.h>

#define NB_MAX_ICONES_CARTES 50

// Une carte est représentée par une liste d'icones et un nombre d'icones associés.
// On a préféré un nombre maximum de carte plutôt qu'une allocation dynamique des tableaux
// pour éviter la source non négligeable de bugs que sont les malloc et free.
typedef struct {
    Icone icones[NB_MAX_ICONES_CARTES];
    int nbIcones;
} Carte;

// Renvoie une nouvelleCarte initialisée à "0"
Carte nouvelleCarte();

// Renvoie l'image partagée entre les deux cartes. -1 si aucune image commune n'est trouvée
Image TrouverImageCommune(Carte* c1, Carte* c2);

// Pour la simulation physique qui permet la position aléatoire des icones sur la carte :

// Positionne tous les icones de la carte pour qu'ils soient valides
void setIconsInCard(Carte* carte);

// Met à jour la position, vitesse, accélération des icones sur la carte 
void updateIcones(Carte* carte);

// Calcule l'accélération de l'icone en fonction des autres icones et de sa position sur la carte 
void computeAcceleration(Icone* icone, Carte* carte, int index);

// Renvoie 1 si la carte est considérée comme valide (aucun icone ne ce touches et aucun icone ne dépasse des bords), 0 sinon
int carteIsValid(Carte* carte);


#endif /* _CARTE_ */
