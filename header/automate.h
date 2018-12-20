// Les 3 états de jeu possible
typedef enum {MenuDebut, Jeu, MenuFin} Etat;

// Les transitions possible
typedef enum {Jouer, FinJeu, Rejouer, RetourMenu, Rien} Transition;

void etatSuivant(Etat* etatCourant, Transition t);
void Sortie(Etat etatSuivant);
