#ifndef __GAME_H__
#define __GAME_H__

// Libraries
#include "graphicsYahtzee.h"

// Functions
int * playGame(int * scoreArray);
void getWinner(int playerOneArray[MAX_GAMES][MAX_ROUNDS + 1], int playerTwoArray[MAX_GAMES][MAX_ROUNDS + 1], char * playerOneName, char * playerTwoName);
int * score(char * dice, int * scoreArray);
void printDice(char dice[]);
char * rollDiceSet(char amountOfDice, char forceKeep, char * returnArray, char returnArrayLength);
char * selectDice(char * diceArray, char diceArrayLength, char clear, char * returnArray, char returnArrayLength);
char checkArrayValue(char * scoreArray, int pos);
char * rollDice(char diceCount, char * returnArray);
char rollRandomDie(void);
char rollDie(char n);
int getUserInput(void);

#endif
