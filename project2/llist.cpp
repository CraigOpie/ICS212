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
//  FILE:           llist.cpp
//
//  DESCRIPTION:    This file declares the struct used to store records.
//
******************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include "llist.h"

/******************************************************************
//
//  FUNCTIONNAME:   readfile
//
//  DESCRIPTION:    A function used to read from files
//
//  PARAMETERS:     None
//
//  RETURNVALUES:   0 : success
//
******************************************************************/

int llist::readfile()
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: llist::readfile" << endl;
    #endif

    FILE * inFile;
    int accNum;
    int row = 0;
    int col = 0;
    int loop = 1;
    int success = 0;
    char c;
    char parsed[3][80];

    inFile = fopen(filename, "a+");

    if(!inFile)
    {
        cerr << "Unable to open file " << filename << endl;
        exit(-1);
    }
    else
    {
        while(c != EOF)
        {
            c = getc(inFile);
            parsed[row][col] = c;
            if(c == '\n' || c == EOF)
            {
                parsed[row][col] = '\0';
                row++;
                col = -1;
            }
            if(c == ';')
            {
                parsed[row][col] = '\n';
            }
            col++;

            if(row > 2)
            {
                stringstream temp(parsed[0]);
                temp >> accNum;
                addRecord(accNum, parsed[1], parsed[2]);

                accNum = 0;
                for(row = 0; row < 3; row++)
                {
                    for(col = 0; col < 80; col++)
                    {
                        parsed[row][col] = '\0';
                    }
                }
            }
        }
    }

    fclose(inFile);

    return success;
}

/******************************************************************************
//
//  FUNCTIONNAME:   writefile
//
//  DESCRIPTION:    A function used to write to files
//
//  PARAMETERS:     None
//
//  RETURNVALUES:   0 : success
//
******************************************************************************/

int llist::writefile()
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: llist::writefile" << endl;
    #endif

    FILE * outFile;
    record * temp = (this -> start);
    int i;
    int success = 0;

    outFile = fopen(filename, "w");

    if (temp != NULL)
    {
        if (outFile == NULL)
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

                fprintf(outFile, "%d\n", temp->accountno);
                fprintf(outFile, "%s\n", temp->name);
                fprintf(outFile, "%s\n", temp->address);
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

            fprintf(outFile, "%d\n", temp->accountno);
            fprintf(outFile, "%s\n", temp->name);
            fprintf(outFile, "%s\n", temp->address);
        }
    }

    fclose(outFile);
    
    return success;

}

/******************************************************************************
//
//  FUNCTIONNAME:   reverse
//
//  DESCRIPTION:    A function used to reverse the llist.
//
//  PARAMETERS:     recordFwd : Pointer to the record to be reversed.
//
//  RETURNVALUES:   0 : success
//
******************************************************************************/

record * llist::reverse(record * recordFwd)
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: llist::record * reverse" << endl;
        cout << "recordFwd: " << recordFwd << endl;
    #endif

    record * temp;
    bool done = false;

    // Returns list as is if there is nothing to reverse
    if(recordFwd == NULL || (recordFwd -> next) == NULL)
    {
        temp = recordFwd;
        done = true;
    }

    // Reverses the list and returns temp
    if(!done)
    {
        temp = reverse(recordFwd -> next);
        ((recordFwd -> next) -> next) = recordFwd;
        (recordFwd -> next) = NULL;
    }
    
    return temp;
    
}

/******************************************************************************
//
//  FUNCTIONNAME:   cleanup
//
//  DESCRIPTION:    A function used to 'free' the allocated memory and set the
//                  pointer to null.
//
//  PARAMETERS:     None
//
//  RETURNVALUES:   0 : success
//
******************************************************************************/

void llist::cleanup()
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: llist::cleanup" << endl;
    #endif

    record * temp;
    while((this -> start) != NULL) 
    {
        temp = (this -> start);
        (this -> start) = ((this -> start) -> next);
        delete(temp);
        temp = NULL;
    }
    (this -> start) = NULL;
}
    
/******************************************************************************
//
//  FUNCTIONNAME:   llist
//
//  DESCRIPTION:    A constructor used to set the llist to null, set the
//                  filename to 'database.txt', and readin the database file.
//
//  PARAMETERS:     None
//
//  RETURNVALUES:   0 : success
//
******************************************************************************/

llist::llist()
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: llist::llist" << endl;
    #endif

    (this -> start) = NULL;
    strcpy(filename, "database.txt");
    readfile();
    
}

/******************************************************************************
//
//  FUNCTIONNAME:   llist
//
//  DESCRIPTION:    A constructor used to set the llist to null, set the
//                  filename to inFile[], and readin the database file.
//
//  PARAMETERS:     inFile : User specified filename for the database file.
//
//  RETURNVALUES:   0 : success
//
******************************************************************************/

