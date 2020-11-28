/*
* This file contains all the graphics used in Yahtzee Project
*/

#include <time.h>

// Functions
char rollRandomDie(void);
char rollDie(char n);
char dice1(char i);
char dice2(char i);
char dice3(char i);
char dice4(char i);
char dice5(char i);
char dice6(char i);
void printIntro(void);

/*
* Rolls a random die.
* @param: void
* @return: char (die) What die was rolled as numeric value.
*/
char rollRandomDie(void)
{
	//srand(time(NULL));
	unsigned char die = (rand() % 6) + 1;

	return rollDie(die);
}

/*
* Rolls a givven die.
* @param: die (char) What die was rolled.
* @return: char (n) What die was rolled as numeric value.
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
* All diceX have the same input and return.
* Print a die and return the value.
* @param: i (char) The numeric value of the die.
* @return: char (n) What die was rolled as numeric value.
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
	printf("%i. '-------------'        \n",i);

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
	printf("%i. '-------------'        \n",i);

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
	printf("%i. '-------------'        \n",i);

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
	printf("%i. '-------------'        \n",i);

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
	printf("%i. '-------------'        \n",i);

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
	printf("%i. '-------------'        \n",i);

	return 6;
}

// End dice functions.

/*
* Prints the welcom screen, nothing more or less
* @param: void
* @return: void
*/
void printIntro(void)
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

printf("By:\nFelix & Leander\n");
}
