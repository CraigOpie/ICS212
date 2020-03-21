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
//  DATE:          Feb 29, 2020
//
//  FILE:          iofunctions.c
//
//  DESCRIPTION:   This file contains input/output functions.
//
//
******************************************************************************/

#include <stdio.h>
#include <string.h>
#include "iofunctions.h"

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
        for (i = (size_user_input); i < length; i++)
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
            printf("Not a valid integer.  Defaulting to 13 miles.\n");
            valid_int *= 0;
            bad_input = 0;
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
