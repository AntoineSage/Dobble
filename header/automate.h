
typedef enum {MenuDebut, Jeu, MenuFin} Etat;

typedef enum {Play, Quitter, Perdu, Gagner, Rejouer, RetourMenu} Transition;

Etat etatSuivant(Etat etatCourant, Transition t);