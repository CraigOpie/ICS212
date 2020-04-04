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
//  FILE:          main.c
//
//  DESCRIPTION:   This file 
//
******************************************************************************/

#include <stdio.h>
#include <string.h>
#include "user_interface.h"
#include "database.h"
#include "iofunctions.h"
#include "record.h"

int debugMode = 1;
void manFile();

/******************************************************************************
//
//  FUNCTION NAME: main
//
//  DESCRIPTION:   Main function creates three different test const char arrays
//
//  PARAMETERS:    None.
//
//  RETURN VALUES: 0 : Success.
//
******************************************************************************/

int main(int argc, char* argv[])
{
    struct record * start = NULL;
    int success = 0;
    int loop = 0;

    if (argc == 2)
    {
        debugMode = strcmp(argv[1],"debug");
    }
    if (argc == 1 || (argc == 2 && debugMode == 0))
    {
        success = readfile(&start, "database.txt");
        introMessage();
        while(loop == 0)
        {
            loop = menu(&start);
        }
        success = writefile(start, "database.txt");
        cleanup(&start);

        if (success == -1)
        {
            printf("ERROR: File could not be opened.");
        }
    }
    if ((argc > 1 && debugMode > 0) || argc > 2)
    {
        printf("ERROR: improper use of arguments\n");
        manFile();
    }

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
    if (debugMode == 0)
    {
        printf("FUNCTION NAME: manFile\n\n");
    }
    printf("NAME\n\thomework3b - bank database application\n\n");
    printf("SYNOPSIS\n\thomework3b [debug]\n\n");
    printf("DESCRIPTION\n\thomework3b allows a banker to create, modify, view");
    printf("\n\tand delete information about clients.\n\n");
    printf("OPTIONS\n\tdebug\n\t\tEnters debug mode and provides amplifying");
    printf("\n\t\tinformation about each function that is operating.\n\n");
}