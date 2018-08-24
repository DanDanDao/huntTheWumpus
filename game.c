/*
* COSC1076 Assignment 1, Semester 2 2018
* Student name  : Quang Viet Dao
* Student number: s3687103
*/
#include "game.h"

void game_PlayGame(){

	Board board;

	char returnKey[USER_MAX_INPUT];
	char loadInput[MAX_LOAD_PARAMETERS];
	char initInput[MAX_INIT_PARAMETERS];
	char directionInput[MAX_PLAY_PARAMETERS];

	Player newPlayer;
	Direction moveDirection, shootDirection;
	Position playerCurrentPosition, playerNextPosition, playerRandomPosition, playerShootDirection;

	int quit = FALSE;

	displayMenu();

	getInput("Press enter to continue...", returnKey, sizeof(returnKey));

	/* If player does not quit (Player chooses to load)*/
	while (quit == FALSE) {
		char *firstChar;
		char *secondChar;
		getInput(
			"At this stage of the program, only two commands are acceptable:\n"
			"load <g>\n"
			"quit\n\n"
			"Please enter your choice: ", loadInput, sizeof(loadInput));

			firstChar = strtok(loadInput, " ");
			if (firstChar != NULL) {
				if (strcmp(firstChar, COMMAND_QUIT) == 0) {
					quit = TRUE;
					break;
				} else {
					secondChar = strtok(NULL, " ");
					if (secondChar != NULL) {
						int boardNumber = atoi(secondChar);
						if (strcmp(firstChar, COMMAND_LOAD) == 0 && (boardNumber == 1 || boardNumber == 2)) {
							chooseBoard(board, boardNumber);
							break;
						} else {
							printInvalidInput();
							continue;
						}
					} else {
						printInvalidInput();
						continue;
					}
				}
			} else {
				printInvalidInput();
				continue;
			}
		}

		/* If player does not quit (Player chooses to init)*/
		while (quit == FALSE) {
			char *firstChar;
			char *secondChar;
			getInput(
				"At this stage of the program, only two commands are acceptable:\n"
				"init <x>,<y>\n"
				"quit\n\n"
				"Please enter your choice: ", initInput, sizeof(initInput));

				firstChar = strtok(initInput, " ");
				if (firstChar != NULL) {
					if (strcmp(firstChar, COMMAND_QUIT) == 0) {
						quit = TRUE;
						break;
					} else {
						secondChar = strtok(NULL, ",");
						if (secondChar != NULL) {
							char *thirdChar = strtok(NULL, ",");
							if (thirdChar != NULL) {
								int positionX = atoi(secondChar);
								int positionY = atoi(thirdChar);
								if (strcmp(firstChar, COMMAND_INIT) == 0 && positionX < BOARD_WIDTH && positionX >= 0 && positionY <= BOARD_HEIGHT && positionY >= 0)  {
									playerCurrentPosition.x = positionX;
									playerCurrentPosition.y = positionY;
									if (board_PlacePlayer(board, playerCurrentPosition) ==	TRUE) {
										player_Initialise(&newPlayer, playerCurrentPosition);
										printf( "Player Initialized\n" );
										break;
									} else {
										printf( "Invalid Space\n\n" );
										continue;
									}
								} else {
									printInvalidInput();
									continue;
								}
							} else {
								printInvalidInput();
								continue;
							}
						} else {
							printInvalidInput();
							continue;
						}
					}
				} else {
					printInvalidInput();
					continue;
				}
			}

			/* If player does not quit (Player chooses to navigate)*/
			while (quit==FALSE) {
				char *firstChar;
				board_Display(board);
				board_DisplayWarnings(board, playerCurrentPosition);
				getInput(
					"\n\nAt this stage of the program, only three commands are acceptable:\n"
					"<directions>\n"
					"shoot <directions>\n"
					"quit\n"
					"Where <direction> is one of: north,n,south,s,east,e,west,w\n\n"
					"Please enter your choice: ", directionInput, sizeof(directionInput));

					firstChar = strtok(directionInput, " ");
					if (firstChar != NULL) {
						if (strcmp(firstChar, COMMAND_QUIT) == 0) {
							quit = TRUE;
							break;
						}
						if (setDirection(firstChar, &moveDirection)) {
							playerNextPosition = player_GetNextPosition(playerCurrentPosition, moveDirection);
							if (board_MovePlayer(board, playerCurrentPosition, playerNextPosition) == board_PLAYER_MOVED) {
								printf("Player moved.\n");
								playerCurrentPosition = playerNextPosition;
								player_UpdatePosition(&newPlayer, playerCurrentPosition);
								continue;

							/*Player moves into a bat cell*/
							} else if (board_MovePlayer(board, playerCurrentPosition, playerNextPosition) == board_BAT_CELL) {
								do {
									playerRandomPosition.x = rand() % (BOARD_HEIGHT);
									playerRandomPosition.y = rand() % (BOARD_HEIGHT);
								} while (isEmpty(board, playerRandomPosition) == FALSE);

								board[playerRandomPosition.y][playerRandomPosition.x] = board_PLAYER;
								board[playerCurrentPosition.y][playerCurrentPosition.x] = board_TRAVERSED;
								playerCurrentPosition = playerRandomPosition;
								player_UpdatePosition(&newPlayer, playerCurrentPosition);
								continue;

							} else if (board_MovePlayer(board, playerCurrentPosition, playerNextPosition) == board_OUTSIDE_BOUNDS) {
								printf("Unable to move - outside bounds.\n");
								continue;
							} else  {
								printf("Player killed!\n");
								break;
							}
						} else {
							char *secondChar = strtok(NULL, " ");
							/*Shooting an arrow*/
							if (strcmp(firstChar, COMMAND_SHOOT) == 0 && setDirection(secondChar, &shootDirection) == TRUE) {
								if (newPlayer.numArrows>0) {
									playerShootDirection = player_GetNextPosition(playerCurrentPosition, shootDirection);
									if ( board_FireArrow(board, playerShootDirection) == board_WUMPUS_KILLED) {
										printf("You killed the Wumpus!\n");
										break;
									} else if (board_FireArrow(board, playerShootDirection) == board_ARROW_MISSED){
										newPlayer.numArrows--;
										printf("Missed. You now have %d arrows.\n", newPlayer.numArrows);
										continue;
									} else {
										printf("Unable to fire arrow in that direction.\n");
										continue;
									}
								} else {
									printf("You don't have any arrows to fire.\n");
									continue;
								}
							} else {
								printInvalidInput();
								continue;
							}
						}
					} else {
						printInvalidInput();
						continue;
					}
				}
				srand(0);
			}

			/*Check if a cell is empty or not*/
			Boolean isEmpty(Board board, Position position) {
				if (board[position.y][position.x] == board_EMPTY || board[position.y][position.x] == board_TRAVERSED) {
					return TRUE;
				}	else {
					return FALSE;
				}
			}


			/*Set direction*/
			Boolean setDirection(char *userDirectionInput, Direction *tmpDirection) {
				if (strcmp(userDirectionInput, COMMAND_NORTH) == 0 || strcmp(userDirectionInput, COMMAND_NORTH_SHORTCUT) == 0) {
					*tmpDirection = player_NORTH;
					return TRUE;
				} else if (strcmp(userDirectionInput, COMMAND_SOUTH) == 0 || strcmp(userDirectionInput, COMMAND_SOUTH_SHORTCUT) == 0) {
					*tmpDirection = player_SOUTH;
					return TRUE;
				} else if (strcmp(userDirectionInput, COMMAND_EAST) == 0 || strcmp( userDirectionInput, COMMAND_EAST_SHORTCUT) == 0) {
					*tmpDirection = player_EAST;
					return TRUE;
				} else if ( strcmp(userDirectionInput, COMMAND_WEST) == 0 || strcmp( userDirectionInput, COMMAND_WEST_SHORTCUT) == 0) {
					*tmpDirection = player_WEST;
					return TRUE;
				} else {
					return FALSE;
				}
			}

			/* This function loads disired board */
			void chooseBoard(Board board, int userLoadChoice) {
				if (userLoadChoice == 1) {
					board_Load(board, BOARD_1) ;
					printf("Board 1 successfully loaded\n\n");
				} else if (userLoadChoice == 2) {
					board_Load(board, BOARD_2);
					printf("Board 2 successfully loaded\n\n");
				}
			}

			/* This function displays game menu and instruction */
			void displayMenu() {
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
			}
