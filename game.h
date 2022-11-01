#ifndef DEF_GAME

#define DEF_GAME

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
int printResult(Game *game);

#endif