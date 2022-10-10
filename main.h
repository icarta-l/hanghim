#ifndef DEF_MAIN

#define DEF_MAIN

#define TAILLE_TABLEAU 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Game Game;

struct Game
{
	int userGuess;
	int numberOfTrial;
	char hiddenWord[6];
	char letterFound[6];
	int result;
};

void initialiseGame(Game *game);
void askUserAGuess(Game *game);
int emptyBuffer();
void revealALetter(Game *game, char *pointerToString);
void handleUserGuess(Game *game);
int printResult(Game *game);
char getActualStateOfHiddenString(Game *game, char actualString[]);
void withdrawATrial(Game *game);
void printQueryToUser(Game *game, char actualString[]);
int checkUserGuessIsALetter(Game *game);

#endif