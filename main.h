#ifndef DEF_MAIN

#define DEF_MAIN

#define TAILLE_TABLEAU 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Game Game;

struct Game
{
	char userGuess[2];
	int numberOfTrial;
	char hiddenWord[6];
	char letterFound[6];
	int result;
};

void initialiseGame(Game *game);
void askUserAGuess(Game *game);
void emptyBuffer();
void revealALetter(Game *game, char *pointerToString);
void handleUserGuess(Game *game);
int printResult(Game *game);
char getActualStateOfHiddenString(Game *game, char actualString[]);
void withdrawATrial(Game *game);

#endif