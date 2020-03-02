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
//  FILE:          iofunctions.h
//
//  DESCRIPTION:   This file declares io functions
//
******************************************************************************/

#ifndef _iofunctions_h
#define _iofunctions_h
#include "record.h"

int readfile( struct record accarray[], int * numcust, char filename[] );
int writefile( struct record accarray[], int numcust, char filename[] );

#endif
