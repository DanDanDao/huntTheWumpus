/*
 * COSC1076 Assignment 1, Semester 2 2018
 * Student name  : Quang Viet Dao
 * Student number: s3687103
 */
#ifndef HUNTWUMP_H
#define HUNTWUMP_H

#include "helpers.h"
#include "game.h"

#define STUDENT_NAME "Quang Viet Dao"
#define STUDENT_ID "s3687103"
#define STUDENT_EMAIL "s3687103@student.rmit.edu.au"
#define USER_MAX_MENU_INPUT 1
#define USER_MENU_INPUT_PARAMETER (USER_MAX_MENU_INPUT + EXTRA_SPACES)

/**
 * Main menu option 2 - show your student information as per specification.
 *
 * You should change the defines above related to student information and use
 * them when printing.
 */
void showStudentInformation();

/**
 * Print out Hunt The Wumpus Menu
 */
void displayWumpusMenu();


#endif
