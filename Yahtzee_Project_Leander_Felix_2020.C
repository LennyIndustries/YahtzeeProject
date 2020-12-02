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

#include "graphicsYahtzee.h"
//#include "yahtzee.h"

// Declarations
//#define AANTAL_DEMO_STENEN 5
#define DICE_PER_GAME 5
#define MAX_GAMES 5 // Maximum amound of rounds played per player.
#define MAX_REROLLS 2 // Maximum amount of times you can reroll dice.

// Functions
char checkArrayValue(char scoreArray[], int pos);
char * rollAllDice(void);

int main(void)
{
	srand(time(NULL)); // Sets the random seed

	char scorePlayerOne[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // Player 1 score array
	char scorePlayerTwo[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // Player 2 score array

	char * playerOneDicePointer;
	char * playerTwoDicePointer;

	//char playerOneDice[DICE_PER_GAME];
	//char playerTwoDice[DICE_PER_GAME];

	//char die1, die2, die3, die4, die5;
	char diceArray[] = {0, 0, 0, 0, 0};
	//char diceToKeep = 0;

	char confirm = 'x';
	int i = 0;
	int tmpDieStorage = 0;
	int doubleEntryCheck = 0;

	for (int gameCounter = 0; gameCounter < MAX_GAMES; gameCounter++)
	{
		//player one rolls
		printf("Player one's turn.\n");
		playerOneDicePointer = rollAllDice(); // Rolls 5 dice for player 1

		do // Main loop for selecting dice
		{
			printf("Enter the number of the die you would like to keep.\nEnter 0 to stop.\n");

			do // Loop for entering dice
			{
				do // Loop for entering ONE die
				{
					printf("You have %i entries left.\n", 5 - i);
					scanf("%i", &tmpDieStorage); // Stores the enterd value to check it

					if (tmpDieStorage < 0 || tmpDieStorage > 5) // Checks if the value is out of bounds (0-5)
					{
						printf("Input out of bounds (0 - 5)\n");
					}
					else
					{
						if (checkArrayValue(diceArray, i) && tmpDieStorage > 0) // Checks if the position in the array is unused (0) if the user didn't enter 0 to stop
						{
							for (int k = i; k >= 0; k--)
							{
								if (diceArray[k] == tmpDieStorage)
								{
									doubleEntryCheck = 1;
								}
							}
							if (doubleEntryCheck)
							{
								printf("Dice already chosen\n");
								doubleEntryCheck = 0;
							}
							else
							{
								diceArray[i] = tmpDieStorage;
							}
						}
						else
						{
							if (tmpDieStorage == 0) // If the user want's to stop entering values
							{
								printf("Stopping input.\n");
							}
							else // If the position in the array is usedd already
							{
								printf("The value %i is in this position.\n", diceArray[i]);
							}
						}
					}
				}
				while (diceArray[i] == 0 && tmpDieStorage != 0); // There is no value in the current position of the array and the user didn't want to stop

				i++;
			}
			while (tmpDieStorage != 0 && i < DICE_PER_GAME); // The uses want's to enter a value and is not over the limit

			printf("Keeping folowing dice:\n");

			if (diceArray[0])
			{
				i = 0;
				do // Loop to print kept dice
				{
					printf("Die: %i - with value: %i\n", diceArray[i], * (playerOneDicePointer + (diceArray[i] - 1)));
					i++;
				}
				while (diceArray[i]); // Keeps going until the array is run trough or all value not 0 have been displayed
			}
			else
			{
				printf("None.\n");
			}

			do // Loop for confirming input
			{
				printf("Is this correct (y/n)? \n");
				scanf(" %c", &confirm);

				if (confirm == 'n')
				{
					i = 0;
					for (int i = 0; i < DICE_PER_GAME; i++) // Clear the array to enter nez values
					{
						diceArray[i] = 0;
					}
				}
				else if (confirm != 'y')
				{
					printf("Invalid input!\n");
				}
			}
			while (confirm != 'y' && confirm != 'n'); // If the user didn't enter y or n
	}
	while (confirm != 'y'); // While the user doesn't want to continue

		//printf("%c\n", confirm);
		//if relolling go to start
		//if keeping all dice end round
	}

	exit(EXIT_SUCCESS);

	return 0;
}

/*
* Checks a position in an array to be 0.
* Returns 1 or 0 on a success or fail.
* @param: (char) scoreArray[] The array you want checked, (char) pos The position you would like to check.
* @return: (char) 1 (success) or 0 (failed).
*/
char checkArrayValue(char array[], int pos)
{
	if (!array[pos])
	{
		return 1;
	}
	return 0;
}

/*
* Rolls a set amount of random dice.
* Returns all rolled dice.
* @param: void
* @return: (char *) An array with all dice values.
*/
char * rollAllDice(void)
{
	static char dice[DICE_PER_GAME];

	for (int i = 0; i < DICE_PER_GAME; i++)
	{
		printf("Die - %i:\n", i + 1);
		dice[i] = rollRandomDie();
	}

	return dice;
}
