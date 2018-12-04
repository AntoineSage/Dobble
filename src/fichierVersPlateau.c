#include <stdio.h>
#include <fichierVersPlateau.h>

Plateau fichierVersPlateau(char *nomFichier){
    printf("Chargement du fichier %s\n", nomFichier);

    FILE* f = fopen(nomFichier, "r"); // ouvre le fichier “fichier.txt” en lecture
    if (f == NULL) {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier %s\n", nomFichier);
        exit(0);
    }
}