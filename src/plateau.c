typedef struct {
    Carte haut, bas;
    Carte pioche[TAILLE_MAX];

    Image imageCommune;

    int Score;
    float TempsRestant;
} Plateau