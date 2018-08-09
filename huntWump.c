/*
* COSC1076 Assignment 1, Semester 2 2018
* Student name  : Quang Dao
* Student number: s3687103
*/
#include "huntWump.h"

void showMenu();
void userInput();
void theGame();


int main()
{
  /**
  * Here's the main function. You can write the "main menu" loop/code
  * here or you can make separate functions - up to you.
  */
  showMenu();
  userInput();

  /* TODO not provided */
  printf("Good bye! \n\n");

  return EXIT_SUCCESS;
}

void showMenu() {
  printf("Welcome to Hunt the Wumpus\n");
  printf("--------------------------\n");
  printf("1. Play game\n");
  printf("2. Show student information\n");
  printf("3. Quit\n\n");
}

void userInput() {

  char input[INPUT_MAX_LENGTH + EXTRA_SPACES];

  while(TRUE) {
    getInput("Please enter your choice", input, sizeof(input));

    if (input == 1) {
      theGame();
    } else if (input == 2) {
      showStudentInformation();
    } else if (input == 3) {
      break;
    } else {
      printf("Invalid Input!\n");
    }
  }
}

void showStudentInformation() {
  printf("----------------------------------\n");
  printf("Name: Quang Dao\n");
  printf("Student ID: s3687103\n");
  printf("Email: s3687103@student.rmit.edu.au\n");
  printf("----------------------------------\n");
  /* TODO not provided */
}

void theGame() {
  printf("Press return to continue...\n");
  /* TODO not provided */
}
