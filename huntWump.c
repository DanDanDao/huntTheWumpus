/*
* COSC1076 Assignment 1, Semester 2 2018
* Student name  : Quang Dao
* Student number: s3687103
*/
#include "huntWump.h"

int main()
{
  /**
  * Here's the main function. You can write the "main menu" loop/code
  * here or you can make separate functions - up to you.
  */

  /* TODO not provided */
  showMenu();
  userInput();
  printf("Good bye! \n\n");

  return EXIT_SUCCESS;
}

void showMenu() {
  printf(
    "Welcome to Hunt the Wumpus\n"
    "--------------------------\n"
    "1. Play game\n"
    "2. Show student information\n"
    "3. Quit\n\n"
  );
}

void userInput() {

  char input[INPUT_MAX_LENGTH + EXTRA_SPACES];

  while(TRUE) {
    getInput("Please enter your choice: ", input, sizeof(input));

    if (strcmp(input,"1")==0) {
      game_PlayGame();
      break;
    } else if (strcmp(input,"2")==0) {
      showStudentInformation();
    } else if (strcmp(input,"3")==0) {
      break;
    } else {
      printInvalidInput();
    }
  }
}

void showStudentInformation()
{
	printf("----------------------------------\n");
	printf("Name: %s\n", STUDENT_NAME);
	printf("No: %s\n", STUDENT_ID);
	printf("Email: %s\n", STUDENT_EMAIL);
	printf("----------------------------------\n");
	printf("\n");
}
