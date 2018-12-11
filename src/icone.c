#include <icone.h>
#include <stdio.h>

Icone nouvelIcone() {
    Icone icone;
    icone.image = 0; // Temp

    printf("Initialisation d'un nouvel icône \n ATTENTION, RIEN N'A ETE FAIS PENDANT L'INITIALISATION DU NOUVEL ICONE\n");

    return icone;
}