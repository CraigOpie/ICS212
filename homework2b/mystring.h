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
//  FILE:          mystring.h
//
//  DESCRIPTION:   This file declares the prototype for the function
//                 'mystring', which is used to clear a char[] and print the
//                 values in const char array and char array without using
//                 overloads.
//
******************************************************************************/

#ifndef _mystring_h
#define _mystring_h

/* Prints the const char[] until it reaches an '\0' character */
void printConstArray(const char [], int);

/* Prints the char[] until it reaches an '\0' character */
void printArray(char [], int);

/* Clears the char[] by inserting '\0' characters for each index */
void clearArray(char [], int);

#endif
