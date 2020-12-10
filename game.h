#ifndef __GAME_H__
#define __GAME_H__

// Libraries
#include <string.h>

#include "graphicsYahtzee.h"

// Functions
int * playGame(int scoreArray[], char maxRerolls);
void getWinner(int playerOneArray[MAX_GAMES][MAX_ROUNDS + 1], int playerTwoArray[MAX_GAMES][MAX_ROUNDS + 1]);
int * score(char dice[], int scoreArray[]);
void printDice(char dice[]);
char * rollDiceSet(char amountOfDice, char forceKeep);
char * selectDice(char diceArray[], char lenghtOfArray, char clear);
char checkArrayValue(char scoreArray[], int pos);
char * rollDice(char diceCount);
char rollRandomDie(void);
char rollDie(char n);
int getUserInput(void);

#endif
