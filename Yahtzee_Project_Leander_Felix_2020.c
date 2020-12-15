/*
* Authors: Dumas Leander & Kremer Felix
* Date: 27/11/2020
* Description: Main file to play Yahtzee
*/

// gcc -Wall -pedantic -c .\myLog.c -o .\myLog.o
// gcc -Wall -pedantic -c .\graphicsYahtzee.c -o .\graphicsYahtzee.o
// gcc -Wall -pedantic -c .\game.c -o .\game.o
// gcc -Wall -pedantic .\Yahtzee_Project_Leander_Felix_2020.c .\graphicsYahtzee.o .\game.o .\myLog.o -o test.exe

// Libraries
#include <string.h>
#include <ctype.h>

#include "game.h"
//#include "graphicsYahtzee.h"

int main(void)
{
	srand(time(NULL)); // Initialize randomness

	/*
	* Use this to log lines to the output log.
	* void myLog(char logLevel, char * file, int line, char append, const char * message, ...)
	* logLevel:
	*		- 1 : INFO : Just normal log info.
	*		- 2 : WARN : Warning that did not terminate the program but should not happen.
	*		- 3 : CRIT : Critical warning that terminates the program.
	* file: from what file the message is. You can use __FILE__
	* line: from what line the message is. You can use __LINE__
	* append: Wether to append (1) or not (0). If you do not append it will clear to file.
	* message: A log message you would like to put in the log.
	* Output.log example line
	* logLevel :: hh:mm:ss - dd/mm/yyyy :: File: FILE_LOCATION (line: LINE IN CODE) :: message
	* message can be used like printf(), ... "This is a number: %i", 1); will put "This is a number: 1" as message in the log file.
	*/
	myLog(1, __FILE__, __LINE__, 0, "Opening & clearing log file success."); // -> INFO :: TIME - DATE :: File: .\Yahtzee_Project_Leander_Felix_2020.c (line: 38) :: Opening & clearing log file success.

	int playerOneScore[MAX_GAMES][MAX_ROUNDS + 1]; // Player 1 score array
	int playerTwoScore[MAX_GAMES][MAX_ROUNDS + 1]; // Player 2 score array

	int playerOneScoreRound[MAX_ROUNDS + 1];
	int playerTwoScoreRound[MAX_ROUNDS + 1];

	int * playerOneDicePointer; // Pointer to player 1's dice array
	int * playerTwoDicePointer; // Pointer to player 2's dice array

	char playerOneName[50]; // Name of player 1
	char playerTwoName[50]; // Name of player 2
	char playerOneLowerName[50]; // Name of player 1
	char playerTwoLowerName[50]; // Name of player 2

	printIntro(); // Annoying while trying to debug. Turn on before release!
	system("PAUSE");

	while (1) // Continues loop until user request exit on start of the game
	{
		myLog(1, __FILE__, __LINE__, 1, "Clearing name strings.");
		for (int i = 0; i < 50; i++) // Clearing player name strings
		{
			playerOneName[i] = '\0';
			playerTwoName[i] = '\0';
			playerOneLowerName[i] = '\0';
			playerTwoLowerName[i] = '\0';
		}

		printf("Enter player names.\nEntering 'exit' will stop the program\n");
		do // Getting player one's name
		{
			printf("Player one name: ");
			gets(playerOneName);
		}
		while(!strcmp(playerOneName, ""));
		myLog(1, __FILE__, __LINE__, 1, "Name player one: %s", playerOneName);
		for(int i = 0; playerOneName[i]; i++)
		{
			playerOneLowerName[i] = tolower(playerOneName[i]);
		}
		if (!strcmp(playerOneLowerName, "exit"))
		{
			printf("Exiting on user request.\n");
			myLog(1, __FILE__, __LINE__, 1, "Program terminated on player one's request.");
			exit(EXIT_SUCCESS);
		}

		do // Getting player two's name
		{
			printf("Player two name: ");
			gets(playerTwoName);
		}
		while(!strcmp(playerTwoName, ""));
		myLog(1, __FILE__, __LINE__, 1, "Name player two: %s", playerTwoName);
		for(int i = 0; playerTwoName[i]; i++)
		{
			playerTwoLowerName[i] = tolower(playerTwoName[i]);
		}
		if (!strcmp(playerTwoLowerName, "exit"))
		{
			printf("Exiting on user request.\n");
			myLog(1, __FILE__, __LINE__, 1, "Program terminated on player two's request.");
			exit(EXIT_SUCCESS);
		}

		myLog(1, __FILE__, __LINE__, 1, "Clearing score arrays.");
		for (int i = 0; i < MAX_GAMES; i++) // Clear the score arrays
		{
			for (int j = 0; j < MAX_ROUNDS + 1; j++)
			{
				playerOneScore[i][j] = 0;
				playerTwoScore[i][j] = 0;
			}
		}

		myLog(1, __FILE__, __LINE__, 1, "Clearing round score arrays with length: %i.", MAX_ROUNDS);
		for (int i = 0; i < MAX_ROUNDS + 1; i++) // Clear the round score arrays
		{
			playerOneScoreRound[i] = 0;
			playerTwoScoreRound[i] = 0;
		}

		for (int i = 0; i < MAX_GAMES; i++)
		{
			myLog(1, __FILE__, __LINE__, 1, "Running game %i / %i", i + 1, MAX_GAMES);
			printf("Game: %i / %i\n", i + 1, MAX_GAMES);
			for (int j = 0; j < MAX_ROUNDS; j++)
			{
				myLog(1, __FILE__, __LINE__, 1, "Running round %i / %i", j + 1, MAX_ROUNDS);
				printf("Round: %i / %i\n", j + 1, MAX_ROUNDS);
				printf("%s's turn\n", playerOneName);
				system("PAUSE");
				playerOneDicePointer = playGame(playerOneScoreRound);
				for (int k = 0; k < MAX_ROUNDS + 1; k++)
				{
					playerOneScoreRound[k] = * (playerOneDicePointer + k);
					myLog(1, __FILE__, __LINE__, 1, "Score %i = %i", k, playerOneScoreRound[k]);
				}

				printf("%s's turn\n", playerTwoName);
				system("PAUSE");
				playerTwoDicePointer = playGame(playerTwoScoreRound);
				for (int k = 0; k < MAX_ROUNDS + 1 + 1; k++)
				{
					playerTwoScoreRound[k] = * (playerTwoDicePointer + k);
					myLog(1, __FILE__, __LINE__, 1, "Score %i = %i", k, playerTwoScoreRound[k]);
				}

				for (int k = 0; k < MAX_ROUNDS + 1; k++)
				{
					playerOneScore[i][k] = playerOneScoreRound[k];
					playerTwoScore[i][k] = playerTwoScoreRound[k];
				}

				printScore(playerOneScore, playerOneName);
				printScore(playerTwoScore, playerTwoName);
				system("PAUSE");
			}
		}

		printScore(playerOneScore, playerOneName);
		printScore(playerTwoScore, playerTwoName);
		getWinner(playerOneScore, playerTwoScore, playerOneName, playerTwoName);
	}
}
