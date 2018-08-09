/*
 * COSC1076 Assignment 1, Semester 2 2018
 * Student name  :
 * Student number:
 */
#ifndef HUNTWUMP_H
#define HUNTWUMP_H

#include "helpers.h"
#include "game.h"

#define STUDENT_NAME "Quang Viet Dao"
#define STUDENT_ID "s3687103"
#define STUDENT_EMAIL "s3687103@student.rmit.edu.au"

#define INPUT_MAX_LENGTH 1
#define NEW_LINE_SPACE 1
#define NULL_SPACE 1
#define EXTRA_SPACES (NEW_LINE_SPACE + NULL_SPACE)

/**
 * Main menu option 2 - show your student information as per specification.
 *
 * You should change the defines above related to student information and use
 * them when printing.
 */
void showStudentInformation();
void showMenu();
void userInput();


#endif
