#include <fichierVersPlateau.h>

main(int argc, char const *argv[])
{
    Plateau p = fichierVersPlateau("data/pg22.txt");
    affichetPlateauPioche(&p);
}
