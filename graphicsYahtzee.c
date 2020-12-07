/*
* This file contains all the graphics used in Yahtzee Project
*/

// Functions
void printScore(char score[]);
char dice1(char i);
char dice2(char i);
char dice3(char i);
char dice4(char i);
char dice5(char i);
char dice6(char i);
void printIntro(char maxGames, char maxRerolls);

/*
* Prints the score screen
* @param: (char) The scores to print
* @return: VOID
*/
void printScore(char score[])
{
	int scoreSum = 0;

	for (int i = 0; i < 14; i++)
	{
		if (score[i] > 0)
		{
			//printf("Score: %i + %i\n", scoreSum, score[i]); // DEBUG
			scoreSum += score[i];
		}
	}

	printf("=================================\n");
	printf("| Aces\t\t\t| %i\t|\n", score[0]);
	printf("| Twos\t\t\t| %i\t|\n", score[1]);
	printf("| Threes\t\t| %i\t|\n", score[2]);
	printf("| Fours\t\t\t| %i\t|\n", score[3]);
	printf("| Fives\t\t\t| %i\t|\n", score[4]);
	printf("| Sixes\t\t\t| %i\t|\n", score[5]);
	printf("=================================\n");
	printf("| Three of a kind\t| %i\t|\n", score[6]);
	printf("| Four of a kind\t| %i\t|\n", score[7]);
	printf("| Full house\t\t| %i\t|\n", score[8]);
	printf("| Small straight\t| %i\t|\n", score[9]);
	printf("| Large straight\t| %i\t|\n", score[10]);
	printf("| Chance\t\t| %i\t|\n", score[11]);
	printf("| Yahtzee\t\t| %i\t|\n", score[12]);
	printf("=================================\n");
	printf("| Yahtzee bonus\t\t| %i\t|\n", score[13]);
	printf("=================================\n");
	printf("| Total\t\t\t| %i\t|\n", scoreSum);
	printf("=================================\n");

	system("PAUSE");
}

/*
* All diceX have the same input and return.
* Print a die and return the value.
* @param: (char) i The numeric value of the die.
* @return: (char) n What die was rolled as numeric value.
*/
char dice1(char i)
{
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
* @param: (char) maxGames The maximum amound of games; (char) maxRerolls The maximum amount of rerells per player
* @return: VOID
*/
void printIntro(char maxGames, char maxRerolls)
{
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

printf("By:\nFelix & Leander\nBoth player get %i turns and can reroll dice %i times. Player one goes first followed by player two.\nIf you are choosing dice keep in mind that all returned dice can NOT be taken back!\nThe game will ask for confirmation on multiple points.\nInbetween player switching the current player gets to see their score sheet.\nAfter %i games are played the game will print the winner and end.\n", maxGames, maxRerolls, maxGames);
}
