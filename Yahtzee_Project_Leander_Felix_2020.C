/*
* Authors: Dumas Leander & Kremer Felix
* Date: 27/11/2020
* Description: Start code voor Yahtzee spel
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "graphics.h"

#define AANTAL_DEMO_STENEN 5

int main(void)
{
	srand(time(NULL)); // Sets the random seed
	// Debug test
	printf("Intro:\n");
	printIntro();
	printf("Dice 1 -> 6:\n");
	for(char i = 0; i < 6; i++)
	{
		rollDie(i + 1); // +1 Dice are 1 trough 6 not 0 trough 5
	}
	printf("Dice 6 random:\n");
	for(char i = 0; i < 6; i++)
	{
		rollRandomDie();
		//fflush ( stdout ); // pauses the program until keypress -DEBUG-
		//getchar(); // pauses the program until keypress -DEBUG-
	}

	exit(EXIT_SUCCESS);

	return 0;
}
