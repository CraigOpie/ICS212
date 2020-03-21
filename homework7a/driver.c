/*******************************************************************************
//
//  NAME:           Craig Opie
//
//  HOMEWORK:       homework7a
//
//  CLASS:          ICS 212
//
//  INSTRUCTOR      Ravi Narayan
//
//  DATE:           Mar 21, 2020
//
//  FILE:           driver.c
//
//  DESCRIPTION:    This file tests the function costofpainting.
//
******************************************************************************/

#include <stdio.h>
#include "iofunctions.h"
#include "paint.h"

void manFile();

/******************************************************************************
//
//  FUNCTION NAME:  main
//
//  DESCRIPTION:    Main function tests the function costofpainting
//
//  PARAMETERS:     None.
//
//  RETURN VALUES:  0 : Success.
//
******************************************************************************/

int main(int argc, char* argv[])
{
    double user_input;
    
    if (argc == 2)
    {
        user_input = (double)strToInt(argv[1], 4);
        if (user_input < 0.1)
        {
            user_input = 13.0;
        }
    }
    else
    {
        if (argc > 2)
        {
            printf("ERROR: improper use of arguments\n");
            manFile();
        }
        else
        {
            user_input = 13.0;
        }
    }

    printf("Total distance:  %.2f\n", user_input);
    printf("Total cost:     $%.2f\n", costofpainting(user_input));

    return 0;
}

/******************************************************************************
//
//  FUNCTION NAME: manFile
//
//  DESCRIPTION:   manFile function informs the user about using arguments
//
//  PARAMETERS:    None.
//
//  RETURN VALUES: None.
//
******************************************************************************/

void manFile()
{
    printf("NAME\n\thomework7a - driver file\n\n");
    printf("SYNOPSIS\n\thomework7a [distance]\n\n");
    printf("DESCRIPTION\n\thomework7a tests the costofpainting function.\n\n");
    printf("OPTIONS\n\tdistance\n\t\tAllows the user to specify a distance,");
    printf("\n\t\tin miles, different from the default 13.0 miles.\n\n");
}
