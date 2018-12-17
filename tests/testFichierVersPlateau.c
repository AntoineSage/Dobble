#include <fichierVersPlateau.h>
#include "dobble-config.h"

int main(int argc, char const *argv[])
{
    Plateau p = fichierVersPlateau(DATA_DIRECTORY "/pg22.txt");
    afficherPlateauPioche(&p);

    return 0;
}
