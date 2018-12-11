#include <plateau.h>

Plateau nouveauPlateau() {
    Plateau plateau;
        
    printf("Initialisation d'un nouveau plateau \n ATTENTION, RIEN N'A ETE FAIS PENDANT L'INITIALISATION DU NOVUEAU TABLEAU\n");

    return plateau;
}

void affichetPlateauPioche(Plateau* p) {
    int i;
    for(i = 0 ; i < p -> nbCartes; i++) {
        printf("Carte %d : ", i+1);
        
        Carte* carte = &(p -> pioche[i]);

        int j;
        for(j = 0; j < carte -> nbIcones; j++) {
            printf(" %d", &(carte -> icones[j]) -> image);
        }

        printf("\n");
    }
}