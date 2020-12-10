/*
* Authors: Dumas Leander & Kremer Felix
* Date: 27/11/2020
* Description: Main file to play Yahtzee
*/

// Libraries
#include "game.h"
#include "graphicsYahtzee.h"

int main(void)
{
	srand(time(NULL)); // Initialize randomness

	myLog("INFO", "Opening & clearing log file success.", 0); // -> INFO :: date - time :: File:.\Yahtzee_Project_Leander_Felix_2020.c (line: 58) :: Log file open success
	//myLog("INFO", "This is a test %i", 0, 0);

	int scorePlayerOne[MAX_GAMES][MAX_ROUNDS + 1]; // Player 1 score array
	int scorePlayerTwo[MAX_GAMES][MAX_ROUNDS + 1]; // Player 2 score array

	int scorePlayerOneRound[MAX_ROUNDS + 1];
	int scorePlayerTwoRound[MAX_ROUNDS + 1];

	int * playerOneDicePointer; // Pointer to player 1's dice array
	int * playerTwoDicePointer; // Pointer to player 2's dice array

	for (int i = 0; i < MAX_GAMES; i++) // Clear the score arrays
	{
		for (int j = 0; j < MAX_ROUNDS + 1; j++)
		{
			scorePlayerOne[i][j] = 0;
			scorePlayerTwo[i][j] = 0;
		}
	}

	for (int i = 0; i < MAX_ROUNDS + 1; i++) // Clear the round score arrays
	{
		scorePlayerOneRound[i] = 0;
		scorePlayerTwoRound[i] = 0;
	}

	printIntro(); // Annoying while trying to debug. Turn on before release!
	system("PAUSE");
	for (int i = 0; i < MAX_GAMES; i++)
	{
		printf("Game: %i / %i\n", i + 1, MAX_GAMES);
		for (int j = 0; j < MAX_GAMES; j++)
		{
			printf("Round: %i / %i\n", j + 1, MAX_ROUNDS);
			printf("Player one's turn\n");
			system("PAUSE");
			playerOneDicePointer = playGame(scorePlayerOneRound, MAX_REROLLS);
			for (int k = 0; k < 13; k++)
			{
				scorePlayerOneRound[k] = * (playerOneDicePointer + k);
				printf("Score %i = %i\n", i, scorePlayerOneRound[k]); // DEBUG
			}

			printf("Player two's turn\n");
			system("PAUSE");
			playerTwoDicePointer = playGame(scorePlayerTwoRound, MAX_REROLLS);
			for (int k = 0; k < 13 + 1; k++)
			{
				scorePlayerTwoRound[k] = * (playerTwoDicePointer + k);
				printf("Score %i = %i\n", i, scorePlayerTwoRound[k]); // DEBUG
			}

			for (int k = 0; k < MAX_ROUNDS + 1; k++)
			{
				scorePlayerOne[i][k] = scorePlayerOneRound[k];
				scorePlayerTwo[i][k] = scorePlayerTwoRound[k];
			}

			printf("Player one's score:\n");
			printScore(scorePlayerOne);
			printf("Player two's score:\n");
			printScore(scorePlayerTwo);
			system("PAUSE");
		}
	}

	printScore(scorePlayerOne);
	printScore(scorePlayerTwo);
	getWinner(scorePlayerOne, scorePlayerTwo);

	exit(EXIT_SUCCESS);

	return 0;
}
