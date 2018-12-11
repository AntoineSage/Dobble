#include <fichierVersPlateau.h>

int main(int argc, char const *argv[])
{
    Plateau p = fichierVersPlateau("data/pg22.txt");
    afficherPlateauPioche(&p);

    return 0;
}
