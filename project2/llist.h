/*******************************************************************************
//
//  NAME:           Craig Opie
//
//  HOMEWORK:       project2
//
//  CLASS:          ICS 212
//
//  INSTRUCTOR:     Ravi Narayan
//
//  DATE:           April 03, 2020
//
//  FILE:           llist.h
//
//  DESCRIPTION:    This file declares the class used to store records.
//
******************************************************************************/

#ifndef _llist_h
#define _llist_h

#include "llist.h"
#include "record.h"
using namespace std;

/* creates a class used capsulate the 'database' */
class llist
{
private:
    record *    start;
    char        filename[16];
    int         readfile();
    int         writefile();
    record *    reverse(record * );
    void        cleanup();

public:
    llist();
    llist(char[]);
    llist(const llist &);
    llist & operator = (const llist &);
    ~llist();
    int addRecord(int, char [],char []);
    int printRecord(int);
    friend ostream & operator << (ostream &, const llist &);
    int modifyRecord(int, char []);
    int deleteRecord(int);
    void reverse();
};

#endif
