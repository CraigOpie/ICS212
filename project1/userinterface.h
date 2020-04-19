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

void manFile();
int menu(llist &);
int userAddRecord(llist &);
int userPrintRecord(llist &);
int userModifyRecord(llist &);
int userDeleteRecord(llist &);
int getAccNo();
void getName(char *);
void getAddress(char *);

#endif
