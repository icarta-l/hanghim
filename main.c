#include "main.h"

int main(int argc, char *argv[])
{
	Game game;

	initialiseGame(&game);

	while(game.result != 1)
	{
		askUserAGuess(&game);
		game.result = printResult(&game);
	}

	return 0;
}

void initialiseGame(Game *game)
{
	game->userGuess = 0;
	game->numberOfTrial = 10;
	game->result = 0;

	game->hiddenWord[0] = 'R';
	game->hiddenWord[1] = 'O';
	game->hiddenWord[2] = 'U';
	game->hiddenWord[3] = 'G';
	game->hiddenWord[4] = 'E';
	game->hiddenWord[5] = '\0';

	game->letterFound[0] = 0;
	game->letterFound[1] = 0;
	game->letterFound[2] = 0;
	game->letterFound[3] = 0;
	game->letterFound[4] = 0;
	game->letterFound[5] = '\0';
}

char getActualStateOfHiddenString(Game *game, char actualString[])
{
	for (int i = 0; i < sizeof game->hiddenWord - 1; ++i)
	{
		if (game->letterFound[i] != 0)
		{
			actualString[i] = game->letterFound[i];
		}
		else
		{
			actualString[i] = '*';
		}
	}
}

int printResult(Game *game)
{
	char actualString[sizeof game->hiddenWord] = {0};
	printf("You have just guessed \"%c\"\n", game->userGuess);

	handleUserGuess(game);
	getActualStateOfHiddenString(game, actualString);

	if (strcmp(actualString,game->hiddenWord) == 0)
	{
		printf("You've won! The word was %s!\n", game->hiddenWord);
		return 1;
	}
	else {
		return 0;
	}
}

void handleUserGuess(Game *game)
{
	char *pointerToString = NULL;

	pointerToString = strchr(game->hiddenWord, game->userGuess);
	if (pointerToString != NULL)
	{
		revealALetter(game, pointerToString);
	}
	else
	{
		withdrawATrial(game);
	}
}

void withdrawATrial(Game *game)
{
	--game->numberOfTrial;

	if (game->numberOfTrial == 0)
	{
		printf("Sorry, game is over!\n");
		exit(0);
	}
}

void revealALetter(Game *game, char *pointerToString)
{
	int position = pointerToString - game->hiddenWord;
	game->letterFound[position] = game->userGuess;
}

void askUserAGuess(Game *game)
{
	char actualString[sizeof game->hiddenWord] = {0};
	int foundCharacter = 0;
	int inputIsLetter = 1;

	do {
		getActualStateOfHiddenString(game, actualString);
		printQueryToUser(game, actualString);
		game->userGuess = toupper(getchar());
		foundCharacter = emptyBuffer();
		if (foundCharacter == 1)
		{
			continue;
		}
		inputIsLetter = checkUserGuessIsALetter(game);
	} while (foundCharacter != 0 || inputIsLetter == 0);
}

int checkUserGuessIsALetter(Game *game)
{
	if (isalpha(game->userGuess) == 0)
	{
		printf("Please tap a letter \n");
	}

	return isalpha(game->userGuess);
}

void printQueryToUser(Game *game, char actualString[])
{
	printf("You have %d trials left\n", game->numberOfTrial);
	printf("What is the hidden word? %s\n", actualString);
	printf("Choose a character: \n");
}

int emptyBuffer()
{
	int c = 0;
	int foundCharacter = 0;

	while (c != '\n' && c != EOF)
	{
		c = getchar();
		if (foundCharacter == 0 && c != '\n')
		{
			printf("Please tap only one character \n");
			foundCharacter = 1;
		}
	}

	return foundCharacter;
}