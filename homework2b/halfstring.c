/*******************************************************************************
//
//  NAME:          Craig Opie
//
//  HOMEWORK:      2b
//
//  CLASS:         ICS 212
//
//  INSTRUCTOR     Ravi Narayan
//
//  DATE:          Feb 01, 2020
//
//  FILE:          halfstring.c
//
//  DESCRIPTION:   This file uses a function 'halfstring' which creates a new
//                 string which skips every other letter.
//
******************************************************************************/

#include <stdio.h>
#include "halfstring.h"

/******************************************************************************
//
//  FUNCTION NAME: halfstring
//
//  DESCRIPTION:   Halfstring function takes a provided char[] and stores every
//                 other letter into a new char[].
//
//  PARAMETERS:    oldString : Pointer to user provided string.
//                 newString : Pointer to the new string with every other
//                             letter of the oldString.
//
//  RETURN VALUES: 0 : Success.
//
******************************************************************************/

void halfstring(const char *oldString, char *newString)
{
    int i;
    int j = 0;
    for (i = 0; i < 15; i++)
    {
        if (oldString[i] == '\0')
        {
            i = 15;
        }
        else
        {
            if ((i % 2) == 0)
            {
                newString[j] = oldString[i];
                j++;
            }
        }
    }
}
