#include <automate.h>

Etat etatSuivant(Etat etatCourant, Transition t) {
    switch (etatCourant)
    {
        case MenuDebut:
            switch (t)
            {
                case Play :
                    return Jeu;
            
                default:
                    return MenuDebut;
            }
    
        case Jeu:
            switch (t)
            {
                case Quitter :
                case Perdu :
                case Gagner :
                    return MenuFin;
            
                default:
                    return MenuDebut;
            }

        case MenuFin:
            switch (t)
            {
                case Rejouer :
                    return Jeu;
            
                default:
                    return MenuDebut;
            }

        default :
            return MenuDebut;
    }
}
