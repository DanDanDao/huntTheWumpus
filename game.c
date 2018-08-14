/*
* COSC1076 Assignment 1, Semester 2 2018
* Student name  :
* Student number:
*/
#include "game.h"

void game_PlayGame(){

	printf(
		"You can use the following commands to play the game:\n"
		" load <g>\n"
		"g: number of the game board to load (either 1 or 2)\n"
		"init <x>,<y>\n"
		" x: horizontal position of the player on the board (between 0 & 4)\n"
		" y: vertical position of the player on the board (between 0 & 4)\n"
		"north (or n)\n"
		"south (or s)\n"
		"east (or e)\n"
		"west (or w)\n"
		"quit\n"
	);

	char userInput[INPUT_MAX_LENGTH + EXTRA_SPACES];

	getInput("Press return to continue...\n", userInput, sizeof(userInput));
	
	if(strstr(userInput, "\n")!=NULL) {
		getInput(
			"At this stage of the program only two commands are acceptable:\n"
			"load <g>\n"
			"quit\n", userInput, sizeof(userInput));
			if(strcmp(userInput, "load 1")!=NULL || strcmp(userInput, "load 2")!=NULL) {
				board_Load(BOARD_1,BOARD_1);
			} else if (strcmp(userInput,"quit")!=NULL) {
				return;
			}
			srand(0);
		}
	}
