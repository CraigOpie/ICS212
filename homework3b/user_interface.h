/*******************************************************************************
//
//  NAME:          Craig Opie
//
//  HOMEWORK:      3b
//
//  CLASS:         ICS 212
//
//  INSTRUCTOR     Ravi Narayan
//
//  DATE:          Feb 11, 2020
//
//  FILE:          user_interface.h
//
//  DESCRIPTION:   This file declares the prototype for the user interface.
//
******************************************************************************/

#ifndef _user_interface_h
#define _user_interface_h

#include "database.h"
#include "record.h"

extern int debugMode;

/* Calls the introduction message for the user interface */
void introMessage ();

/* Calls the menu for the user to interact with */
int menu(struct record * dataBase);

/* Calls the function selected by the user */
int callMenuItem(struct record * dataBase, int);

/* Collects information for adding a record */
int userAddRecord(struct record ** dataBase);

/* Collects information for printing a record */
int userPrintRecord(struct record * dataBase);

/* Collects information for modifying a record */
int userModifyRecord(struct record * dataBase);

/* Collects information for deleting a record */
int userDeleteRecord(struct record ** dataBase);

/* Collects valid integers from the user */
int getIntFromUser();

/* Collects string from the user with \n chars */
void getStringFromUser(char * text, int size);

/* Exponent calculation function */
int exponent(int base, int exp);

#endif
