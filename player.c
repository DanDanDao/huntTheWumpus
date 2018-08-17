/*
 * COSC1076 Assignment 1, Semester 2 2018
 * Student name  :
 * Student number:
 */
#include "player.h"

void player_Initialise(Player * player, Position position){
  player -> position = position;
  player -> numArrows = 5;
}


Position player_GetNextPosition(Position position, Direction direction){

  Position positon;

  positon = direction -> positon;

  if (player -> direction == player_NORTH) {
    positon.y--;
  } else if (player -> direction == player_EAST) {
    positon.x++;
  } else if (player -> direction == player_SOUTH) {
    positon.y++;
  } else if (player -> direction == player_WEST) {
    positon.x--;
  }
   return position;
}

void player_UpdatePosition(Player * player, Position position) {
  player -> position = position;
}