llist::llist(char inFile[])
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: llist::llist" << endl;
        // cout << "char[]: " << char[] << endl;
    #endif

    (this -> start) = NULL;
    strcpy(filename, inFile);
    readfile();

}

/******************************************************************************
//
//  FUNCTIONNAME:   ~llist
//
//  DESCRIPTION:    A deconstructor used to write the database file, then
//                  cleanup the allocated memory.
//
//  PARAMETERS:     None
//
//  RETURNVALUES:   0 : success
//
******************************************************************************/

llist::~llist()
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: llist::~llist" << endl;
    #endif

    writefile();
    cleanup();

}

/******************************************************************************
//
//  FUNCTIONNAME:   addRecord
//
//  DESCRIPTION:    addRecord function creates a new record entry.
//
//  PARAMETERS:     accNum    : Account number for the entry.
//                  name      : Pointer to the entry name.
//                  address   : Pointer to the entry address.
//
//  RETURNVALUES:   0 : Success.
//
******************************************************************************/

int llist::addRecord(int accNum, char name[25],char address[80])
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: llist::addRecord" << endl;
        cout << "accNum: " << accNum << endl;
        // cout << "name[25]: " << name[] << endl;
        // cout << "address[80]: " << address[] << endl;
    #endif

    record * temp = NULL;

    temp = (this -> start);
    while(temp != NULL)
    {
        temp = temp -> next;
    }
    temp = new record;
    temp -> accountno = accNum;
    strcpy(temp -> name, name);
    strcpy(temp -> address, address);

    return 0;
}

/******************************************************************************
//
//  FUNCTIONNAME:   printRecord
//
//  DESCRIPTION:    printRecord function prints the specified record to screen.
//
//  PARAMETERS:     accNum  : Account number for the entry.
//
//  RETURNVALUES:   0 : Success.
//
******************************************************************************/

int llist::printRecord(int accNum)
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: llist::printRecord" << endl;
        cout << "accNum: " << accNum << endl;
    #endif

    record * temp = NULL;

    temp = (this -> start);
    while (temp != NULL)
    {
        if(temp -> accountno == accNum)
        {
            cout << temp -> accountno << endl;
            cout << temp -> name << endl;
            cout << temp -> address << endl;
        }
        temp = temp -> next;
    }

    return 0;
}

// replace printAllRecords() with the << operator

/******************************************************************************
//
//  FUNCTIONNAME:   modifyRecord
//
//  DESCRIPTION:    modifyRecord function changes the specified address.
//
//  PARAMETERS:     accNum  : Account number for the entry.
//                  address : Pointer to the entry address.
//
//  RETURNVALUES:   0 : Success.
//
******************************************************************************/

int llist::modifyRecord(int accNum, char address[80])
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: llist::modifyRecord" << endl;
        cout << "accNum: " << accNum << endl;
        // cout << "address[80]: " << address[] << endl;
    #endif

    record * temp = NULL;

    temp = (this -> start);
    while (temp != NULL)
    {
        if(temp -> accountno == accNum)
        {
            strcpy(temp -> address, address);
        }
        temp = temp -> next;
    }

    return 0;
}

/******************************************************************************
//
//  FUNCTIONNAME:   deleteRecord
//
//  DESCRIPTION:    deleteRecord function removes the specified entry.
//
//  PARAMETERS:     accNum  : Account number for the entry.
//
//  RETURNVALUES:   0 : Success.
//
******************************************************************************/

int llist::deleteRecord(int accNum)
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: llist::deleteRecord" << endl;
        cout << "accNum: " << accNum << endl;
    #endif

    record * temp = NULL;
    record * previous = NULL;

    temp = (this -> start);
    while (temp != NULL)
    {
        if((temp -> accountno) == accNum)
        {
            if(temp == (this -> start))
            {
                previous = (this -> start);
                start = ((this -> start) -> next);
                temp = (this -> start);
                delete(previous);
                previous = NULL;
            }
            else
            {
                previous -> next = temp -> next;
                delete(temp);
                temp = previous -> next;
            }
        }
        else
        {
            previous = temp;
            temp = temp -> next;
        }
    }

    return 0;
}

/******************************************************************************
//
//  FUNCTIONNAME:   reverse
//
//  DESCRIPTION:    reverse function calls the private function to reverse the
//                  llist and replace the previous llist.
//
//  PARAMETERS:     None
//
//  RETURNVALUES:   0 : Success.
//
******************************************************************************/

void llist::reverse()
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: llist::reverse" << endl;
    #endif

    record * temp;

    temp = reverse(this -> start);
}
