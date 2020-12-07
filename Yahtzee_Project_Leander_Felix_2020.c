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
#define MAX_GAMES 13 // Maximum of games played.
#define MAX_ROUNDS 5// Maximum amound of rounds played per player.
#define MAX_REROLLS 2 // Maximum amount of times you can reroll dice. Fill in ONE LESS then the total amount of rerolls!

// Functions
void printScore(int score[MAX_ROUNDS][MAX_GAMES + 1]);
void getWinner(int playerOneArray[MAX_ROUNDS][MAX_GAMES + 1], int playerTwoArray[MAX_ROUNDS][MAX_GAMES + 1]);

int main(void)
{
	int scorePlayerOne[MAX_ROUNDS][MAX_GAMES + 1]; // Player 1 score array
	int scorePlayerTwo[MAX_ROUNDS][MAX_GAMES + 1]; // Player 2 score array

	int scorePlayerOneRound[MAX_GAMES + 1];
	int scorePlayerTwoRound[MAX_GAMES + 1];

	int * playerOneDicePointer; // Pointer to player 1's dice array
	int * playerTwoDicePointer; // Pointer to player 2's dice array

	for (int i = 0; i < MAX_ROUNDS; i++) // Clear the score arrays
	{
		for (int j = 0; j < MAX_GAMES + 1; j++)
		{
			scorePlayerOne[i][j] = 0;
			scorePlayerTwo[i][j] = 0;
		}
	}

	for (int i = 0; i < MAX_GAMES + 1; i++) // Clear the round score arrays
	{
		scorePlayerOneRound[i] = 0;
		scorePlayerTwoRound[i] = 0;
	}

	printIntro(MAX_GAMES, MAX_REROLLS); // Annoying while trying to debug
	system("PAUSE");
	for (int i = 0; i < MAX_ROUNDS; i++)
	{
		printf("Round: %i / %i\n", i + 1, MAX_ROUNDS);
		for (int j = 0; j < MAX_GAMES; j++)
		{
			printf("Game: %i / %i\n", j + 1, MAX_GAMES);
			printf("Player one's turn\n");
			system("PAUSE");
			playerOneDicePointer = playGame(scorePlayerOneRound, MAX_REROLLS);
			for (int k = 0; k < 13; k++)
			{
				scorePlayerOneRound[k] = * (playerOneDicePointer + k);
				//printf("Score %i = %i\n", i, scorePlayerOne[i]);
			}

			printf("Player two's turn\n");
			system("PAUSE");
			playerTwoDicePointer = playGame(scorePlayerTwoRound, MAX_REROLLS);
			for (int k = 0; k < 13 + 1; k++)
			{
				scorePlayerTwoRound[k] = * (playerTwoDicePointer + k);
				//printf("Score %i = %i\n", i, scorePlayerTwo[i]);
			}

			for (int k = 0; k < MAX_GAMES + 1; k++)
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

/*
* Prints the score screen
* @param: (char) The scores to print
* @return: VOID
*/
void printScore(int score[MAX_ROUNDS][MAX_GAMES + 1])
{
	int scoreSumOne = 0;
	int scoreSumTwo = 0;
	int scoreSumThree = 0;
	int scoreSumFour = 0;
	int scoreSumFive = 0;
	int scoreSumTotal = 0;

	for (int i = 0; i < MAX_ROUNDS; i++)
	{
		//printf("I = %i\n", i); // DEBUG
		for (int j = 0; j < MAX_GAMES + 1; j++)
		{
			//printf("J = %i\n", j); // DEBUG
			if (score[i][j] > 0)
			{
				//printf("Score over 0: %i\n", score[i][j]); // DEBUG
				scoreSumTotal += score[i][j];

				switch (i)
				{
					case 0:
						scoreSumOne += score[i][j];
						break;
					case 1:
						scoreSumTwo += score[i][j];
						break;
					case 2:
						scoreSumThree += score[i][j];
						break;
					case 3:
						scoreSumFour += score[i][j];
						break;
					case 4:
						scoreSumFive += score[i][j];
						break;
					default:
						printf("Failed to calculate score!\n");
						exit(EXIT_FAILURE);
						break;
				}
			}
		}
	}

	printf("=================================================================\n");
	printf("| Aces\t\t\t| %i\t| %i\t| %i\t| %i\t| %i\t|\n", score[0][0], score[1][0], score[2][0], score[3][0], score[4][0]);
	printf("| Twos\t\t\t| %i\t| %i\t| %i\t| %i\t| %i\t|\n", score[0][1], score[1][1], score[2][1], score[3][1], score[4][1]);
	printf("| Threes\t\t| %i\t| %i\t| %i\t| %i\t| %i\t|\n", score[0][2], score[1][2], score[2][2], score[3][2], score[4][2]);
	printf("| Fours\t\t\t| %i\t| %i\t| %i\t| %i\t| %i\t|\n", score[0][3], score[1][3], score[2][3], score[3][3], score[4][3]);
	printf("| Fives\t\t\t| %i\t| %i\t| %i\t| %i\t| %i\t|\n", score[0][4], score[1][4], score[2][4], score[3][4], score[4][4]);
	printf("| Sixes\t\t\t| %i\t| %i\t| %i\t| %i\t| %i\t|\n", score[0][5], score[1][5], score[2][5], score[3][5], score[4][5]);
	printf("=================================================================\n");
	printf("| Three of a kind\t| %i\t| %i\t| %i\t| %i\t| %i\t|\n", score[0][6], score[1][6], score[2][6], score[3][6], score[4][6]);
	printf("| Four of a kind\t| %i\t| %i\t| %i\t| %i\t| %i\t|\n", score[0][7], score[1][7], score[2][7], score[3][7], score[4][7]);
	printf("| Full house\t\t| %i\t| %i\t| %i\t| %i\t| %i\t|\n", score[0][8], score[1][8], score[2][8], score[3][8], score[4][8]);
	printf("| Small straight\t| %i\t| %i\t| %i\t| %i\t| %i\t|\n", score[0][9], score[1][9], score[2][9], score[3][9], score[4][9]);
	printf("| Large straight\t| %i\t| %i\t| %i\t| %i\t| %i\t|\n", score[0][10], score[1][10], score[2][10], score[3][10], score[4][10]);
	printf("| Chance\t\t| %i\t| %i\t| %i\t| %i\t| %i\t|\n", score[0][11], score[1][11], score[2][11], score[3][11], score[4][11]);
	printf("| Yahtzee\t\t| %i\t| %i\t| %i\t| %i\t| %i\t|\n", score[0][12], score[1][12], score[2][12], score[3][12], score[4][12]);
	printf("=================================================================\n");
	printf("| Yahtzee bonus\t\t| %i\t| %i\t| %i\t| %i\t| %i\t|\n", score[0][13], score[1][13], score[2][13], score[3][13], score[4][13]);
	printf("=================================================================\n");
	printf("| Total\t\t\t| %i\t| %i\t| %i\t| %i\t| %i\t|\n", scoreSumOne, scoreSumTwo, scoreSumThree, scoreSumFour, scoreSumFive);
	printf("=================================================================\n");
	printf("| Grandtotal\t\t| %i\t\t\t\t\t|\n", scoreSumTotal);
	printf("=================================================================\n");
}

/*
* Compares to array and find the highes one.
* @param: (char) playerOneArray[] The array of player one; (char) playerTwoArray[] The array for player two.
* @return: VOID
*/
void getWinner(int playerOneArray[MAX_ROUNDS][MAX_GAMES + 1], int playerTwoArray[MAX_ROUNDS][MAX_GAMES + 1])
{
	int playerOneSum = 0;
	int playerTwoSum = 0;

	for (int i = 0; i < MAX_ROUNDS; i++) // Gets the sum of both arrays
	{
		for (int j = 0; j < MAX_GAMES + 1; j++)
		{
			if (playerOneArray[i][j] > 0)
			{
				playerOneSum += playerOneArray[i][j];
			}
			if (playerTwoArray[i][j] > 0)
			{
				playerTwoSum += playerTwoArray[i][j];
			}
		}
	}

	if (playerOneSum > playerTwoSum) // Checks what array if higher.
	{
		printf("Player one wins!\nFinal score:\nPlayer one: %i\nPlayer two: %i\n", playerOneSum, playerTwoSum);
	}
	else if (playerTwoSum > playerOneSum)
	{
		printf("Player two wins!\nFinal score:\nPlayer one: %i\nPlayer two: %i\n", playerOneSum, playerTwoSum);
	}
	else
	{
		printf("It's a draw\nFinal score:\nPlayer one: %i\nPlayer two: %i\n", playerOneSum, playerTwoSum);
	}
	printf("GG WP!\n");
}
