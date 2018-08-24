/*
* COSC1076 Assignment 1, Semester 2 2018
* Student name  : Quang Viet Dao
* Student number: s3687103
*/
#include "player.h"

/* This function references the player struct in player.h, it gets the member
of position, and arrows that player currently retains. */
void player_Initialise(Player * player, Position position) {
  player -> position = position;
  player -> numArrows = INIT_ARROW_COUNT;
}

/* This function obtains the next position that the player will move forward to.*/
Position player_GetNextPosition(Position position, Direction direction) {
  switch (direction) {
    case 0:
    position.y--;
    break;
    case 1:
    position.x++;
    break;
    case 2:
    position.y++;
    break;
    case 3:
    position.x--;
    break;
    default:
    break;
  }
  return position;
}

/* This function updates the player's position and keeps track of the current
moves the player has made if they have successfully moved forward. */
void player_UpdatePosition(Player * player, Position position) {
  player -> position = position;
}
