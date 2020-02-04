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
//  FILE:          driver.c
//
//  DESCRIPTION:   This file uses a function 'halfstring' which populates a new
//                 char array which skips every other letter of the original.
//
******************************************************************************/

#include <stdio.h>
#include "halfstring.h"
#include "mystring.h"

/******************************************************************************
//
//  FUNCTION NAME: main
//
//  DESCRIPTION:   Main function creates three different test const char arrays
//                 with a maximum of 15 characters.  The function then creates
//                 a new char array with a maximum of 15 characters.  The
//                 function then calls halfstring() and passes the address of
//                 each, current test string and the newString array.  The
//                 function then stores every other letter of the test array
//                 into the newString array until it reaches the '\0' character
//                 or the maximum length defined in the function.  The function
//                 then prints the values of the test array and newString to
//                 the screen for the user.  Afterwards, the function clears
//                 the contents from newString to store the next value.
//
//  PARAMETERS:    None.
//
//  RETURN VALUES: 0 : Success.
//
******************************************************************************/

int main(int argc, char* argv[])
{
    char newString[15];
    const char firstString[15] = { 'T','h','i','s',' ','i','s',' ','f','i', \
    'r','s','t','\0' };
    const char secondString[15] = { 'S','e','c','o','n','d','\0' };
    const char thirdString[15] = { '3','r','d',' ','s','t','r','i','n','g', \
    '\0' };
    const int maxSize = 15;

    halfstring(firstString, newString);
    printf("Input:  ");
    printConstArray(firstString, maxSize);
    printf("Result: ");
    printArray(newString, maxSize);

    clearArray(newString, maxSize);
    halfstring(secondString, newString);
    printf("Input:  ");
    printConstArray(secondString, maxSize);
    printf("Result: ");
    printArray(newString, maxSize);

    clearArray(newString, maxSize);
    halfstring(thirdString, newString);
    printf("Input:  ");
    printConstArray(thirdString, maxSize);
    printf("Result: ");
    printArray(newString, maxSize);

    return 0;
}
