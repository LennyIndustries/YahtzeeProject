/*
* This file contains all the graphics used in Yahtzee Project.
*/

// Libraries
#include "graphicsYahtzee.h"

/*
* Prints the score screen
* @param: (char) score The scores to print; (char *) playerName The name of the player.
* @return: VOID
*/
void printScore(int score[MAX_GAMES][MAX_ROUNDS + 1], char * playerName)
{
	int scoreSumOne = 0;
	int scoreSumTwo = 0;
	int scoreSumThree = 0;
	int scoreSumFour = 0;
	int scoreSumFive = 0;
	int scoreSumTotal = 0;

	printf("%s's score\n", playerName);

	for (int i = 0; i < MAX_GAMES; i++)
	{
		printf("I = %i\n", i); // DEBUG
		for (int j = 0; j < MAX_ROUNDS + 1; j++)
		{
			printf("J = %i\n", j); // DEBUG
			if (score[i][j] > 0)
			{
				printf("Score over 0: %i\n", score[i][j]); // DEBUG
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
						myLog(3, __FILE__, __LINE__, 1, "Could not find score: overflow.");
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

	myLog(1, __FILE__, __LINE__, 1, "Total score for %s: %i.", playerName, scoreSumTotal);
}

/*
* All diceX have the same input and return.
* Print a die and return the value.
* @param: (char) i The numeric value of the die.
* @return: (char) n What die was rolled as numeric value.
*/
char dice1(char i)
{
	myLog(1, __FILE__, __LINE__, 1, "Printing die %i.", i);
	printf("      .-------------.    \n");
	printf("     /             /|    \n");
	printf("    /      o      / |    \n");
	printf("   /_____________/  |    \n");
	printf("   |             |  |    \n");
	printf("   |             |  |    \n");
	printf("   |             |  /     \n");
	printf("   |             | /     \n");
	printf("   |             |/       \n");
	printf("%i. '-------------'        \n\n",i);

	return 1;
}

char dice2(char i)
{
	myLog(1, __FILE__, __LINE__, 1, "Printing die %i.", i);
	printf("      .-------------.    \n");
	printf("     /  o          /|    \n");
	printf("    /             / |    \n");
	printf("   /__________o__/  |    \n");
	printf("   |             |  |    \n");
	printf("   |             |  |    \n");
	printf("   |             |  /     \n");
	printf("   |             | /     \n");
	printf("   |             |/       \n");
	printf("%i. '-------------'        \n\n",i);

	return 2;
}

char dice3(char i)
{
	myLog(1, __FILE__, __LINE__, 1, "Printing die %i.", i);
	printf("      .-------------.    \n");
	printf("     /  o          /|    \n");
	printf("    /      o      / |    \n");
	printf("   /___________o_/  |    \n");
	printf("   |             |  |    \n");
	printf("   |             |  |    \n");
	printf("   |             |  /     \n");
	printf("   |             | /     \n");
	printf("   |             |/       \n");
	printf("%i. '-------------'        \n\n",i);

	return 3;
}

char dice4(char i)
{
	myLog(1, __FILE__, __LINE__, 1, "Printing die %i.", i);
	printf("      .-------------.    \n");
	printf("     /  o       o  /|    \n");
	printf("    /             / |    \n");
	printf("   /__o________o_/  |    \n");
	printf("   |             |  |    \n");
	printf("   |             |  |    \n");
	printf("   |             |  /     \n");
	printf("   |             | /     \n");
	printf("   |             |/       \n");
	printf("%i. '-------------'        \n\n",i);

	return 4;
}

char dice5(char i)
{
	myLog(1, __FILE__, __LINE__, 1, "Printing die %i.", i);
	printf("      .-------------.    \n");
	printf("     /  o       o  /|    \n");
	printf("    /      o      / |    \n");
	printf("   /__o_______o__/  |    \n");
	printf("   |             |  |    \n");
	printf("   |             |  |    \n");
	printf("   |             |  /     \n");
	printf("   |             | /     \n");
	printf("   |             |/       \n");
	printf("%i. '-------------'        \n\n",i);

	return 5;
}

char dice6(char i)
{
	myLog(1, __FILE__, __LINE__, 1, "Printing die %i.", i);
	printf("      .-------------.    \n");
	printf("     /  o       o  /|    \n");
	printf("    /  o       o  / |    \n");
	printf("   /__o_______o__/  |    \n");
	printf("   |             |  |    \n");
	printf("   |             |  |    \n");
	printf("   |             |  /     \n");
	printf("   |             | /     \n");
	printf("   |             |/       \n");
	printf("%i. '-------------'        \n\n",i);

	return 6;
}

// End dice functions.

/*
* Prints the welcom screen, nothing more or less
* @param: VOID
* @return: VOID
*/
void printIntro(void)
{
	myLog(1, __FILE__, __LINE__, 1, "Printing intro.");
	printf(" .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.   \n");
	printf("| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |  \n");
	printf("| | _____  _____ | || |  _________   | || |   _____      | || |     ______   | || |     ____     | || | ____    ____ | || |  _________   | |  \n");
	printf("| ||_   _||_   _|| || | |_   ___  |  | || |  |_   _|     | || |   .' ___  |  | || |   .'    `.   | || ||_   \\  /   _|| || | |_   ___  |  | |  \n");
	printf("| |  | | /\\ | |  | || |   | |_  \\_|  | || |    | |       | || |  / .'   \\_|  | || |  /  .--.  \\  | || |  |   \\/   |  | || |   | |_  \\_|  | |  \n");
	printf("| |  | |/  \\| |  | || |   |  _|  _   | || |    | |   _   | || |  | |         | || |  | |    | |  | || |  | |\\  /| |  | || |   |  _|  _   | |  \n");
	printf("| |  |   /\\   |  | || |  _| |___/ |  | || |   _| |__/ |  | || |  \\ `.___.'\\  | || |  \\  `--'  /  | || | _| |_\\/_| |_ | || |  _| |___/ |  | |  \n");
	printf("| |  |__/  \\__|  | || | |_________|  | || |  |________|  | || |   `._____.'  | || |   `.____.'   | || ||_____||_____|| || | |_________|  | |  \n");
	printf("| |              | || |              | || |              | || |              | || |              | || |              | || |              | |  \n");
	printf("| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |  \n");
	printf(" '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'   \n");
	printf(" .----------------.  .----------------.                                                                                                       \n");
	printf("| .--------------. || .--------------. |                                                                                                      \n");
	printf("| |  _________   | || |     ____     | |                                                                                                      \n");
	printf("| | |  _   _  |  | || |   .'    `.   | |                                                                                                      \n");
	printf("| | |_/ | | \\_|  | || |  /  .--.  \\  | |                                                                                                      \n");
	printf("| |     | |      | || |  | |    | |  | |                                                                                                      \n");
	printf("| |    _| |_     | || |  \\  `--'  /  | |                                                                                                      \n");
	printf("| |   |_____|    | || |   `.____.'   | |                                                                                                      \n");
	printf("| |              | || |              | |                                                                                                      \n");
	printf("| '--------------' || '--------------' |                                                                                                      \n");
	printf(" '----------------'  '----------------'                                                                                                       \n");
	printf(" .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.   \n");
	printf("| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |  \n");
	printf("| |  ____  ____  | || |      __      | || |  ____  ____  | || |  _________   | || |   ________   | || |  _________   | || |  _________   | |  \n");
	printf("| | |_  _||_  _| | || |     /  \\     | || | |_   ||   _| | || | |  _   _  |  | || |  |  __   _|  | || | |_   ___  |  | || | |_   ___  |  | |  \n");
	printf("| |   \\ \\  / /   | || |    / /\\ \\    | || |   | |__| |   | || | |_/ | | \\_|  | || |  |_/  / /    | || |   | |_  \\_|  | || |   | |_  \\_|  | |  \n");
	printf("| |    \\ \\/ /    | || |   / ____ \\   | || |   |  __  |   | || |     | |      | || |     .'.' _   | || |   |  _|  _   | || |   |  _|  _   | |  \n");
	printf("| |    _|  |_    | || | _/ /    \\ \\_ | || |  _| |  | |_  | || |    _| |_     | || |   _/ /__/ |  | || |  _| |___/ |  | || |  _| |___/ |  | |  \n");
	printf("| |   |______|   | || ||____|  |____|| || | |____||____| | || |   |_____|    | || |  |________|  | || | |_________|  | || | |_________|  | |  \n");
	printf("| |              | || |              | || |              | || |              | || |              | || |              | || |              | |  \n");
	printf("| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |  \n");
	printf(" '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'   \n");

	printf("By:\nFelix & Leander\nBoth player get %i turns and can reroll dice %i times. Player one goes first followed by player two.\nIf you are choosing dice keep in mind that all returned dice can NOT be taken back!\nThe game will ask for confirmation on multiple points.\nA game has %i dice\nAfter one round both players can see their score sheet.\nAfter %i rounds are played the game will print the winner and end.\n", MAX_ROUNDS, MAX_REROLLS, DICE_PER_GAME, MAX_GAMES);
}
