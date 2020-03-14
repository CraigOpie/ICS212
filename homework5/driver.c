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
#include "iofunctions.h"
#include "record.h"

/******************************************************************************
//
//  FUNCTION NAME: main
//
//  DESCRIPTION:   A function used to test the read and write functions
//
//  PARAMETERS:    None
//
//  RETURN VALUES: 0 : success
//
******************************************************************************/

int main( int argc, char * argv[] )
{
    struct record bankone[5];
    int numcustomers = 0;

    readfile(bankone, &numcustomers, "test.txt");
    /*writefile(bankone, numcustomers, "outfile.txt");*/

    return 0;
}
