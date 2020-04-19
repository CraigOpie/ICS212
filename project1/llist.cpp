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
//  RETURNVALUES:   0   : Success
//
******************************************************************/

int llist::readfile()
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: llist::readfile" << endl;
    #endif

    fstream inFile;
    int accNum;
    int row = 0;
    int col = 0;
    int success = 0;
    char c = '\0';
    char parsed[3][80];

    inFile.open(this->filename);

    if(!inFile.fail())
    {
        while(!inFile.eof())
        {
            inFile.get(c);
            parsed[row][col] = c;
            if(c == '\n')
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
                this->addRecord(accNum, parsed[1], parsed[2]);

                accNum = 0;
                for(row = 0; row < 3; row++)
                {
                    for(col = 0; col < 80; col++)
                    {
                        parsed[row][col] = '\0';
                    }
                }

                row = 0;
                col = 0;
            }
        }
        inFile.close();
    }
    else
    {
        success = -1;
    }

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
//  RETURNVALUES:   0   : Success
//
******************************************************************************/

int llist::writefile()
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: llist::writefile" << endl;
    #endif

    ofstream outFile(this->filename);
    record * temp = NULL;
    int i;
    int success = 0;

    if(!outFile.fail())
    {
        temp = (this->start);
        while(temp != NULL)
        {
            for(i = 0; i < 25; i++)
            {
                if(temp->name[i] == '\n')
                {
                    temp->name[i] = ';';
                }
            }
            for(i = 0; i < 80; i++)
            {
                if(temp->address[i] == '\n')
                {
                    temp->address[i] = ';';
                }
            }
            outFile << temp->accountno << endl;
            outFile << temp->name << endl;
            outFile << temp->address << endl;

            temp = temp->next;
        }
    }
    else
    {
        success = -1;
    }
    
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
//  RETURNVALUES:   0   : Success
//
******************************************************************************/

record * llist::reverse(record * recordFwd)
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: llist::record * reverse" << endl;
    #endif

    record * temp;
    bool done = false;

    // Returns list as is if there is nothing to reverse
    if(recordFwd == NULL || recordFwd->next == NULL)
    {
        temp = recordFwd;
        done = true;
    }

    // Reverses the list and returns temp
    if(!done)
    {
        temp = this->reverse(recordFwd->next);
        ((recordFwd->next)->next) = recordFwd;
        recordFwd->next = NULL;
    }
    
    return temp;
    
}

/******************************************************************************
//
//  FUNCTIONNAME:   cleanup
//
//  DESCRIPTION:    A function used to 'free' the allocated memory and set the
//                  pointer to NULL.
//
//  PARAMETERS:     None
//
//  RETURNVALUES:   0   : Success
//
******************************************************************************/

void llist::cleanup()
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: llist::cleanup" << endl;
    #endif

    record * temp;
    while(this->start != NULL) 
    {
        temp = this->start;
        this->start = ((this->start)->next);
        delete(temp);
        temp = NULL;
    }
    this->start = NULL;
}
    
/******************************************************************************
//
//  FUNCTIONNAME:   llist
//
//  DESCRIPTION:    A constructor used to set the llist to NULL, set the
//                  filename to 'database.txt', and readin the database file.
//
//  PARAMETERS:     None
//
//  RETURNVALUES:   0   : Success
//
******************************************************************************/

llist::llist()
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: llist::llist" << endl;
    #endif

    this->start = NULL;
    strcpy(this->filename, "database.txt");
    this->readfile();
    
}

/******************************************************************************
//
//  FUNCTIONNAME:   llist
//
//  DESCRIPTION:    A constructor used to set the llist to NULL, set the
//                  filename to inFile[], and readin the database file.
//
//  PARAMETERS:     inFile : User specified filename for the database file.
//
//  RETURNVALUES:   0   : Success
//
******************************************************************************/

llist::llist(char inFile[])
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: llist::llist" << endl;
        cout << "char[]: " << inFile << endl;
    #endif

    int i = 0;

    while(inFile[i] != '\0')
    {
        i++;
    }
    if(i < 16)
    {
        strcpy(this->filename, inFile);
    }
    else
    {
        strcpy(this->filename, "database.txt");
        cout << "Warning: Filename too long. New filename is: ";
        cout << this->filename << endl;
    }
    
    this->start = NULL;
    this->readfile();
}

/******************************************************************************
//
//  FUNCTIONNAME:   llist
//
//  DESCRIPTION:    A copy constructor used to set the llist to the same values
//                  as the passed objects llist.
//
//  PARAMETERS:     obj : Object to copy.
//
//  RETURNVALUES:   0   : Success
//
******************************************************************************/

