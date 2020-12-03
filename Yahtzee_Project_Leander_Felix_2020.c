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
#include "game.h"
//#include "yahtzee.h"

// Declarations
//#define AANTAL_DEMO_STENEN 5
//#define DICE_PER_GAME 5
//#define MAX_GAMES 5 // Maximum amound of rounds played per player.
//#define MAX_REROLLS 2 // Maximum amount of times you can reroll dice.

// Functions
/*char checkArrayValue(char scoreArray[], int pos);
char * rollDice(char diceCount);*/

int main(void)
{
	srand(time(NULL)); // Sets the random seed

	//char scorePlayerOne[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // Player 1 score array
	//char scorePlayerTwo[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // Player 2 score array

	//char * playerOneDicePointer; // Pointer to plqyer 1's dice array
	//char * playerTwoDicePointer; // Pointer to plqyer 2's dice array

	//char playerOneDice[DICE_PER_GAME];
	//char playerTwoDice[DICE_PER_GAME];

	//char die1, die2, die3, die4, die5;
	//char diceArray[] = {0, 0, 0, 0, 0};
	//char diceToKeep = 0;

	// Variables used in the loops to enter what dice to keep
	// char confirm = 'x';
	// int i = 0;
	// int tmpDieStorage = 0;
	// int doubleEntryCheck = 0;

	//printIntro(); // Annoying while trying to debug
	playGame();

	exit(EXIT_SUCCESS);

	return 0;
}
