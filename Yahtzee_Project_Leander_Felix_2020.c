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
#include "game.h"

// Enum
typedef enum
{
	Intro_State,
	Name_State,
	Game_State,
	Score_State,
}
gameState;

int main(void)
{ // Put in FSM
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
	myLog(1, __FILE__, __LINE__, 0, "Opening & clearing log file success."); // -> INFO :: TIME - DATE :: File: .\Yahtzee_Project_Leander_Felix_2020.c (line: 34) :: Opening & clearing log file success.

	int playerOneScore[MAX_GAMES][MAX_ROUNDS + 1]; // Player 1 score array
	int playerTwoScore[MAX_GAMES][MAX_ROUNDS + 1]; // Player 2 score array

	int playerOneScoreRound[MAX_ROUNDS + 1];
	int playerTwoScoreRound[MAX_ROUNDS + 1];

	char playerOneName[NAME_LENGTH]; // Name of player 1
	char playerTwoName[NAME_LENGTH]; // Name of player 2

	gameState nextState = Intro_State;

	while (1) // Continues loop until user request exit on start of the game
	{
		switch (nextState)
		{
			case Intro_State:
				nextState = Name_State;
				printIntro(); // Annoying while trying to debug. Turn on before release!
				system("PAUSE");
				break;
			case Name_State:
				nextState = Game_State;
				clearCharArray(playerOneName, NAME_LENGTH, 1);
				clearCharArray(playerTwoName, NAME_LENGTH, 1);

				printf("Enter player names.\nEntering 'exit' will stop the program\nMax lenght is: %i.\n", NAME_LENGTH);
				printf("Player one.\n");
				getPlayerName(playerOneName);
				printf("Player two.\n");
				getPlayerName(playerTwoName);
				break;
			case Game_State:
				nextState = Score_State;
				myLog(1, __FILE__, __LINE__, 1, "Clearing 2 dim score arrays.");
				for (int i = 0; i < MAX_GAMES; i++) // Clear the score arrays
				{
					for (int j = 0; j < MAX_ROUNDS + 1; j++)
					{
						playerOneScore[i][j] = 0;
						playerTwoScore[i][j] = 0;
					}
				}

				for (int i = 0; i < MAX_GAMES; i++)
				{
					clearIntArray(playerOneScoreRound, MAX_ROUNDS + 1, 0);
					clearIntArray(playerTwoScoreRound, MAX_ROUNDS + 1, 0);

					myLog(1, __FILE__, __LINE__, 1, "Running game %i / %i", i + 1, MAX_GAMES);
					printf("Game: %i / %i\n", i + 1, MAX_GAMES);
					for (int j = 0; j < MAX_ROUNDS; j++)
					{
						myLog(1, __FILE__, __LINE__, 1, "Running round %i / %i", j + 1, MAX_ROUNDS);
						printf("Round: %i / %i\n", j + 1, MAX_ROUNDS);
						printf("%s's turn\n", playerOneName);
						system("PAUSE");
						playGame(playerOneScoreRound);

						printf("%s's turn\n", playerTwoName);
						system("PAUSE");
						playGame(playerTwoScoreRound);

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
				break;
			case Score_State:
				nextState = Name_State; // Skipping intro
				printScore(playerOneScore, playerOneName);
				printScore(playerTwoScore, playerTwoName);
				getWinner(playerOneScore, playerTwoScore, playerOneName, playerTwoName);
				break;
			default:
				printf("Could not determine state.\nExiting!");
				myLog(3, __FILE__, __LINE__, 1, "Could not determine state.");
				exit(EXIT_FAILURE);
				break;
		}
	}
}
