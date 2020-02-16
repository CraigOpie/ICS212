/*******************************************************************************
//
//  NAME:          Craig Opie
//
//  HOMEWORK:      3b
//
//  CLASS:         ICS 212
//
//  INSTRUCTOR     Ravi Narayan
//
//  DATE:          Feb 11, 2020
//
//  FILE:          record.h
//
//  DESCRIPTION:   This file declares the struct used to store records.
//
******************************************************************************/

#ifndef _record_h
#define _record_h

/* creates a structure used as a record in a 'database' */
struct record
{
    int             accountno;
    char            name[25];
    char            address[80];
    struct record*  next;
};

#endif
