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
#include <stdlib.h>
#include <string.h>
#include "iofunctions.h"

int exponent(int base, int exp);
int strToInt(char user_input[], int length);

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

int readfile( struct record ** accarray, char filename[] )
{
    struct record * temp = *accarray;
    char string[80];
    char currentChar = '\0';
    int success = 0;
    int item = 1;
    int loop = 1;
    int i = 0;
    int accnum;

    FILE * in_file;
    in_file = fopen(filename, "r");
    
    if (in_file == NULL)
    {
        success = -1;
    }

    while (loop)
    {
        currentChar = fgetc(in_file);
        if (currentChar == EOF)
        {
            loop = 0;
        }

        if (loop = 1)
        {
            if (temp == NULL)
            {
                *accarray = (struct record *) malloc(sizeof(struct record));
                temp = *accarray;
            }
            else
            {
                temp->next = (struct record *) malloc(sizeof(struct record));
                temp = temp->next;
            }
            
            if (item % 3 == 0)
            {
                *string = '\0';
                for (i = 0; i < 25; i++)
                {
                    string[i] = currentChar;
                    if (currentChar == '\0')
                    {
                        i = 25;
                    }
                }

                accnum = strToInt(string[], 25);
                temp->accountno = accnum;
                item++;
            }

            if (item % 3 == 1)
            {
                *string = '\0';
                for (i = 0; i < 25; i++)
                {
                    string[i] = currentChar;
                    if (currentChar == '\0')
                    {
                        i = 25;
                    }
                }

                strcpy(temp->name, string);
                item++;
            }

            if (item % 3 == 2)
            {
                *string = '\0';
                for (i = 0; i < 80; i++)
                {
                    string[i] = currentChar;
                    if (currentChar == '\0')
                    {
                        i = 80;
                    }
                }

                strcpy(temp->address, string);
                item++;
            }
        }
    }
    
    fclose(in_file);

    return success;
}

/******************************************************************************
//
//  FUNCTION NAME: strToInt
//
//  DESCRIPTION:   Takes a string input and performs checks to ensure it is an
//                 integer value, then converts the useable string values to an
//                 integer.  The value is returned for use.
//
//  PARAMETERS:    None.
//
//  RETURN VALUES: int : Value inputed.
//
******************************************************************************/

int strToInt(char user_input[], int length)
{
    int i;
    int size_user_input = 0;
    int bad_input = 1;
    int digits;
    int valid_int;

    do
    {
        for (i = 0; i < length; i++)
        {
            if (((int)user_input[i] > 47) && ((int)user_input[i] < 58))
            {
                user_input[size_user_input] = user_input[i];
                size_user_input++;
            }
        }
        for (i = (size_user_input - 1); i < length; i++)
        {
            user_input[i] = '\0';
        }
        for (i = 0; i < length; i++)
        {
            if ((int)user_input[i] == 3)
            {
                user_input[i] = '\0';
            }
        }
        digits = 0;
        valid_int = 0;
        for (i = size_user_input; i >= 0; i--)
        {
            if (((int)user_input[i] > 47) && ((int)user_input[i] < 58))
            {
                bad_input = 0;
                valid_int += (exponent(10, digits) * ((int)user_input[i] - 48));
                digits++;
            }
        }
        if (((int)user_input[0] == 45) || (valid_int <=0))
        {
            bad_input = 1;
        }
        for (i = 0; i < size_user_input; i++)
        {
            if ((int)user_input[i] == 46)
            {
                bad_input = 1;
            }
        }
        if (bad_input == 1)
        {
            for (i = 0; i < length; i++)
            {
                user_input[i] = '\0';
            }
        }
    }
    while(bad_input == 1);

    return(valid_int);
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
