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
//  FILE:          database.c
//
//  DESCRIPTION:   This file uses
//
******************************************************************************/

#include <stdio.h>
#include "database.h"

/******************************************************************************
//
//  FUNCTION NAME: addRecord
//
//  DESCRIPTION:   addRecord function creates a new record entry.
//
//  PARAMETERS:    entry     : Pointer the pointers address of the entry.
//                 accNum    : Account number for the entry.
//                 name      : Pointer to the entry name.
//                 address   : Pointer to the entry address.
//
//  RETURN VALUES: 0 : Success.
//
******************************************************************************/

int addRecord(struct record ** entry, int accNum, char * name, char * address)
{
    if (debugMode == 0)
    {
        printf("\n\nFUNCTION NAME: addRecord\n");
        printf("Account Number: %d\n", accNum);
        printf("Name: %s\n", name);
        printf("Address: %s\n", address);
    }
    printf("STUB - You added a record.\n");

    return 0;
}

/******************************************************************************
//
//  FUNCTION NAME: printRecord
//
//  DESCRIPTION:   printRecord function prints the specified record to screen.
//
//  PARAMETERS:    recordSet : Pointer to the address of the record struct.
//                 accNum    : Account number for the entry.
//
//  RETURN VALUES: 0 : Success.
//
******************************************************************************/

int printRecord(struct record * recordSet, int accNum)
{
    if (debugMode == 0)
    {
        printf("\n\nFUNCTION NAME: printRecord\n");
        printf("Account Number: %d\n", accNum);
    }
    printf("\nSTUB - You printed a record.\n");

    return 0;
}

/******************************************************************************
//
//  FUNCTION NAME: printAllRecords
//
//  DESCRIPTION:   printAllRecords function prints all records in the struct.
//
//  PARAMETERS:    recordSet : Pointer to the address of the record struct.
//
//  RETURN VALUES: None
//
******************************************************************************/

void printAllRecords(struct record * recordSet)
{
    if (debugMode == 0)
    {
        printf("\n\nFUNCTION NAME: printAllRecords\n");
    }
    printf("STUB - You printed all records.\n");
}

/******************************************************************************
//
//  FUNCTION NAME: modifyRecord
//
//  DESCRIPTION:   modifyRecord function changes the specified address.
//
//  PARAMETERS:    recordSet : Pointer to the address of the record struct.
//                 accNum    : Account number for the entry.
//                 address   : Pointer to the entry address.
//
//  RETURN VALUES: 0 : Success.
//
******************************************************************************/

int modifyRecord(struct record * recordSet, int accNum, char * address)
{
    if (debugMode == 0)
    {
        printf("\n\nFUNCTION NAME: modifyRecord\n");
        printf("Account Number: %d\n", accNum);
        printf("Address: %s\n", address);
    }
    printf("STUB - You modified the address.\n");

    return 0;
}

/******************************************************************************
//
//  FUNCTION NAME: deleteRecord
//
//  DESCRIPTION:   deleteRecord function removes the specified entry.
//
//  PARAMETERS:    entry     : Pointer the pointers address of the entry.
//                 accNum    : Account number for the entry.
//
//  RETURN VALUES: 0 : Success.
//
******************************************************************************/

int deleteRecord(struct record ** entry, int accNum)
{
    if (debugMode == 0)
    {
        printf("\n\nFUNCTION NAME: deleteRecord\n");
        printf("Account Number: %d\n", accNum);
    }
    printf("\nSTUB - You deleted a record.\n");

    return 0;
}
