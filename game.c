/*
* COSC1076 Assignment 1, Semester 2 2018
* Student name  :
* Student number:
*/
#include "game.h"

void menuAfterMain() {

	char enter = "/0";

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
		"quit\n\n"
	);

	printf("Press enter to continue...");

	/* If enter is not equal to the carriage return character and the new userInput character,
	run the while loop to getChar() the enter variable. */
	while(enter != '\r' && enter != '\n')
	{
		enter = getchar();
	}
	printf("\n");
}

void game_PlayGame(){

	// char userInput[100];

	menuAfterMain();

	// if(strstr(userInput, "\n")!=NULL) {
	// 	getInput(
	// 		"At this stage of the program only two commands are acceptable:\n"
	// 		"load <g>\n"
	// 		"quit\n", userInput, sizeof(userInput));
	//
	// 		if(strcmp(userInput, "load 1")!=0) {
	// 			board_Load(BOARD_1,BOARD_1);
	// 		} else if (strcmp(userInput, "load 2")!=0) {
	// 			board_Load(BOARD_2,BOARD_2);
	// 		} else if (strcmp(userInput,"quit")!=0) {
	// 			return;
	// 		}
	// 		srand(0);
	// 	}
}
