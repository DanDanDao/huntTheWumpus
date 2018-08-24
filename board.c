/*
* COSC1076 Assignment 1, Semester 2 2018
* Student name  : Quang Viet Dao
* Student number: s3687103
*/
#include "board.h"

Board BOARD_1 =
{
  { board_EMPTY,  board_EMPTY,  board_EMPTY,  board_PIT,    board_EMPTY},
  { board_EMPTY,  board_EMPTY,  board_EMPTY,  board_EMPTY,  board_EMPTY},
  { board_BATS,   board_EMPTY,  board_EMPTY,  board_WUMPUS, board_EMPTY},
  { board_EMPTY,  board_PIT,    board_EMPTY,  board_EMPTY,  board_EMPTY},
  { board_EMPTY,  board_EMPTY,  board_BATS,   board_EMPTY,  board_EMPTY}
};

Board BOARD_2 =
{
  { board_PIT,    board_EMPTY,  board_PIT,    board_EMPTY,  board_EMPTY},
  { board_EMPTY,  board_EMPTY,  board_EMPTY,  board_EMPTY,  board_EMPTY},
  { board_EMPTY,  board_EMPTY,  board_BATS,   board_EMPTY,  board_EMPTY},
  { board_EMPTY,  board_EMPTY,  board_EMPTY,  board_EMPTY,  board_BATS },
  { board_EMPTY,  board_WUMPUS, board_EMPTY,  board_EMPTY,  board_EMPTY},
};

/* This function is to load board if the boardToLoad is equal
to either BOARD_1 or BOARD_2, load the desired board */
void board_Load(Board board, Board boardToLoad) {
  int row, column;
  for (row = 0; row < BOARD_WIDTH; row++) {
    for (column = 0; column < BOARD_HEIGHT; column++) {
      board[row][column] = boardToLoad[row][column];
    }
  }
}

/* This function is to place player in cell, the function will check the
position to place player, return true and place player in desired cell if it is valid,
return false if it is not valid*/
Boolean board_PlacePlayer(Board board, Position position) {
  if (board[position.y][position.x] == board_EMPTY) {
    board[position.y][position.x] = board_PLAYER;
    return TRUE;
  }
  else
  return FALSE;
}

PlayerMove board_MovePlayer(Board board, Position playerPosition, Position nextPosition) {
  if (board[nextPosition.y][nextPosition.x] == board_PIT || board[nextPosition.y][nextPosition.x] == board_WUMPUS) {
    return board_PLAYER_KILLED;
  } else if (nextPosition.y >= BOARD_HEIGHT || nextPosition.x >= BOARD_WIDTH || nextPosition.x < 0 || nextPosition.y < 0) {
    return board_OUTSIDE_BOUNDS;
  } else if (board[nextPosition.y][nextPosition.x] == board_EMPTY || board[nextPosition.y][nextPosition.x] == board_TRAVERSED ) {
    board[nextPosition.y][nextPosition.x] = board_PLAYER;
    board[playerPosition.y][playerPosition.x] = board_TRAVERSED;
    return board_PLAYER_MOVED;
  } else {
    return board_BAT_CELL;
  }
}

/* This function will shoot arraw into a cell and return board_ARROW_MISSED if there is no wumpus
in the cell or return board_WUMPUS_KILLED if there is a wumpus*/
ArrowHit board_FireArrow(Board board, Position position) {
  if (position.y >= BOARD_HEIGHT || position.x >= BOARD_WIDTH || position.x < 0 || position.y < 0) {
    return board_ARROW_OUTSIDE_BOUNDS;
  } else if (board[position.y][position.x] == board_WUMPUS) {
    return board_WUMPUS_KILLED;
  } else {
    return board_ARROW_MISSED;
  }
}

/* This function displays the board and the player's position.
It will print in a way if the cell is EMPTY is will print an PLAYER_OUTPUT,
else if the cell is TRAVERSED it will print a TRAVERSED_OUTPUT.*/
void board_Display(Board board) {
  int column, row;
  printf("\n\n   0  1  2  3  4  \n");
  for (row = 0; row < BOARD_WIDTH; row++) {
    printf("  ----------------\n");
    printf("%d ", row);
    for (column = 0; column < BOARD_HEIGHT; column++) {
      if (board[row][column] == board_PLAYER) {
        printf("|%s", PLAYER_OUTPUT);
      } else if ( board[row][column] == board_TRAVERSED) {
        printf("|%s", TRAVERSED_OUTPUT);
      } else {
        printf("|%s", EMPTY_OUTPUT);
      }
    }
    printf("|\n");
  }
  printf("  ----------------\n");
}

/* This function displays warnings.*/
void board_DisplayWarnings(Board board, Position position) {
  int x;
  int y;
  char *warnings[] = {"You hear flapping!", "You feel a breeze!", "You smell a wumpus!"};

  for (x = position.x-1; x >= 0 && x <= position.x+1 && x < BOARD_WIDTH; x++) {
    for (y = position.y-1; y >= 0 && y <= position.y+1 && y < BOARD_HEIGHT; y++) {
      int index = 2;
      do {
        if (board[y][x] == index) {
          printf("%s ", warnings[index-2]);
        }
        index++;
      } while (index<5);
    }
  }
}
