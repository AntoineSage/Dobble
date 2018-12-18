#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>

#include "dobble-config.h"
#include "dobble.h"
#include "graphics.h"
#include "time.h"
#include "carte.h"
#include <unistd.h>

/// Etat du compte à rebous (lancé/non lancé)
static bool timerRunning = false;

Carte carte;
Icone* ic;
Icone* ic2;
Icone* ic3;
Icone* ic4;
Icone* ic5;
Icone* ic6;
Icone* ic7;
Icone* ic8;
Icone* ic9;

void onMouseMove(int x, int y)
{
	printf("dobble: Position de la souris: (%3d %3d)\r", x, y);
	fflush(stdout);
}


void onMouseClick()
{
	printf("\ndobble: Clic de la souris.\n");

	if (timerRunning)
	{
		printf("\ndobble: Arrêt du compte à rebours.\n");
		stopTimer();
		timerRunning = false;
	}
	else
	{
		printf("\ndobble: Démarrage du compte à rebours.\n");
		startTimer();
		timerRunning = true;
	}
}

void onTimerTick()
{
	printf("\ndobble: Tic du compte à rebours\n");
}

void renderScene()
{
	char title[100];

	// Efface le contenu de la fenêtre
	clearWindow();
	// Crée le titre qui sera affiché. Utile pour afficher le score.
	sprintf(title, "RICM3-Dobble    Score %d", 100);
	drawText(title, WIN_WIDTH / 2, 0, Center, Top);

	CardPosition currentCard = UpperCard;

	// Dessin du fond de carte de la carte supérieure
	drawCardShape(currentCard, 5, 252, 252, 252, 155, 119, 170);

    // -----------------------------------------------------------------
   	int cardCenterX = 0, cardCenterY = 0;
    getCardCenter(currentCard, &cardCenterX, &cardCenterY);

    drawCircle(ic -> position.x + cardCenterX, ic -> position.y + cardCenterY, ic -> scale * ICON_SIZE / 2, 100, 0, 0, 100);
	drawIcon(currentCard, 0, ic -> distance, ic -> angle, ic -> rotation, ic -> scale, NULL, NULL);
	drawIcon(currentCard, 0, ic2 -> distance, ic2 -> angle, ic2 -> rotation, ic2 -> scale, NULL, NULL);
	drawIcon(currentCard, 0, ic3 -> distance, ic3 -> angle, ic3 -> rotation, ic3 -> scale, NULL, NULL);
	drawIcon(currentCard, 0, ic4 -> distance, ic4 -> angle, ic4 -> rotation, ic4 -> scale, NULL, NULL);
	drawIcon(currentCard, 0, ic5 -> distance, ic5 -> angle, ic5 -> rotation, ic5 -> scale, NULL, NULL);
	drawIcon(currentCard, 0, ic6 -> distance, ic6 -> angle, ic6 -> rotation, ic6 -> scale, NULL, NULL);
	drawIcon(currentCard, 0, ic7 -> distance, ic7 -> angle, ic7 -> rotation, ic7 -> scale, NULL, NULL);
	drawIcon(currentCard, 0, ic8 -> distance, ic8 -> angle, ic8 -> rotation, ic8 -> scale, NULL, NULL);
	drawIcon(currentCard, 0, ic9 -> distance, ic9 -> angle, ic9 -> rotation, ic9 -> scale, NULL, NULL);
    // -----------------------------------------------------------------

	// Met au premier plan le résultat des opérations de dessin
	showWindow();
}

int main(int argc, char **argv)
{
	srand(time(NULL));

    carte = nouvelleCarte();
    carte.nbIcones = 9;
    carte.icones[0] = nouvelIcone();
    carte.icones[1] = nouvelIcone();
    carte.icones[2] = nouvelIcone();
    carte.icones[3] = nouvelIcone();
    carte.icones[4] = nouvelIcone();
    carte.icones[5] = nouvelIcone();
    carte.icones[6] = nouvelIcone();
    carte.icones[7] = nouvelIcone();
    carte.icones[8] = nouvelIcone();
    ic = &carte.icones[0];   
    ic2 = &carte.icones[1];   
    ic3 = &carte.icones[2];   
    ic4 = &carte.icones[3];   
    ic5 = &carte.icones[4];   
    ic6 = &carte.icones[5]; 
    ic7 = &carte.icones[6]; 
    ic8 = &carte.icones[7]; 
    ic9 = &carte.icones[8];   

    positionAleatoireIcones(&carte);

    printf("Dist : %f\t Angle : %f\n", ic -> distance, ic -> angle);

    fromComplexToXY(ic);
    fromXYtoComplex(ic);

    printf("Dist : %f\t Angle : %f\n", ic -> distance, ic -> angle);

	if (!initializeGraphics())
	{
		printf("dobble: Echec de l'initialisation de la librairie graphique.\n");
		return 1;
	}

	if (loadIconMatrix(DATA_DIRECTORY "/Matrice8x10_Icones90x90.png") != 1)
	{
		printf("dobble: Echec du chargement des icônes.\n");
		return -1;
	}

    while(!carteIsValid(&carte)) {
        fromComplexToXY(ic);
        fromComplexToXY(ic2);
        fromComplexToXY(ic3);
        fromComplexToXY(ic4);
        fromComplexToXY(ic5);
        fromComplexToXY(ic6);
        fromComplexToXY(ic7);
        fromComplexToXY(ic8);
        fromComplexToXY(ic9);

        updateIcones(&carte);
        // updateIcone(ic);
        fromXYtoComplex(ic);
        fromXYtoComplex(ic2);
        fromXYtoComplex(ic3);
        fromXYtoComplex(ic4);
        fromXYtoComplex(ic5);
        fromXYtoComplex(ic6);
        fromXYtoComplex(ic7);
        fromXYtoComplex(ic8);
        fromXYtoComplex(ic9);

        renderScene();
        usleep(10);
    }
    freeGraphics();
    printf("done");
	return 0;
}