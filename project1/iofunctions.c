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
    FILE * in_file;
    int i;
    int j;
    int accnum;
    int loop = 1;
    int success = 0;
    char parsed[3][80];

    in_file = fopen(filename, "a+");

    if (in_file == NULL)
    {
        success = -1;
    }
    else
    {
        while(loop)
        {
            for(i = 0; i < 3; i++)
            {
                if(fgets(parsed[i], 80, in_file) != NULL)
                {
                    for(j = 0; j < 80; j++)
                    {
                        if(parsed[i][j] == '\n')
                        {
                            parsed[i][j] = '\0';
                        }
                        if(parsed[i][j] == ';')
                        {
                            parsed[i][j] = '\n';
                        }
                    }
                }
                else
                {
                    loop = 0;
                }
            }
            if(loop)
            {
                accnum = strToInt(parsed[0], 80);
                addRecord(accarray, accnum, parsed[1], parsed[2]);

                for(i = 0; i < 3; i++)
                {
                    for(j = 0; j < 80; j++)
                    {
                        parsed[i][j] = '\0';
                    }
                }
            }
        }
    }

    fclose(in_file);

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

int writefile( struct record * accarray, char filename[] )
{
    FILE * out_file;
    struct record * temp = accarray;
    int i;
    int success = 0;

    out_file = fopen(filename, "w");

    if (accarray != NULL)
    {
        if (out_file == NULL)
        {
            success = -1;
        }
        else
        {
            while (temp->next != NULL)
            {
                for (i = 0; i < 25; i++)
                {
                    if (temp->name[i] == '\n')
                    {
                        temp->name[i] = ';';
                    }
                }
                for (i = 0; i < 80; i++)
                {
                    if (temp->address[i] == '\n')
                    {
                        temp->address[i] = ';';
                    }
                }

                fprintf(out_file, "%d\n", temp->accountno);
                fprintf(out_file, "%s\n", temp->name);
                fprintf(out_file, "%s\n", temp->address);
                temp = temp->next;
            }
            
            for (i = 0; i < 25; i++)
            {
                if (temp->name[i] == '\n')
                {
                    temp->name[i] = ';';
                }
            }
            for (i = 0; i < 80; i++)
            {
                if (temp->address[i] == '\n')
                {
                    temp->address[i] = ';';
                }
            }

            fprintf(out_file, "%d\n", temp->accountno);
            fprintf(out_file, "%s\n", temp->name);
            fprintf(out_file, "%s\n", temp->address);
        }
    }

    fclose(out_file);
    
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
        }
    }
    while(bad_input == 1);

    return(valid_int);
}

