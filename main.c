/*
* [Pas deze hoofding aan]
* Authors: Vreys Frederik & Gilissen Koen
* Date: 24/10/2019
* Description: Start code voor blackjack spel
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define AANTAL_DEMO_STENEN 5

int showDie(char i);
int dice1(char i);
int dice2(char i);
int dice3(char i);
int dice4(char i);
int dice5(char i);
int dice6(char i);
int throwDie();
void printIntro(void);

int main(void)
{
	srand(time(NULL));

	//DEMO Code voor testen van kaarten
        printIntro();
	for(char i = 0; i < AANTAL_DEMO_STENEN; i++)
	{
		showDie(i+65);
	}

}

int showDie(char i)
{
        int die = throwDie();
        int eyes = 0;
        switch (die)
        {
			case 1:
					eyes = dice1(i);
					break;
			case 2:
					eyes = dice2(i);
					break;
			case 3:
					eyes = dice3(i);
					break;
			case 4:
					eyes = dice4(i);
					break;
			case 5:
					eyes = dice5(i);
					break;
			case 6:
					eyes = dice6(i);
					break;
			default:
					eyes = 0;
					printf("Die off the tabel! Try again!");
					break;
        }
        return eyes;
}

int throwDie()
{
        int getal = (rand() % 6) +1;
        return getal;
}


int dice1(char i)
{
        int a=0;
        printf("      .-------------.    \n");
		printf("     /             /|    \n");
		printf("    /      o      / |    \n");
		printf("   /_____________/  |    \n");
		printf("   |             |  |    \n");
		printf("   |             |  |    \n");
		printf("   |             |  /     \n");
		printf("   |             | /     \n");
		printf("   |             |/       \n");
		printf("%c. '-------------'        \n",i);
        return a;
}

int dice2(char i)
{
        int a=2;
        printf("      .-------------.    \n");
		printf("     /  o          /|    \n");
		printf("    /             / |    \n");
		printf("   /__________o__/  |    \n");
		printf("   |             |  |    \n");
		printf("   |             |  |    \n");
		printf("   |             |  /     \n");
		printf("   |             | /     \n");
		printf("   |             |/       \n");
		printf("%c. '-------------'        \n",i);
        return a;
}

int dice3(char i)
{
        int a=3;
        printf("      .-------------.    \n");
		printf("     /  o          /|    \n");
		printf("    /      o      / |    \n");
		printf("   /___________o_/  |    \n");
		printf("   |             |  |    \n");
		printf("   |             |  |    \n");
		printf("   |             |  /     \n");
		printf("   |             | /     \n");
		printf("   |             |/       \n");
		printf("%c. '-------------'        \n",i);
        return a;
}

int dice4(char i)
{
        int a=4;
        printf("      .-------------.    \n");
		printf("     /  o       o  /|    \n");
		printf("    /             / |    \n");
		printf("   /__o________o_/  |    \n");
		printf("   |             |  |    \n");
		printf("   |             |  |    \n");
		printf("   |             |  /     \n");
		printf("   |             | /     \n");
		printf("   |             |/       \n");
		printf("%c. '-------------'        \n",i);
        return a;
}

int dice5(char i)
{
        int a=5;
        printf("      .-------------.    \n");
		printf("     /  o       o  /|    \n");
		printf("    /      o      / |    \n");
		printf("   /__o_______o__/  |    \n");
		printf("   |             |  |    \n");
		printf("   |             |  |    \n");
		printf("   |             |  /     \n");
		printf("   |             | /     \n");
		printf("   |             |/       \n");
		printf("%c. '-------------'        \n",i);
        return a;
}

int dice6(char i)
{
        int a=6;
        printf("      .-------------.    \n");
		printf("     /  o       o  /|    \n");
		printf("    /  o       o  / |    \n");
		printf("   /__o_______o__/  |    \n");
		printf("   |             |  |    \n");
		printf("   |             |  |    \n");
		printf("   |             |  /     \n");
		printf("   |             | /     \n");
		printf("   |             |/       \n");
		printf("%c. '-------------'        \n",i);
        return a;
}

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


printf("<< Uitleg voeg je hier toe>>\n");
}
