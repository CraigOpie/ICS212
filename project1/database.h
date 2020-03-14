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
//  FILE:          database.h
//
//  DESCRIPTION:   This file declares the prototypes for the functions used
//                 to modify the struct records. These functions require
//                 using the 'record.h' file to create the structs.  Each
//                 function also includes a debug mode which requires a global
//                 variable named debugMode to be initialized in main.
//
******************************************************************************/

#ifndef _database_h
#define _database_h

#include "record.h"
extern int debugMode;

/* Adds a record to the struct */
int addRecord (struct record **, int, char [], char []);

/* Prints the specified record to the screen */
int printRecord (struct record *, int);

/* Prints all records to the screen */
void printAllRecords (struct record *);

/* Change the record's address */
int modifyRecord (struct record *, int, char []);

/* Delete the specified record */
int deleteRecord (struct record **, int);

/* Releases all allocated heap space and assigns NULL to start */
void cleanup(struct record ** entry);

#endif
