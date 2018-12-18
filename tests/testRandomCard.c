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
#include <plateau.h>
#include <fichierVersPlateau.h>

/// Etat du compte à rebous (lancé/non lancé)
static bool timerRunning = false;

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
    // -----------------------------------------------------------------

	// Met au premier plan le résultat des opérations de dessin
	showWindow();
}

int main(int argc, char const *argv[])
{
	srand(time(NULL));
    Plateau p = fichierVersPlateau(DATA_DIRECTORY "/pg28.txt");
	initCardsIconsPositions(&p);

    return 0;
}
