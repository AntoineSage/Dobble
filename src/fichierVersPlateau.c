#include <stdio.h>
#include <stdlib.h>
#include <fichierVersPlateau.h>

FILE* ouvertureFichier(char *nomFichier, char *Mode);

Plateau fichierVersPlateau(char *nomFichier){

    FILE* f = ouvertureFichier(nomFichier, "r");

    int nbCartes, nbIcones;

    // Lecture de l'en tête
    int nbRead = fscanf(f, "%d %d", &nbCartes, &nbIcones);

    if (nbRead != 2) {
        fprintf(stderr, "Erreur de lecture dans le fichier %s à la ligne 0.\n", nomFichier);
    }

    // Init plateau
    Plateau plateau = nouveauPlateau();
    plateau.nbCartes = nbCartes;

    int i,j;
    for(i = 0; i < nbCartes; i++) {

        // Init Carte
        Carte carte = nouvelleCarte();
        carte.nbIcones = nbIcones;

        for(j = 0; j < nbIcones; j++) {
            // Init Icone
            Icone icone = nouvelIcone();

            Image image;
            nbRead = fscanf(f, "%d", &image);
            if (nbRead != 1) {
                fprintf(stderr, "Erreur de lecture dans le fichier %s à la ligne %d et au nombre %d.\n", nomFichier, i+1, j+1);
            }

            // Ajout de l'icone dans la carte
            icone.image = image;
            carte.icones[j] = icone;
        }

        // Ajoute de la carte dans le plateau
        plateau.pioche[i] = carte;
    }

    fclose(f);
    printf("Fermeture du fichier %s réussi \n", nomFichier);

    return plateau;
}

FILE* ouvertureFichier(char *nomFichier, char *Mode) {
    printf("Chargement du fichier %s\n", nomFichier);

    FILE* f = fopen(nomFichier, Mode);
    if (f == NULL) {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier %s\n", nomFichier);
        exit(0);
    }

    printf("Ouverture du fichier %s réussi \n", nomFichier);
    return f;
}