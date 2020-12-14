/*
* Here you can fine all you need to play the game.
*/

// Libraries
#include "game.h"

/*
* Main function to play a game
* @param: (char) scoreArray[] the array with all the scores of the player.
* @return: (char *) score(dice, scoreArray)
*/
int * playGame(int * scoreArray)
{
	char dice[DICE_PER_GAME]; // Local dice array
	//char * diceArrayPointer = 0; // Return array pointer
	char confirm = 'x'; // y/n input from user
	char dieCounter = 0;
	char rollCounter = 0; // Counts the amount of rolls made
	char copyCounter = 0; // Saves the position during copying

	myLog(1, __FILE__, __LINE__, 1, "Clearing dice with length: %i.", DICE_PER_GAME);
	for (int i = 0; i < DICE_PER_GAME; i++) // Clearing dice array
	{
		dice[i] = 0;
	}

	do // Main game loop
	{
		printf("Roll: %i / %i\n", rollCounter + 1, MAX_REROLLS + 1); // Prints the round
		myLog(1, __FILE__, __LINE__, 1, "Roll %i / %i", rollCounter + 1, MAX_REROLLS + 1);
		if (rollCounter == MAX_REROLLS)
		{
			myLog(1, __FILE__, __LINE__, 1, "Forcing player to keep roll.");
			myLog(1, __FILE__, __LINE__, 1, "Getting dice.");
			rollDiceSet((DICE_PER_GAME - dieCounter), 1, dice, DICE_PER_GAME); // Rolls dice
			myLog(1, __FILE__, __LINE__, 1, "Dice gotten (FORCED).");
		}
		else
		{
			myLog(1, __FILE__, __LINE__, 1, "Getting dice.");
			rollDiceSet((DICE_PER_GAME - dieCounter), 0, dice, DICE_PER_GAME); // Rolls dice
			myLog(1, __FILE__, __LINE__, 1, "Dice gotten.");
		}

		dieCounter = 0;
		myLog(1, __FILE__, __LINE__, 1, "Counting dice.");
		for (int i = 0; i < DICE_PER_GAME; i++) // Counting dice
		{
			dieCounter += dice[i] ? 1 : 0;
		}
		myLog(1, __FILE__, __LINE__, 1, "Amount of dice: %i.", dieCounter);

		printDice(dice); // Prints what dice the player currently has

		// do // Loop for confirming input if the user want to keep these dice
		// {
		// 	if (rollCounter == MAX_REROLLS || dieCounter == 0)
		// 	{
		// 		break;
		// 	}
		// 	printf("Would you like to return dice for rerolling (y/n)?\n");
		// 	scanf(" %c", &confirm);
		//
		// 	if (confirm == 'y' || confirm == 'Y') // Rerolling dice
		// 	{
		// 		myLog(1, __FILE__, __LINE__, 1, "Player is returning dice.");
		// 		//diceArrayPointer = selectDice(dice, dieCounter, 1);
		// 		selectDice(dice, dieCounter, 1, dice, DICE_PER_GAME);
		// 		printf("Resetting array\n"); // DEBUG
		// 		for (int i = 0; i < DICE_PER_GAME; i++) // Resetting dice array
		// 		{
		// 			dice[i] = 0;
		// 		}
		// 		//printDice(dice); // Prints what dice the player currently has
		// 	}
		// 	else if (confirm != 'n' && confirm != 'N')
		// 	{
		// 		printf("Invalid input!\n");
		// 	}
		// }
		// while ((confirm != 'y' && confirm != 'Y') && (confirm != 'n' && confirm != 'N')); // If the user didn't enter y or n

		copyCounter = 0; // Resets the copy counter
		printf("Die counter: %i\nCopy counter: %i\n", dieCounter, copyCounter); // DEBUG

		if (confirm == 'y' || confirm == 'Y')
		{
			for (int i = 0; i < DICE_PER_GAME; i++) // copying diceArrayPointer to dice
			{
				// if (!dice[i])
				// {
				// 	dice[i] = * (diceArrayPointer + copyCounter);
				// 	copyCounter++;
				// }
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

	return score(dice, scoreArray);
}

/*
* Compares to array and find the highes one.
* @param: (char) playerOneArray[] The array of player one; (char) playerTwoArray[] The array for player two.
* @return: VOID
*/
void getWinner(int playerOneArray[MAX_GAMES][MAX_ROUNDS + 1], int playerTwoArray[MAX_GAMES][MAX_ROUNDS + 1]) // Needs player names as input and logging
{
	int playerOneSum = 0;
	int playerTwoSum = 0;

	for (int i = 0; i < MAX_GAMES; i++) // Gets the sum of both arrays
	{
		for (int j = 0; j < MAX_ROUNDS + 1; j++)
		{
			if (playerOneArray[i][j] > 0)
			{
				printf("Score sum 1 %i + %i\n", playerOneSum, playerOneArray[i][j]); // DEBUG
				playerOneSum += playerOneArray[i][j];
			}
			if (playerTwoArray[i][j] > 0)
			{
				printf("Score sum 2 %i + %i\n", playerTwoSum, playerTwoArray[i][j]); // DEBUG
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

/*
* This function calculates the score from a givven dice array.
* @param: (char) dice[] The dice array; (char) scoreArray[] the score array for the player.
* @return: (char *) The array for the player with the new scores.
*/
int * score(char * dice, int * scoreArray) // Needs to get the log function
{
	char sumOne = 0; // Sum of all 1's
	char totalOne = 0;
	char sumTwo = 0; // Sum of all 2's
	char totalTwo = 0;
	char sumThree = 0; // Sum of all 3's
	char totalThree = 0;
	char sumFour = 0; // Sum of all 4's
	char totalFour = 0;
	char sumFive = 0; // Sum of all 5's
	char totalFive = 0;
	char sumSix = 0; // Sum of all 6's
	char totalSix = 0;
	char threeOfAKind = 0; // At least 3 of the same dice
	char fourOfAKind = 0; // At least 4 of the same dice
	char fullHouse = 0; // At least a set of 3 of the same dice and 2 of the same dice (can also be gotten by having yahtzee if it's already is filled in)
	char smallStraight = 0; // 4 sequential dice
	char largeStraight = 0; // 5 sequential dice
	char chance = 0; // Sum of all dice
	char yahtzee = 0; // 5 of the same (after first you get a bonus of 100 pt and can choose another score)
	char sequentialCheckStorage = 0; // Storage used when looking for sequential dice
	char sequentialStorage = 0;
	char sequentialCounter = 0;
	char userScoreInput = 0;
	char yahtzeeBonus = 0;
	char score = 0;
	char validInput = 0;
	char confirm = 'x'; // y/n input from user

	for (int i = 0; i < DICE_PER_GAME; i++) // Simple top scores & chance
	{
		printf("Score for die: %i - value: %i\n", i + 1, dice[i]); // DEBUG
		switch (dice[i]) // Counts all dice and gets the total
		{
			case 1:
				printf("It's a ONE\n"); // DEBUG
				totalOne++;
				sumOne += 1;
				break;
			case 2:
				printf("It's a TWO\n"); // DEBUG
				totalTwo++;
				sumTwo += 2;
				break;
			case 3:
				printf("It's a THREE\n"); // DEBUG
				totalThree++;
				sumThree += 3;
				break;
			case 4:
				printf("It's a FOUR\n"); // DEBUG
				totalFour++;
				sumFour += 4;
				break;
			case 5:
				printf("It's a FIVE\n"); // DEBUG
				totalFive++;
				sumFive += 5;
				break;
			case 6:
				printf("It's a SIX\n"); // DEBUG
				totalSix++;
				sumSix += 6;
				break;
			default:
				printf("Could not calculate score!\n");
				exit(EXIT_FAILURE);
				break;
		}
		chance += dice[i];
	}

	printf("Dice total: \n1: %i\n2: %i\n3: %i\n4: %i\n5: %i\n6: %i\n", totalOne, totalTwo, totalThree, totalFour, totalFive, totalSix); // DEBUG

	if ((totalOne >= 3) || (totalTwo >= 3) || (totalThree >= 3) || (totalFour >= 3) || (totalFive >= 3) || (totalSix >= 3)) // 3 of a kind
	{
		printf("Three of a kind\n"); // DEBUG
		threeOfAKind = 1;
	}

	if ((totalOne >= 4) || (totalTwo >= 4) || (totalThree >= 4) || (totalFour >= 4) || (totalFive >= 4) || (totalSix >= 4)) // 4 of a kind
	{
		printf("Four of a kind\n"); // DEBUG
		fourOfAKind = 1;
	}

	if ((totalOne >= 5) || (totalTwo >= 5) || (totalThree >= 5) || (totalFour >= 5) || (totalFive >= 5) || (totalSix >= 5)) // Yahtzee
	{
		printf("Yahtzee\n"); // DEBUG
		yahtzee = 1;
	}

	for (int i = 0; i < DICE_PER_GAME; i++) // Checks if there is a sequence.
	{
		sequentialCheckStorage = dice[i];
		printf("Checking die: %i\n", sequentialCheckStorage); // DEBUG
		for (int j = 0; j < DICE_PER_GAME; j++)
		{
			if (sequentialCheckStorage == 6)
			{
				printf("Max die value, skipping.\n"); // DEBUG
				break;
			}
			printf("Against: %i\n", dice[j]); // DEBUG
			if (sequentialCheckStorage + 1 == dice[j])
			{
				printf("Sequence found.\n"); // DEBUG
				sequentialCounter++;
				sequentialCheckStorage++;
				j = -1; // -1 Because it will add 1 once the loop start again so it will be 0.
				printf("Sequential counter: %i\nChecking die: %i\n", sequentialCounter, sequentialCheckStorage); // DEBUG
			}
		}

		if (sequentialCounter > sequentialStorage)
		{
			sequentialStorage = sequentialCounter;
		}
		printf("Sequential storage: %i\n", sequentialStorage); // DEBUG

		sequentialCounter = 0;
	}
	printf("Largest sequence: %i\n", sequentialStorage); // DEBUG

	smallStraight = (sequentialStorage + 1 >= 4) ? 1 : 0;
	largeStraight = (sequentialStorage + 1 >= 5) ? 1 : 0;

	printf("Score array 13: %i\nYahtzee: %i\n", scoreArray[12], yahtzee); // DEBUG
	if (scoreArray[12] > 0 && yahtzee) // Checks if yahtzee bonus is aplicable
	{
		printf("Yahtzee bonus\n"); // DEBUG
		yahtzeeBonus = 1;
	}

	do // Lets the user pick a score until the user confirms score
	{
		do // Lets the user pick a score until the user picks a valid option
		{
			do // Lets the user pick a score until the user picks a valid range
			{
				printf("Scores:\n1 - Aces (%i pt)\n2 - Twos (%i pt)\n3 - Threes (%i pt)\n4 - Fours (%i pt)\n5 - Fives (%i pt)\n6 - Sixes (%i pt)\n", sumOne, sumTwo, sumThree, sumFour, sumFive, sumSix);
				printf("A - Three of a kind (%i pt)\nB - Four of a kind (%i pt)\nC - Full house (%i pt)\nD - Small straight (%i pt)\nE - Large straight (%i pt)\nF - Chance (%i pt)\nG - Yahtzee (%i pt)\nYahtzee bonus: %i\n", threeOfAKind * chance, fourOfAKind * chance, fullHouse * 25, smallStraight * 30, largeStraight * 40, chance, yahtzee * 50, yahtzeeBonus * 100);
				printf("Select a score: ");
				scanf(" %c", &userScoreInput);
				printf("Score choise: %d\n", userScoreInput); // DEBUG
				if (userScoreInput >= 65 && userScoreInput <= 71)
				{
					userScoreInput += 32;
				}
				if ((userScoreInput < 97 || userScoreInput > 103) && (userScoreInput < 49 || userScoreInput > 54))
				{
					printf("Invalid input '%c'\n", userScoreInput);
				}
			}
			while((userScoreInput < 97 || userScoreInput > 103) && (userScoreInput < 49 || userScoreInput > 54));

			switch (userScoreInput) { // Goes over all posible inputs
				case 49:
					score = sumOne;
					printf("Aces (%i pt)\n", score);
					userScoreInput = 0;
					break;
				case 50:
					score = sumTwo;
					printf("Twos (%i pt)\n", score);
					userScoreInput = 1;
					break;
				case 51:
					score = sumThree;
					printf("Threes (%i pt)\n", score);
					userScoreInput = 2;
					break;
				case 52:
					score = sumFour;
					printf("Fours (%i pt)\n", score);
					userScoreInput = 3;
					break;
				case 53:
					score = sumFive;
					printf("Fives (%i pt)\n", score);
					userScoreInput = 4;
					break;
				case 54:
					score = sumSix;
					printf("Sixes (%i pt)\n", score);
					userScoreInput = 5;
					break;
				case 97:
					score = threeOfAKind * chance;
					printf("Three of a kind (%i pt)\n", score);
					userScoreInput = 6;
					break;
				case 98:
					score = fourOfAKind * chance;
					printf("Four of a kind (%i pt)\n", score);
					userScoreInput = 7;
					break;
				case 99:
					score = fullHouse * 25;
					printf("Full house (%i pt)\n", score);
					userScoreInput = 8;
					break;
				case 100:
					score = smallStraight * 30;
					printf("Small straight (%i pt)\n", score);
					userScoreInput = 9;
					break;
				case 101:
					score = largeStraight * 40;
					printf("Large straight (%i pt)\n", score);
					userScoreInput = 10;
					break;
				case 102:
					score = chance;
					printf("Chance (%i pt)\n", score);
					userScoreInput = 11;
					break;
				case 103:
					score = yahtzee * 50;
					printf("Yahtzee (%i pt)\n", score);
					userScoreInput = 12;
					break;
				default:
					printf("Error processing score: %c\n", userScoreInput);
					exit(EXIT_FAILURE);
					break;
			}

			if (scoreArray[(int) userScoreInput] == 0)
			{
				printf("Valid input\n"); // DEBUG
				validInput = 1;
				do // Get the user confirmation
				{
					printf("Would you like to set this score (y/n)?\n");
					scanf(" %c", &confirm);

					if (confirm == 'n' && confirm == 'N')
					{
						break;
					}
					else if (confirm != 'y' && confirm != 'Y')
					{
						printf("Invalid input!\n");
					}
				}
				while ((confirm != 'y' && confirm != 'Y') && (confirm != 'n' && confirm != 'N'));
				if (confirm == 'y' || confirm == 'Y') // Sets the score in the array if the user has confirmed
				{
					if (score)
					{
						scoreArray[(int) userScoreInput] = score;
					}
					else
					{
						scoreArray[(int) userScoreInput] = -1; // If the user picks a score of 0
					}
					scoreArray[13] += 100 * yahtzeeBonus;
				}
			}
			else
			{
				printf("Invalid input\n"); // DEBUG
				printf("There is already a score here: %i\n", scoreArray[(int) userScoreInput]); // "Score already filled in"
				validInput = 0;
			}
		}
		while(!validInput);
	}
	while (confirm != 'y' && confirm != 'Y'); // If the user didn't enter y or n


	return scoreArray;
}

/*
* All the dice in the givven array are printed.
* @param: (char) dice[] the dice array
* @return: VOID
*/
void printDice(char * dice)
{
	myLog(1, __FILE__, __LINE__, 1, "Printing dice to output.");
	printf("You have the following dice:\n");
	for (int i = 0; i < DICE_PER_GAME; i++)
	{
		printf("Die[%i] = %i\n", i + 1, dice[i]);
	}
}

/*
* Rolls a set of dice.
* @param: (char) amountOfDice Amount of dice in the roll; (char) forceKeep Wether or not the player can choose what dice to keep (0, player choise; 1 Force the player to keep all of them); (char *) returnArray The array you would like to heve return it to; (char) returnArrayLength the length.
* @return: (char *) the dice array with all dice.
*/
char * rollDiceSet(char amountOfDice, char forceKeep, char * returnArray, char returnArrayLength)
{
	char tempDiceArray[amountOfDice]; // Dice list

	// myLog(1, __FILE__, __LINE__, 1, "Clearing returnArray with length: %i.", returnArrayLength);
	// for (int i = 0; i < returnArrayLength; i++) // Clearing array to prevent random values
	// {
	// 	returnArray[i] = 0;
	// }

	rollDice(amountOfDice, tempDiceArray, returnArrayLength); // Rolls x dice

	if (!forceKeep)
	{
		myLog(1, __FILE__, __LINE__, 1, "Player may choose dice.");
		selectDice(tempDiceArray, amountOfDice, 0, returnArray, amountOfDice);
	}

	return returnArray;
}

/*
* Lets the player select what dice to keep or remove from a givven array.
* @param: (char) diceArray The array of dice; (char) lengthOfDiceArray The length of the givven array; (char) clear Wether or not to clear the chosen values (0 keep, 1 clear); (char *) returnArray The array you would like to heve return it to; (char) returnArrayLength the length.
* @return: (char *) The dice array with all the dice that are left.
*/
char * selectDice(char * diceArray, char diceArrayLength, char clear, char * returnArray, char returnArrayLength)
{
	int i = 0; // Counter used in loops
	char confirm = 'x'; // y/n input from user
	int tmpDieStorage = 0; // temporary storage for the dice number
	char doubleEntryCheck = 0; // 1/0 set if q die is already in the list
	char selectDiceArray[diceArrayLength]; // Selected dice list
	char keepDie; // Used to determen wath value should be cleared from the return array
	int arrayPosCounter = 0; // Counter used when creating the output array
	char printCounter = 0; // A counter used during the printing of the array

	myLog(1, __FILE__, __LINE__, 1, "Selecting dice with clear = %i.", clear);
	myLog(1, __FILE__, __LINE__, 1, "Clearing selectDiceArray with length: %i.", diceArrayLength);
	for (int i = 0; i < diceArrayLength; i++) // Clearing array to prevent random values
	{
		selectDiceArray[i] = 0;
	}

	// myLog(1, __FILE__, __LINE__, 1, "Clearing returnArray with length: %i.", returnArrayLength);
	// for (int i = 0; i < returnArrayLength; i++) // Clearing array to prevent random values
	// {
	// 	returnArray[i] = 0;
	// }

	do // Main loop for selecting dice
	{
		printf(clear ? "Enter the number of the die you would like to return.\nEnter 0 to stop.\n" : "Enter the number of the die you would like to keep.\nEnter 0 to stop.\n");
		do // Loop for entering dice
		{
			do // Loop for entering ONE die
			{
				printf((i == diceArrayLength - 1) ? "You have %i enrty left.\n" : "You have %i entries left.\n", diceArrayLength - i);
				tmpDieStorage = getUserInput(); // A better way of getting user input
				myLog(1, __FILE__, __LINE__, 1, "Got %i from getUserInput().", tmpDieStorage);

				if (tmpDieStorage < 0 || tmpDieStorage > diceArrayLength) // Checks if the value is out of bounds (0-5)
				{
					myLog(1, __FILE__, __LINE__, 1, "Player input %i is out of bounds.", tmpDieStorage);
					printf("Input out of bounds (0 - %i)\n", diceArrayLength);
				}
				else
				{
					if (checkArrayValue(selectDiceArray, i) && tmpDieStorage > 0) // Checks if the position in the array is unused (0) & if the user didn't enter 0 to stop
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
							myLog(1, __FILE__, __LINE__, 1, "Player input %i is already picked.", tmpDieStorage);
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
							myLog(1, __FILE__, __LINE__, 1, "Player stopped input.", tmpDieStorage);
							printf("Stopping input.\n");
						}
						else // If the position in the array is usedd already
						{
							myLog(2, __FILE__, __LINE__, 1, "Position taken by: %i.", selectDiceArray[i]);
							printf("The value %i is in this position.\n", selectDiceArray[i]);
						}
					}
				}
			}
			while (selectDiceArray[i] == 0 && tmpDieStorage != 0); // There is no value in the current position of the array and the user didn't want to stop
			i++;
		}
		while (tmpDieStorage != 0 && i < diceArrayLength); // The uses want's to enter a value and is not over the limit

		printf(clear ? "Returning folowing dice:\n" : "Keeping folowing dice:\n");

		if (selectDiceArray[0])
		{
			i = 0;
			for (i = 0; i < diceArrayLength; i++)
			{
				printCounter += selectDiceArray[i] ? 1 : 0;
			}
			i = 0;
			while (selectDiceArray[i] && i < printCounter) // Loop to print kept dice
			{
				printf("Die: %i - with value: %i\n", selectDiceArray[i], diceArray[selectDiceArray[i] - 1]);
				myLog(1, __FILE__, __LINE__, 1, "Selected die. Die: %i - with value: %i", selectDiceArray[i], diceArray[selectDiceArray[i] - 1]);
				i++;
			}
			//while (selectDiceArray[i]); // Keeps going until the array is run trough or all value not 0 have been displayed
		}
		else
		{
			printf("None.\n");
			myLog(1, __FILE__, __LINE__, 1, "Selected die. None.");
		}

		do // Loop for confirming input
		{
			printf("Is this correct (y/n)? \n");
			scanf(" %c", &confirm);

			if (confirm == 'n' || confirm == 'N')
			{
				myLog(1, __FILE__, __LINE__, 1, "Resetting input.");
				i = 0;
				for (int i = 0; i < diceArrayLength; i++) // Clear the array to enter new values
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

	for (int i = 0; i < diceArrayLength; i++) // Clearing the return array of removed values
	{
		for (int j = 0; j < diceArrayLength; j++)
		{
			if ((selectDiceArray[j] - 1) == i)
			{
				myLog(1, __FILE__, __LINE__, 1, "Keeping die: %i.", i + 1);
				keepDie = clear ? 0 : 1;
			}
		}

		if (!keepDie)
		{
			myLog(1, __FILE__, __LINE__, 1, "Removing die: %i.", i + 1);
			diceArray[i] = 0;
		}

		keepDie = clear ? 1 : 0;
	}

	myLog(1, __FILE__, __LINE__, 1, "Shifting dice array.");
	for (int i = 0; i < diceArrayLength; i++) // Moving > 0 values in array to the left
	{
		myLog(1, __FILE__, __LINE__, 1, "Position: %i.", i);
		if (diceArray[i])
		{
			myLog(1, __FILE__, __LINE__, 1, "Putting value: %i at: %i.", diceArray[i], arrayPosCounter);
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
char checkArrayValue(char * array, int pos)
{
	myLog(1, __FILE__, __LINE__, 1, "Checking if array position %i is clear.", pos);
	if (!array[pos])
	{
		myLog(1, __FILE__, __LINE__, 1, "Position %i is clear.", pos);
		return 1;
	}
	myLog(1, __FILE__, __LINE__, 1, "Position %i in not clear.", pos);
	return 0;
}

/*
* Rolls a set amount of random dice.
* Returns all rolled dice.
* @param: (char) diceCount Amount of dice you would like to roll; (char *) returnArray The array you would like to heve return it to; (char) returnArrayLength the length.
* @return: (char *) An array with all dice values.
*/
char * rollDice(char diceCount, char * returnArray, char returnArrayLength)
{
	for (int i = 0; i < returnArrayLength; i++)
	{
		returnArray[i] = 0; // Filling the return array with 0's for reuse
	}

	for (int i = 0; i < diceCount; i++)
	{
		printf("Die - %i:\n", i + 1);
		returnArray[i] = rollRandomDie();
		myLog(1, __FILE__, __LINE__, 1, "Die %i = %i.", i + 1, returnArray[i]);
	}

	return returnArray;
}

/*
* Rolls a random die.
* @param: void
* @return: rollDie() (char) What die was rolled as numeric value.
*/
char rollRandomDie(void)
{
	myLog(1, __FILE__, __LINE__, 1, "Rolling a random die.");
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
			myLog(3, __FILE__, __LINE__, 1, "Failed to roll a die (%i).", n);
			exit(EXIT_FAILURE);
			break;
	}

	return die;
}

/*
* Found at https://stackoverflow.com/questions/41145908/how-to-stop-user-entering-char-as-int-input-in-c
* Credit: chux - Reinstate Monica : https://stackoverflow.com/users/2410359/chux-reinstate-monica
* Gets input from the user but only allows numbers.
* @param: VOID
* @return: int The number chosen by the user.
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
			myLog(1, __FILE__, __LINE__, 1, "Returning %i from getUserInput().", value);
			return value;
		}
		fflush(stdout);
	}
	return -1;
}
