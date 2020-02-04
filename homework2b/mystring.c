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
//  FILE:          mystring.c
//
//  DESCRIPTION:   This file is used to manipulate char arrays and const char
//                 arrays without using overloads or the system <string.h>
//
******************************************************************************/

#include <stdio.h>
#include "mystring.h"

/******************************************************************************
//
//  FUNCTION NAME: printConstArray
//
//  DESCRIPTION:   Function receives an address to an array and the size of the
//                 array as an int and then iterates through the array,
//                 printing each character until it reaches a '\0' character
//                 or the max size provided.
//
//  PARAMETERS:    *constString : This is a const char pointer which identifys
//                                the address of the character array to print.
//                 size : This is an integer that specifies the maximum size
//                 of the array to print.
//
//  RETURN VALUES: None.
//
******************************************************************************/

void printConstArray(const char *constString, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (constString[i] == '\0')
        {
            i = size;
        }
        else
        {
            printf("%c", constString[i]);
        }
    }
    printf("\n");
}

/******************************************************************************
//
//  FUNCTION NAME: printArray
//
//  DESCRIPTION:   Function receives an address to an array and the size of the
//                 array as an int and then iterates through the array,
//                 printing each character until it reaches a '\0' character
//                 or the max size provided.
//
//  PARAMETERS:    string : This is a char pointer which identifys the address
//                 of the character array to print.
//                 size : This is an integer that specifies the maximum size
//                 of the array to print.
//
//  RETURN VALUES: None.
//
******************************************************************************/

void printArray(char *string, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (string[i] == '\0')
        {
            i = size;
        }
        else
        {
            printf("%c", string[i]);
        }
    }
    printf("\n");
}

/******************************************************************************
//
//  FUNCTION NAME: clearArray
//
//  DESCRIPTION:   Function receives an address to an array and the size of the
//                 array as an int and then iterates through the array,
//                 replacing each character with a '\0' character for the max
//                 size provided.
//
//  PARAMETERS:    newString : This is a char pointer which identifys the
//                 address of the character array to clear.
//                 size : This is an integer that specifies the maximum size
//                 of the array to clear.
//
//  RETURN VALUES: None.
//
******************************************************************************/

void clearArray(char *newString, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        newString[i] = '\0';
    }
}
