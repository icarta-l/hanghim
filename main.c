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