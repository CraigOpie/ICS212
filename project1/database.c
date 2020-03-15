/*******************************************************************************
//
//  NAME:          Craig Opie
//
//  HOMEWORK:      project1
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
#include <stdlib.h>
#include <string.h>
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
    struct record * temp = *entry;
    int wrote = 2;

    if (debugMode == 0)
    {
        printf("\n\nFUNCTION NAME: addRecord\n");
        printf("Account Number: %d\n", accNum);
        printf("Name: %s\n", name);
        printf("Address: %s\n", address);
    }

    if (temp == NULL)
    {
        *entry = (struct record *) malloc(sizeof(struct record));
        temp = *entry;
        wrote = 0;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = (struct record *) malloc(sizeof(struct record));
        temp = temp->next;
        wrote = 0;
    }

    temp->accountno = accNum;
    strcpy(temp->name, name);
    strcpy(temp->address, address);

    return wrote;
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
    struct record * temp = recordSet;
    int printed = 2;

    if (debugMode == 0)
    {
        printf("\n\nFUNCTION NAME: printRecord\n");
        printf("Account Number: %d\n", accNum);
    }

    if (temp == NULL)
    {
        printf("\nThe database is empty.\n");
    }
    else
    {
        while (temp->next != NULL)
        {
            if (temp->accountno == accNum)
            {
                printf("\nAccount Number: %d\n", temp->accountno);
                printf("Name: %s\n", temp->name);
                printf("Address: %s\n", temp->address);
                printed = 0;
            }
            temp = temp->next;
        }

        if (temp->accountno == accNum)
        {
            printf("\nAccount Number: %d\n", temp->accountno);
            printf("Name: %s\n", temp->name);
            printf("Address: %s\n", temp->address);
            printed = 0;
        }
    }

    return printed;
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
    struct record * temp = recordSet;

    if (debugMode == 0)
    {
        printf("\n\nFUNCTION NAME: printAllRecords\n");
    }

    if (temp == NULL)
    {
        printf("\nThe database is empty.\n");
    }
    else
    {
        while (temp->next != NULL)
        {
            printf("\nAccount Number: %d\n", temp->accountno);
            printf("Name: %s\n", temp->name);
            printf("Address: %s\n", temp->address);
            temp = temp->next;
        }

            printf("Back to the main menu");
        printf("\nAccount Number: %d\n", temp->accountno);
        printf("Name: %s\n", temp->name);
        printf("Address: %s\n", temp->address);
    }
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
    struct record * temp = recordSet;
    int modified = 2;

    if (debugMode == 0)
    {
        printf("\n\nFUNCTION NAME: modifyRecord\n");
        printf("Account Number: %d\n", accNum);
        printf("Address: %s\n", address);
    }

    if (temp == NULL)
    {
        printf("\nThe database is empty.\n");
    }
    else
    {
        while (temp->next != NULL)
        {
            if (temp->accountno == accNum)
            {
                strcpy(temp->address, address);
                modified = 0;
            }
            temp = temp->next;
        }

        if (temp->accountno == accNum)
        {
            strcpy(temp->address, address);
            modified = 0;
        }
    }

    return modified;
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
    struct record * temp = *entry;
    struct record * last = *entry;
    int deleted = 2;

    if (debugMode == 0)
    {
        printf("\n\nFUNCTION NAME: deleteRecord\n");
        printf("Account Number: %d\n", accNum);
    }

    if (temp == NULL)
    {
        printf("\nThe database is empty.\n");
    }
    else
    {
        while(temp->next != NULL)
        {
            if (temp->accountno == accNum)
            {
                if (temp == *entry)
                {
                    *entry = temp->next;
                    temp = NULL;
                    free(temp);
                    temp = *entry;
                    deleted = 0;
                }
                else
                {
                    last->next = temp->next;
                    temp = NULL;
                    free(temp);
                    temp = last->next;
                    deleted = 0;
                }
            }

            if(temp->next != NULL)
            {
                last = temp;
                temp = temp->next;
            }
        }

        if (temp->accountno == accNum)
        {
            if (temp == *entry)
            {
                temp = NULL;
                free(temp);
                *entry = NULL;
                deleted = 0;
            }
            else
            {
                temp = NULL;
                free(temp);
                last->next = NULL;
                deleted = 0;
            }
        }
    }
    
    return deleted;
}

/******************************************************************************
//
//  FUNCTION NAME: cleanup
//
//  DESCRIPTION:   cleanup function removes all entries.
//
//  PARAMETERS:    entry     : Pointer the pointers address of the entry.
//
//  RETURN VALUES: 0 : Success.
//
******************************************************************************/

void cleanup(struct record ** entry)
{
    struct record * temp = *entry;
    struct record * last = *entry;

    if (debugMode == 0)
    {
        printf("\n\nFUNCTION NAME: cleanup\n");
    }

    if (temp == NULL)
    {
        printf("\nThe database is empty.\n");
    }
    else
    {
        while(temp->next != NULL)
        {
            if (temp == *entry)
            {
                *entry = temp->next;
                temp = NULL;
                free(temp);
                temp = *entry;
            }
            else
            {
                last->next = temp->next;
                temp = NULL;
                free(temp);
                temp = last->next;
            }

            if(temp->next != NULL)
            {
                last = temp;
                temp = temp->next;
            }
        }

        if (temp == *entry)
        {
            temp = NULL;
            free(temp);
            *entry = NULL;
        }
        else
        {
            temp = NULL;
            free(temp);
            last->next = NULL;
        }
    }
}
