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

    FILE * file_p;
    char accountnoC[80];

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
        if (item == 0)
        {
            fgets(accountnoC, 80, file_p);
            accarray[count].accountno = strToInt(accountnoC);
            item = 1;
            i++;
        }
        accountnoC[79] = '\0';
        if (item == 1)
        {
            fgets(accarray[count].name, 25, file_p);
            item = 2;
            i++;
        }
        accarray[count].name[24] = '\0';
        if (item == 3)
        {
            fgets(accarray[count].address, 80, file_p);
            item = 0;
            i++;
        }
        accarray[count].address[79] = '\0';
        count++;
    }
    *numcust = lines / 3;

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

    FILE * file_p;
    int accuntno;
    char name[25];
    char address[80];

    file_p = fopen("outfile.txt", "w");
    if (file_p == NULL)
    {
        success = -1;
    }

    while (currentChar != EOF)
    {
        if (item == 0)
        {
            fprintf(file_p, accarray[count].accountno + '\n', text);
            item = 1;
        }
        if (item == 1)
        {
            i = 0;
            while (currentChar != '\n')
            {
                currentChar = accarray[count].name[i];
                fprintf(file_p, currentChar, text);
                i++;
            }
            item = 2;
        }
        if (item == 2)
        {
            i = 0;
            while (currentChar != '\n')
            {
                currentChar = accarray[count].address[i];
                fprintf(file_p, currentChar, text);
                i++;
            }
            item = 0;
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

int strToInt()
{
    char user_input[80];
    int i;
    int size_user_input = 0;
    int bad_input = 1;
    int digits;
    int valid_int;

    do
    {
        fgets(user_input, 80, stdin);
        for (i = 0; i < 80; i++)
        {
            if (((int)user_input[i] > 47) && ((int)user_input[i] < 58))
            {
                user_input[size_user_input] = user_input[i];
                size_user_input++;
            }
        }
        for (i = (size_user_input - 1); i < 80; i++)
        {
            user_input[i] = '\0';
        }
        for (i = 0; i < 80; i++)
        {
            if ((int)user_input[i] == 3)
            {
                user_input[i] = '\0';
            }
        }
        digits = 0;
        valid_int = 0;
        for (i = (size_user_input - 1); i >= 0; i--)
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
            for (i = 0; i < 80; i++)
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
