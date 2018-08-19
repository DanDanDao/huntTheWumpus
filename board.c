/*
* COSC1076 Assignment 1, Semester 2 2018
* Student name  :
* Student number:
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

void board_Load(Board board, Board boardToLoad) {
  int column;
  int row;

  for (column = 0; column < BOARD_HEIGHT; column++) {
    for (row = 0; row < BOARD_WIDTH; row++) {
        board[column][row] = boardToLoad[column][row];
    }
  }
}

Boolean board_PlacePlayer(Board board, Position position) {
  int column;
  int row;

  row = position.x;
  column = position.y;

  if ((column < 0 || column > BOARD_HEIGHT) || (row < 0 || row > BOARD_WIDTH)) {
    printf("Unable to place player – outside bounds\n\n");
    return FALSE;
  }

  if (board[column][row] == board_EMPTY) {
    board[column][row] = board_PLAYER;
    return TRUE;
  }

  return FALSE;
}


PlayerMove board_MovePlayer(Board board, Position playerPosition,
  Position nextPosition) {
    /* TODO */
    return board_PLAYER_MOVED;
  }

  ArrowHit board_FireArrow(Board board, Position position) {
    /* TODO */
    return board_ARROW_MISSED;
  }

  void board_Display(Board board) {
    /* TODO */
  }

  void board_DisplayWarnings(Board board, Position position){
    /* TODO */
  }
