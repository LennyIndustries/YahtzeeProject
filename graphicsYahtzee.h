#ifndef __GRAPHICSYAHTZEE_H__
#define __GRAPHICSYAHTZEE_H__

// Libraries
#include <stdlib.h>

#include "myLog.h"


// Definitions
#define MAX_GAMES 5 // Maximum of games played.
#define MAX_ROUNDS 13 // Maximum amound of rounds played per player.
#define MAX_REROLLS 2 // Maximum amount of times you can reroll dice. Fill in ONE LESS then the total amount of rerolls!
#define DICE_PER_GAME 5 // Total dice in the game

// Functions
void printScore(int score[MAX_GAMES][MAX_ROUNDS + 1], char * playerName);
char dice1(char i);
char dice2(char i);
char dice3(char i);
char dice4(char i);
char dice5(char i);
char dice6(char i);
void printIntro(void);

#endif
