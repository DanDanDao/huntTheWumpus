/*
 * COSC1076 Assignment 1, Semester 2 2018
 * Student name  :
 * Student number:
 */
#include "helpers.h"

void readRestOfLine()
{
	int ch;
	while(ch = getc(stdin), ch != EOF && ch != '\n')
	{ } /* Gobble each character. */

	/* Reset the error status of the stream. */
	clearerr(stdin);
}

typedef enum
{
    false = 0, true = 1
} bool;

#define INPUT_MAX_LENGTH 1
#define NEW_LINE_SPACE 1
#define NULL_SPACE 1
#define EXTRA_SPACES (NEW_LINE_SPACE + NULL_SPACE)

void input()
{
    /* char input[80 + 2]; */
    char input[INPUT_MAX_LENGTH + EXTRA_SPACES];

    while(true)
    {
        printf("Enter input up to %d characters: ", INPUT_MAX_LENGTH);

        fgets(input, sizeof(input), stdin);
        if(input[strlen(input) - 1] != '\n')
        {
            printf("Input was too long, try again. \n\n");
            readRestOfLine();
            continue;
        }
        /**
         * You can strip off the new line at the end of the string here if you want.
         * Typically you do because most of the time you don't want the \n to be processed.
         */
        input[strlen(input) - 1] = '\0';

        break;
    }
    printf("Your input was '%s' \n", input);
    printf("\n");
}

ReadInputResult readInput(char * str, int num, FILE * stream)
{
	char * result;

	result = fgets(str, num, stream);
	if(result == NULL)
	{
		return ReadInputResultNull;
	}
	else if(str[strlen(str) - 1] != '\n')
	{
		readRestOfLine();
		return ReadInputResultOverflow;
	}
	else
	{
		str[strlen(str) - 1] = '\0';
		return ReadInputResultSuccess;
	}
}

ReadInputResult getInput(char * prompt, char * input, int inputSize)
{
	ReadInputResult readInputResult;

	while(TRUE)
	{
		printf("%s", prompt);
		readInputResult = readInput(input, inputSize, stdin);
		printf("\n");

		if(readInputResult != ReadInputResultSuccess)
		{
			printInvalidInput();
			continue;
		}

		return readInputResult;
	}
}

void printInvalidInput()
{
	printf("Invalid input. \n\n");
}

void enableWindowsCompatibility()
{
	/* Disable buffering on stdout - this is typically an issue on Windows. */
	setbuf(stdout, NULL);

	/* Disable buffering on stderr just in case. */
	setbuf(stderr, NULL);
}
