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

int readfile( struct record accarray[], int * numcust, char filename[] )
{
    int success = 0;
    int count = 0;
    int i = 0;
    int lines = 0;
    int loop = 1;
    int temp = 0;
    char currentChar = '\0';
    char master[15][80];

    FILE * file_p;
    
    file_p = fopen(filename, "r");
    if (file_p == NULL)
    {
        success = -1;
    }

    while (loop)
    {
        currentChar = fgetc(file_p);
        if (currentChar == EOF)
        {
            master[lines][i] = '\0';
        }
        else
        {
            master[lines][i] = currentChar;
        }
        i++;
        if (currentChar == '\n')
        {
            master[lines][79] = '\0';
            lines++;
            i = 0;
        }
        if (currentChar == EOF)
        {
            master[lines][79] = '\0';
            i = 0;
            loop = 0;
        }
    }
    
    fclose(file_p);

    while (i <= lines)
    {
        if (i % 3 == 0)
        {
            temp = strToInt(master[i], 80);
            accarray[count].accountno = temp;
        }
        if (i % 3 == 1)
        {
            strcpy(accarray[count].name, master[i]);
        }
        if (i % 3 == 2)
        {
            strcpy(accarray[count].address, master[i]);
            count++;
        }
        i++;
    }

    *numcust = (int)((lines + 1) / 3);

    return success;
}

/******************************************************************************
//
//  FUNCTION NAME: writefile
//
//  DESCRIPTION:   A function used to write to files
//
//  PARAMETERS:    None
//
//  RETURN VALUES: 0 : success
//
******************************************************************************/

int writefile( struct record accarray[], int numcust, char filename[] )
{
    int success = 0;
    int count = 0;
    int item = 0;
    int i = 0;
    char currentChar = '\0';
    char accountnoC[80];
    char nameStr[25];
    char addressStr[80];
    
    
    FILE * file_p;
    file_p = fopen(filename, "w");

    if (file_p == NULL)
    {
        success = -1;
    }

    while (count < numcust)
    {
        if (item == 0)
        {
            sprintf(accountnoC, "%d", accarray[count].accountno);
            accountnoC[78] = 'n';
            accountnoC[79] = '\0';
            fprintf(file_p, accountnoC);
            item = 1;
        }
        if (item == 1)
        {
            i = 0;
            while (currentChar != '\n')
            {
                currentChar = accarray[count].name[i];
                nameStr[i] = currentChar;
                i++;
            }
            nameStr[24] = '\0';
            fprintf(file_p, nameStr);
            item = 2;
        }
        if (item == 2)
        {
            i = 0;
            while (currentChar != '\n')
            {
                currentChar = accarray[count].address[i];
                addressStr[i] = currentChar;
                i++;
            }
            addressStr[79] = '\0';
            fprintf(file_p, addressStr);
            item = 0;
        }
        i = 0;
        while (i < 25)
        {
            nameStr[i] = '\0';
        }
        i = 0;
        while (i < 80)
        {
            addressStr[i] = '\0';
        }
        count++;
    }

    fclose(file_p);

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
