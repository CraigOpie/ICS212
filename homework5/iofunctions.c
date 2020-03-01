/*******************************************************************************
//
//  NAME:          Craig Opie
//
//  HOMEWORK:      5
//
//  CLASS:         ICS 212
//
//  INSTRUCTOR     Ravi Narayan
//
//  DATE:          Feb 29, 2020
//
//  FILE:          iofunctions.c
//
//  DESCRIPTION:   This file contains input/output functions.
//
//
******************************************************************************/

#include <stdio.h>
#include "record.h"
#include "iofunctions.h"

/******************************************************************************
//
//  FUNCTION NAME: readfile
//
//  DESCRIPTION:   A function used to read from files
//
//  PARAMETERS:    None
//
//  RETURN VALUES: 0 : success
//
******************************************************************************/

int readfile( struct record accarray[], int * numcust, char filename[] )
{
    int success = 0;
    int count = 0;
    int i = 0;
    int item = 0;
    int lines = 0;
    int loop = 1;
    char currentChar = '\0';
    char lastChar = '\0';

    FILE * file_p;
    int accuntno;
    char accountnoC[80];
    char name[25];
    char address[80];

    file_p = fopen(filename, "r");
    if (file_p == NULL)
    {
        printf("%s not found.", filename);
        success = -1;
    }

    while (loop)
    {
        currentChar = fgetc(file_p);
        if (currentChar == '\n')
        {
            lines++;
        }
        if (currentChar == EOF)
        {
            loop = 0;
        }
    }

    fclose(file_p);

    file_p = fopen(filename, "r");
    while (i < lines)
    {
        if (item = 0)
        {
            fgets(accountnoC, 80, file_p);
            accarray[count].accountno = strToInt(accountnoC);
            item = 1;
            i++;
        }
        if (item = 1)
        {
            fgets(accarray[count].name, 25, file_p);
            item = 2;
            i++;
        }
        if (item = 3)
        {
            fgets(accarray[count].address, 80, file_p);
            item = 0;
            i++;
            count++;
        }
    }

    return success;
}

/******************************************************************************
//
//  FUNCTION NAME: exponent
//
//  DESCRIPTION:   exponent function returns the int of the base raised to the
//                 exp specified by the call.
//
//  PARAMETERS:    base : The radix of the number system
//                 exp  : The distance from the radix point
//
//  RETURN VALUES: int  : The result of the math.
//
******************************************************************************/

int exponent(int base, int exp)
{
    int i;
    int number =1;

    for (i = 0; i < exp; ++i)
    {
        number *= base;
    }
    return(number);
}
