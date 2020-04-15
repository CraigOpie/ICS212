/*******************************************************************************
//
//  NAME:           Craig Opie
//
//  HOMEWORK:       project2
//
//  CLASS:          ICS 212
//
//  INSTRUCTOR:     Ravi Narayan
//
//  DATE:           April 03, 2020
//
//  FILE:           user-interface.h
//
//  DESCRIPTION:    This file declares the function used for user interaction.
//
******************************************************************************/

#ifndef _userinterface_h
#define _userinterface_h

#include "llist.h"
using namespace std;

// manFile function informs the user about using arguments
void manFile();

// interface menu to navigate the program and its features
int menu(llist &);

// interface menu to navigate the program and its features
int userAddRecord(llist &);

// interface menu to navigate the program and its features
int userPrintRecord(llist &);

// interface menu to navigate the program and its features
int userModifyRecord(llist &);

// interface menu to navigate the program and its features
int userDeleteRecord(llist &);

// interface menu to navigate the program and its features
int getAccNo();

// interface menu to navigate the program and its features
void getName(char *);

// interface menu to navigate the program and its features
void getAddress(char *);

#endif
