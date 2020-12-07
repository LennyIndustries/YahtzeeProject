/*
* Authors: Dumas Leander & Kremer Felix
* Date: 27/11/2020
* Description: Start code voor Yahtzee spel
*/

// Puntern verdeeling: Er kan maar één rij gekozen worden met uitzondering van Yahtzee als deze al is ingevuld.
// Bovenste rijen aantal van dezelfde dobblestenen: 5*2 of 3*4
// Onderste rijen:
// 3 of a kind: totaal van al de dobblestenen als er minstens 3 gelijk zijn. som
// 4 of a kind: totaal van al de dobblestenen als er minstens 4 gelijk zijn. som
// Full house: minstens 3 gelijk en één paar of 5 gelijk als Yahtzee al is ingevuld. 25pt
// Small straight: 4 opeenvolgende. 30pt
// Large straight: 5 opeenvolgende. 40pt
// Chance: som
// Yahtzee: alle dobblestenen moetten gelijk zijn. 50pt Al deze al is ingevuld krijt de speler nog 100pt extra en een ander score vak.

// Libaries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "graphicsYahtzee.c"
#include "game.c"

// Declarations
#define MAX_GAMES 5 // Maximum amound of rounds played per player.
#define MAX_REROLLS 2 // Maximum amount of times you can reroll dice. Fill in ONE LESS then the total amount of rerolls!

int main(void)
{
	char scorePlayerOne[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // Player 1 score array
	char scorePlayerTwo[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // Player 2 score array

	char * playerOneDicePointer; // Pointer to player 1's dice array
	char * playerTwoDicePointer; // Pointer to player 2's dice array

	printIntro(MAX_GAMES, MAX_REROLLS); // Annoying while trying to debug
	system("PAUSE");
	for (int i = 0; i < MAX_GAMES; i++)
	{
		printf("Game: %i / %i\n", i + 1, MAX_GAMES);
		printf("Player one's turn\n");
		system("PAUSE");
		playerOneDicePointer = playGame(scorePlayerOne, MAX_REROLLS);
		for (int i = 0; i < 13; i++)
		{
			scorePlayerOne[i] = * (playerOneDicePointer + i);
			printf("Score %i = %i\n", i, scorePlayerOne[i]);
		}
		printScore(scorePlayerOne);

		printf("Player two's turn\n");
		system("PAUSE");
		playerTwoDicePointer = playGame(scorePlayerTwo, MAX_REROLLS);
		for (int i = 0; i < 13; i++)
		{
			scorePlayerTwo[i] = * (playerTwoDicePointer + i);
			printf("Score %i = %i\n", i, scorePlayerTwo[i]);
		}
		printScore(scorePlayerTwo);
	}

	getWinner(scorePlayerOne, scorePlayerTwo);

	exit(EXIT_SUCCESS);

	return 0;
}