llist::llist(llist const &obj)
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: llist::llist" << endl;
        cout << "Copy Constructor" << endl;
    #endif

    this->start = obj.start;
    strcpy(this->filename, obj.filename);

}

llist & llist::operator = (const llist &obj)
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: llist::llist" << endl;
        cout << "Copy Constructor" << endl;
    #endif

    this->start = obj.start;
    strcpy(this->filename, obj.filename);

    return *this;

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
//  RETURNVALUES:   0   : Success
//
******************************************************************************/

llist::~llist()
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: llist::~llist" << endl;
    #endif

    this->writefile();
    this->cleanup();

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
//  RETURNVALUES:   0   : Success.
//
******************************************************************************/

int llist::addRecord(int accNum, char name[25],char address[80])
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: llist::addRecord" << endl;
        cout << "accNum: " << accNum << endl;
        cout << "name[25]: " << name << endl;
        cout << "address[80]: " << address << endl;
    #endif

    record * temp = NULL;
    int success = 2;

    temp = this->start;
    if(temp == NULL)
    {
        this->start = new record;
        (this->start)->accountno = accNum;
        strcpy((this->start)->name, name);
        strcpy((this->start)->address, address);
        (this->start)->next = NULL;
        success = 0;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new record;
        temp = temp->next;
        temp->accountno = accNum;
        strcpy(temp->name, name);
        strcpy(temp->address, address);
        temp->next = NULL;
        success = 0;
    }

    return success;
}

/******************************************************************************
//
//  FUNCTIONNAME:   printRecord
//
//  DESCRIPTION:    printRecord function prints the specified record to screen.
//
//  PARAMETERS:     accNum  : Account number for the entry.
//
//  RETURNVALUES:   0   : Success.
//
******************************************************************************/

int llist::printRecord(int accNum)
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: llist::printRecord" << endl;
        cout << "accNum: " << accNum << endl;
    #endif

    record * temp = NULL;
    int success = 3;

    temp = this->start;
    while (temp != NULL)
    {
        if(temp->accountno == accNum)
        {
            cout << temp->accountno << endl;
            cout << temp->name << endl;
            cout << temp->address << endl;
            success = 0;
        }
        temp = temp->next;
    }

    return success;
}

/******************************************************************************
//
//  OPERATORNAME:   <<
//
//  DESCRIPTION:    << prints all records in the llist.
//
//  PARAMETERS:     myCout  : Reference to ostream cout.
//                  obj     : Reference to the llist object to print.
//
//  RETURNVALUES:   myCout  : All records in an ostream.
//
******************************************************************************/

ostream & operator << (ostream &myCout, const llist &obj)
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: llist::operator <<" << endl;
    #endif

    record * temp = NULL;

    temp = obj.start;
    while(temp != NULL)
    {
        myCout << temp->accountno << endl;
        myCout << temp->name << endl;
        myCout << temp->address << endl;
        myCout << endl;
        temp = temp->next;
    }
    return myCout;
}

/******************************************************************************
//
//  FUNCTIONNAME:   modifyRecord
//
//  DESCRIPTION:    modifyRecord function changes the specified address.
//
//  PARAMETERS:     accNum  : Account number for the entry.
//                  address : Pointer to the entry address.
//
//  RETURNVALUES:   0   : Success.
//
******************************************************************************/

int llist::modifyRecord(int accNum, char address[80])
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: llist::modifyRecord" << endl;
        cout << "accNum: " << accNum << endl;
        cout << "address[80]: " << address << endl;
    #endif

    record * temp = NULL;
    int success = 4;

    temp = this->start;
    while(temp != NULL)
    {
        if(temp->accountno == accNum)
        {
            strcpy(temp->address, address);
            success = 0;
        }
        temp = temp->next;
    }

    return success;
}

/******************************************************************************
//
//  FUNCTIONNAME:   deleteRecord
//
//  DESCRIPTION:    deleteRecord function removes the specified entry.
//
//  PARAMETERS:     accNum  : Account number for the entry.
//
//  RETURNVALUES:   0   : Success.
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
    int success = 5;

    temp = this->start;
    while(temp != NULL)
    {
        if(temp->accountno == accNum)
        {
            if(temp == this->start)
            {
                previous = this->start;
                start = (this->start)->next;
                temp = this->start;
                delete(previous);
                previous = NULL;
                success = 0;
            }
            else
            {
                previous->next = temp->next;
                delete(temp);
                temp = previous->next;
                success = 0;
            }
        }
        else
        {
            previous = temp;
            temp = temp->next;
        }
    }

    return success;
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
//  RETURNVALUES:   0   : Success.
//
******************************************************************************/

void llist::reverse()
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: llist::reverse" << endl;
    #endif

    this->start = this->reverse(this->start);
}
