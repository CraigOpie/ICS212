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
#include "database.h"
#include "user_interface.h"

int readfile( struct record ** accarray, char filename[] );
int writefile( struct record * accarray, char filename[] );
int strToInt(char user_input[], int length);

#endif
