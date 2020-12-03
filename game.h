#include <time.h>

#define DICE_PER_GAME 5 // Total dice in the game
#define MAX_REROLLS 2 // Maximum amount of times you can reroll dice. Fill in ONE LESS then the total amount of games!

void playGame(void);
void printDice(char dice[]);
char * rollDiceSet(char amountOfDice, char forceKeep);
char * selectDice(char diceArray[], char lenghtOfArray, char clear);
char checkArrayValue(char scoreArray[], int pos);
char * rollDice(char diceCount);
char rollRandomDie(void);
char rollDie(char n);
int getUserInput(void);

/*
* tbd
* @param: tbd
* @return: tbd
*/
void playGame(void)
{
	char dice[DICE_PER_GAME]; // Local dice array
	char * diceArrayPointer = 0; // Return array pointer
	char confirm = 'x'; // y/n input from user
	char dieCounter = 0;
	char rollCounter = 0; // Counts the amount of rolls made
	char copyCounter = 0; // Saves the position during copying

	for (int i = 0; i < DICE_PER_GAME; i++) // Clearing dice array
	{
		dice[i] = 0;
	}

	do // Main game loop
	{
		printf("Roll: %i / %i\n", rollCounter + 1, MAX_REROLLS + 1); // Prints the round
		printf("Roll counter: %i\n", rollCounter);
		if (rollCounter == MAX_REROLLS)
		{
			printf("FORCE KEEP ROLL\n"); // DEBUG
			diceArrayPointer = rollDiceSet((DICE_PER_GAME - dieCounter), 1); // Rolls dice
		}
		else
		{
			diceArrayPointer = rollDiceSet((DICE_PER_GAME - dieCounter), 0); // Rolls dice
		}

		copyCounter = 0; // Resets the copy counter
		for (int i = 0; i < DICE_PER_GAME; i++) // copying diceArrayPointer to dice
		{
			if (!dice[i])
			{
				dice[i] = * (diceArrayPointer + copyCounter);
				copyCounter++;
			}
		}
		dieCounter = 0;
		for (int i = 0; i < DICE_PER_GAME; i++) // Counting dice
		{
			dieCounter += dice[i] ? 1 : 0;
		}

		printf("Print one\n"); // DEBUG
		printDice(dice); // Prints what dice the player currently has

		do // Loop for confirming input if the user want to keep these dice
		{
			if (rollCounter == MAX_REROLLS || dieCounter == 0)
			{
				break;
			}
			printf("Would you like to return dice for rerolling (y/n)?\n");
			scanf(" %c", &confirm);

			if (confirm == 'y' || confirm == 'Y') // Rerolling dice
			{
				diceArrayPointer = selectDice(dice, dieCounter, 1);
				printf("Resetting array\n"); // DEBUG
				for (int i = 0; i < DICE_PER_GAME; i++) // Resetting dice array
				{
					dice[i] = 0;
				}
				//printDice(dice); // Prints what dice the player currently has
			}
			else if (confirm != 'n' && confirm != 'N')
			{
				printf("Invalid input!\n");
			}
		}
		while ((confirm != 'y' && confirm != 'Y') && (confirm != 'n' && confirm != 'N')); // If the user didn't enter y or n

		copyCounter = 0; // Resets the copy counter
		printf("Die counter: %i\nCopy counter: %i\n", dieCounter, copyCounter); // DEBUG

		if (confirm == 'y' || confirm == 'Y')
		{
			for (int i = 0; i < DICE_PER_GAME; i++) // copying diceArrayPointer to dice
			{
				if (!dice[i])
				{
					dice[i] = * (diceArrayPointer + copyCounter);
					copyCounter++;
				}
			}
			dieCounter = 0;
			for (int i = 0; i < DICE_PER_GAME; i++) // Counting dice
			{
				printf("Counting dice (2) die: %i : value: %i :: ", i, dice[i]); // DEBUG
				dieCounter += dice[i] ? 1 : 0;
				printf("Die counter: %i\n", dieCounter); // DEBUG
			}

			printf("Print two\n"); // DEBUG
			printDice(dice); // Prints what dice the player currently has
			confirm = 'x';
		}
		printf("Die counter: %i\n", dieCounter); // DEBUG
		rollCounter++; // One roll has finished
	}
	while(dieCounter < DICE_PER_GAME);
}

