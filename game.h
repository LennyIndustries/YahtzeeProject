#define DICE_PER_GAME 5

void rollDiceSet(char amountOfDice);
char checkArrayValue(char scoreArray[], int pos);
char * rollDice(char diceCount);

/*
* tbd
* @param: (char) Amount of dice in the roll
* @return: tbd
*/
void rollDiceSet(char amountOfDice)
{
	int i = 0; // Counter used in loops
	char confirm = 'x'; // y/n input from user
	int tmpDieStorage = 0; // temporary storage for the dice number
	char doubleEntryCheck = 0; // 1/0 set if q die is already in the list
	char diceArray[] = {0, 0, 0, 0, 0}; // dice list
	char * dicePointer = rollDice(amountOfDice); // Rolls x dice

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
						for (int k = i; k >= 0; k--) // Checks if the enter value is already in the array
						{
							if (diceArray[k] == tmpDieStorage)
							{
								doubleEntryCheck = 1;
							}
						}
						if (doubleEntryCheck) // Value is already chosen
						{
							printf("Dice already chosen\n");
							doubleEntryCheck = 0;
						}
						else
						{
							diceArray[i] = tmpDieStorage; // Puts the value in the array
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
				printf("Die: %i - with value: %i\n", diceArray[i], * (dicePointer + (diceArray[i] - 1)));
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

			if (confirm == 'n' || confirm == 'N')
			{
				i = 0;
				for (int i = 0; i < DICE_PER_GAME; i++) // Clear the array to enter nez values
				{
					diceArray[i] = 0;
				}
			}
			else if (confirm != 'y' && confirm != 'Y')
			{
				printf("Invalid input!\n");
			}
		}
		while ((confirm != 'y' && confirm != 'Y') && (confirm != 'n' && confirm != 'N')); // If the user didn't enter y or n
	}
	while (confirm != 'y' && confirm != 'Y'); // While the user doesn't want to continue
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