/*
* tbd
* @param: tbd
* @return: tbd
*/
void printDice(char dice[])
{
	printf("You have the following dice:\n");
	for (int i = 0; i < DICE_PER_GAME; i++)
	{
		printf("Die[%i] = %i\n", i + 1, dice[i]);
	}
}

/*
* tbd
* @param: (char) Amount of dice in the roll
* @return: tbd
*/
char * rollDiceSet(char amountOfDice, char forceKeep)
{
	static char diceArray[DICE_PER_GAME]; // Dice list
	char * dicePointer = rollDice(amountOfDice); // Rolls x dice

	for (int i = 0; i < DICE_PER_GAME; i++) // Clearing array to prevent random values
	{
		diceArray[i] = 0;
	}

	for (int i = 0; i < amountOfDice; i++) // copying dicePointer array to diceArray
	{
		diceArray[i] = * (dicePointer + i);
	}

	if (!forceKeep)
	{
		dicePointer = selectDice(diceArray, amountOfDice, 0);
	}

	for (int i = 0; i < amountOfDice; i++) // copying dicePointer array to diceArray
	{
		diceArray[i] = * (dicePointer + i);
	}

	return diceArray;
}

/*
* tbd
* @param: tbd
* @return: tbd
*/
char * selectDice(char diceArray[], char lenghtOfArray, char clear)
{
	int i = 0; // Counter used in loops
	char confirm = 'x'; // y/n input from user
	int tmpDieStorage = 0; // temporary storage for the dice number
	char doubleEntryCheck = 0; // 1/0 set if q die is already in the list
	char selectDiceArray[lenghtOfArray]; // Selected dice list
	char keepDie; // Used to determen wath value should be cleared from the return array
	static char returnArray[DICE_PER_GAME]; // The array that will be returned
	int arrayPosCounter = 0; // Counter used when creating the output array
	char printCounter = 0; // A counter used during the printing of the array

	for (int i = 0; i < lenghtOfArray; i++) // Clearing array to prevent random values
	{
		selectDiceArray[i] = 0;
		returnArray[i] = 0;
	}

	do // Main loop for selecting dice
	{
		if (clear)
		{
			printf("Enter the number of the die you would like to return.\nEnter 0 to stop.\n");
		}
		else
		{
			printf("Enter the number of the die you would like to keep.\nEnter 0 to stop.\n");
		}

		do // Loop for entering dice
		{
			do // Loop for entering ONE die
			{
				printf("You have %i entries left.\n", lenghtOfArray - i);
				//scanf("%i", &tmpDieStorage) // Stores the enterd value to check it
				tmpDieStorage = getUserInput();
				printf("Input: %i\n", tmpDieStorage); // DEBUG

				if (tmpDieStorage < 0 || tmpDieStorage > lenghtOfArray) // Checks if the value is out of bounds (0-5)
				{
					printf("Input out of bounds (0 - %i)\n", lenghtOfArray);
				}
				else// if (tmpDieStorage >= 0 && tmpDieStorage <= lenghtOfArray)
				{
					if (checkArrayValue(selectDiceArray, i) && tmpDieStorage > 0) // Checks if the position in the array is unused (0) if the user didn't enter 0 to stop
					{
						for (int k = i; k >= 0; k--) // Checks if the enter value is already in the array
						{
							if (selectDiceArray[k] == tmpDieStorage)
							{
								doubleEntryCheck = 1;
							}
						}
						if (doubleEntryCheck) // Value is already chosen
						{
							printf("Die already chosen\n");
							doubleEntryCheck = 0;
						}
						else
						{
							selectDiceArray[i] = tmpDieStorage; // Puts the value in the array
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
							printf("The value %i is in this position.\n", selectDiceArray[i]);
						}
					}
				}
				// else if ((next = getchar()) != EOF && next != '\n')
				// {
				// 	printf("Invalid input!\n");
				// 	tmpDieStorage = -1;
				// }
			}
			while (selectDiceArray[i] == 0 && tmpDieStorage != 0); // There is no value in the current position of the array and the user didn't want to stop
			i++;
		}
		while (tmpDieStorage != 0 && i < lenghtOfArray); // The uses want's to enter a value and is not over the limit

		if (clear)
		{
			printf("Returning folowing dice:\n");
		}
		else
		{
			printf("Keeping folowing dice:\n");
		}

		if (selectDiceArray[0])
		{
			i = 0;
			for (int i = 0; i < lenghtOfArray; i++)
			{
				printCounter += selectDiceArray[i] ? 1 : 0;
			}
			printf("Print counter: %i\n", printCounter); // DEBUG
			while (selectDiceArray[i] && i < printCounter) // Loop to print kept dice
			{
				printf("Die: %i - with value: %i\n", selectDiceArray[i], diceArray[selectDiceArray[i] - 1]);
				i++;
			}
			//while (selectDiceArray[i]); // Keeps going until the array is run trough or all value not 0 have been displayed
		}
		else
		{
			printf("None.\n");
		}

		do // Loop for confirming input
		{
			printf("Is this correct (y/n)? \n");
			scanf(" %c", &confirm);

			if (confirm == 'n' || confirm == 'N')
			{
				i = 0;
				for (int i = 0; i < lenghtOfArray; i++) // Clear the array to enter new values
				{
					selectDiceArray[i] = 0;
				}

				printCounter = 0;
			}
			else if (confirm != 'y' && confirm != 'Y')
			{
				printf("Invalid input!\n");
			}
		}
		while ((confirm != 'y' && confirm != 'Y') && (confirm != 'n' && confirm != 'N')); // If the user didn't enter y or n
	}
	while (confirm != 'y' && confirm != 'Y'); // While the user doesn't want to continue

	keepDie = clear ? 1 : 0;

	for (int i = 0; i < lenghtOfArray; i++) // Clearing the return array of removed values
	{
		for (int j = 0; j < lenghtOfArray; j++)
		{
			if ((selectDiceArray[j] - 1) == i)
			{
				printf("Keeping die: %i\n", i + 1); // DEBUG
				keepDie = clear ? 0 : 1;
			}
		}

		if (!keepDie)
		{
			printf("Removing die: %i\n", i + 1); // DEBUG
			diceArray[i] = 0;
		}

		keepDie = clear ? 1 : 0;
	}

	for (int i = 0; i < lenghtOfArray; i++) // Moving > 0 values in array to the left
	{
		if (diceArray[i])
		{
			returnArray[arrayPosCounter] = diceArray[i];
			arrayPosCounter++;
		}
	}

	return returnArray;
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
* @param: (char) diceCount Amount of dice you would like to roll.
* @return: (char *) An array with all dice values.
*/
char * rollDice(char diceCount)
{
	static char dice[DICE_PER_GAME];

	for (int i = 0; i < DICE_PER_GAME; i++)
	{
		dice[i] = 0; // Filling the static array with 0's for reuse
	}

	for (int j = 0; j < diceCount; j++)
	{
		printf("Die - %i:\n", j + 1);
		dice[j] = rollRandomDie();
	}

	return dice;
}

/*
* Rolls a random die.
* @param: void
* @return: rollDie() (char) What die was rolled as numeric value.
*/
char rollRandomDie(void)
{
	return rollDie((rand() % 6) + 1);
}

/*
* Rolls a given die.
* @param: n (char) What die needs to be rolled.
* @return: die (char) What die was rolled as numeric value.
*/
char rollDie(char n)
{
	char die = 0;

	switch (n)
	{
		case 1:
			die = dice1(n);
			break;
		case 2:
			die = dice2(n);
			break;
		case 3:
			die = dice3(n);
			break;
		case 4:
			die = dice4(n);
			break;
		case 5:
			die = dice5(n);
			break;
		case 6:
			die = dice6(n);
			break;
		default:
			printf("An error occourt.\nFailed to roll a die (%i)", n);
			break;
	}

	return die;
}

/*
* Found at https://stackoverflow.com/questions/41145908/how-to-stop-user-entering-char-as-int-input-in-c
* Credit: chux - Reinstate Monica : https://stackoverflow.com/users/2410359/chux-reinstate-monica
* @param: tbd
* @return: tbd
*/
int getUserInput(void)
{
	char buffer[10];
	fflush(stdout);
	while (fgets(buffer, sizeof buffer, stdin))
	{
		int value;
		if (sscanf(buffer, "%d", &value) == 1 && value >= 0)
		{
			return value;
		}
		fflush(stdout);
	}
	return -1;
}
