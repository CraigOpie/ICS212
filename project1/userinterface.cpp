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
//  FILE:           userinterface.cpp
//
//  DESCRIPTION:    This file declares the function used for user interaction.
//
******************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include "llist.h"
#include "userinterface.h"
using namespace std;

/******************************************************************************
//
//  FUNCTIONNAME:   manFile
//
//  DESCRIPTION:    manFile function informs the user about using arguments
//
//  PARAMETERS:     None.
//
//  RETURNVALUES:   None.
//
******************************************************************************/

void manFile()
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: manFile" << endl;
    #endif

    cout << "NAME\n\tproject2 - bank database application\n\n"
            "SYNOPSIS\n\tproject2 [none]\n\n"
            "DESCRIPTION\n\tproject2 allows a banker to create, modify, view"
            "\n\tand delete information about clients.\n\n"
            "OPTIONS\n\tnone\n\t\tNo options are available for this"
            "\n\t\tapplication.\n" << endl;
}

/******************************************************************************
//
//  FUNCTIONNAME:   main
//
//  DESCRIPTION:    A userinterface function that asks the user for an integer
//                  and then verifies that the user did not enter a negative
//                  value or decimal place.  The function also ignores inputs
//                  that are not integers = such as charaters = and produces
//                  an error message if the value is not as expected.
//
//  PARAMETERS:     None
//
//  RETURNVALUES:   0 : success
//
******************************************************************************/

int main(int argc, char *argv [])
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: main" << endl;
    #endif
    llist dataBase;
    int result = 0;

    // directs the user to the program manual when too many parameters are used
    if(argc > 1)
    {
        manFile();
    }
    else
    {
        // informs the user about the program's purpose and displays a welcome
        cout << "This program allows a banker to create, modify, view, \n"
            "and delete information about clients.\n     " << endl;
        cout << "========================================="
                "========================================" << endl;
        cout << "  Welcome to the 'School of Hard Knocks' Student Banking "
                "and Transaction System" << endl;
        cout << "========================================="
                "========================================" << endl;
        // loop through the application until the user quits or an error occurs
        while(result == 0)
        {
            result = menu(dataBase);
            if(result > 1)
            {
                // error statements based on return values
                cout << "ERROR: ";
                switch(result)
                {
                    case 2: cout << "Record not able to be created" << endl;
                            break;
                    case 3: cout << "Record not found nor printed" << endl;
                            break;
                    case 4: cout << "Record not found nor modified" << endl;
                            break;
                    case 5: cout << "Record not found nor deleted" << endl;
                            break;
                }
                result = 0;
            }
        }
        // exit value is '1' and not an error => set to normal return value
        if(result == 1)
        {
            result = 0;
        }
        else
        {
            // unexpected result and occured causing the program to close
            cout << "FATAL ERROR: Unexpected return value." << endl;
        }
    }
    return result;
}

/******************************************************************************
//
//  FUNCTIONNAME:   menu
//
//  DESCRIPTION:    Provides the user with an interface menu to navigate the
//                  program and its features.
//
//  PARAMETERS:     dataBase : Pointer to the record database.
//
//  RETURNVALUES:   0 : Continue Loop
//                  1 : Exit Loop
//                  2 : Record not able to be created
//                  3 : Record not found and not printed
//                  4 : Record not found and not modified
//                  5 : Record not found and not deleted
//
******************************************************************************/

int menu(llist &dataBase)
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: menu" << endl;
    #endif
    int choice;
    int result = 0;

    cout << "Please choose a menu option by typing the corresponding number\n"
            "and pressing enter.\n"
            "1: Add a new record.\n"
            "2: Print a record.\n"
            "3: Print all records.\n"
            "4: Change a records address.\n"
            "5: Delete a record.\n"
            "6: Reverse the list.\n"
            "7: Quit.\n";
    cout << "Option: ";

    while ((!(cin >> choice)) || (choice <= 0) || (choice > 7))
    {
        cout << "ERROR: You must enter a valid integer.";
        cin.clear();
        cin.ignore(999, '\n');
        cout << "Option: ";
    }

    switch(choice)
    {
        case 1: result = userAddRecord(dataBase);
                break;
        case 2: result = userPrintRecord(dataBase);
                break;
        case 3: cout << (dataBase);
                break;
        case 4: result = userModifyRecord(dataBase);
                break;
        case 5: result = userDeleteRecord(dataBase);
                break;
        case 6: dataBase.reverse();
                break;
        case 7: result = 1;
                break;
        default:cout << "Invalid input. Please try again.\n\n";
    }
    
    return result;
}

/******************************************************************************
//
//  FUNCTIONNAME:   userAddRecord
//
//  DESCRIPTION:    Obtains the account number, name, and address of the new
//                  user and creates the record in the database.
//
//  PARAMETERS:     dataBase : Address of a pointer to the new record in the 
//                            database.
//
//  RETURNVALUES:   0 : Success.
//
******************************************************************************/

int userAddRecord(llist &dataBase)
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: userAddRecord" << endl;
    #endif
    int accNum;
    int success;
    char name[25] = "";
    char address[80] = "";

    accNum = getAccNo();
    getName(name);
    getAddress(address);
    success = dataBase.addRecord(accNum, name, address);

    return success;
}

/******************************************************************************
//
//  FUNCTIONNAME:   userPrintRecord
//
//  DESCRIPTION:    Obtains the account number from the user and prints the
//                  record information.
//
//  PARAMETERS:     dataBase : Pointer to the record location.
//
//  RETURNVALUES:   0 : Success.
//
******************************************************************************/

int userPrintRecord(llist &dataBase)
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: userAddRecord" << endl;
    #endif
    int accNum;
    int success;
    
    accNum = getAccNo();
    success = dataBase.printRecord(accNum);

    return success;
}

/******************************************************************************
//
//  FUNCTIONNAME:   userModifyRecord
//
//  DESCRIPTION:    Obtains the account number and new address from the user
//                  and updates the record in the database.
//
//  PARAMETERS:     dataBase : Pointer to the record location.
//
//  RETURNVALUES:   0 : Success.
//
******************************************************************************/

int userModifyRecord(llist &dataBase)
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: userModifyRecord" << endl;
    #endif
    int accNum;
    int success;
    char address[80] = "";

    accNum = getAccNo();
    getAddress(address);
    success = dataBase.modifyRecord(accNum, address);

    return success;
}

/******************************************************************************
//
//  FUNCTION NAME: userDeleteRecord
//
//  DESCRIPTION:   Obtains the account number from the user and deletes the
//                 associated record from the database.
//
//  PARAMETERS:    dataBase : Address of a Pointer to the record location.
//
//  RETURN VALUES: 0 : Success.
//
******************************************************************************/

int userDeleteRecord(llist &dataBase)
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: userDeleteRecord" << endl;
    #endif
    int accNum;
    int success;
    
    accNum = getAccNo();
    success = dataBase.deleteRecord(accNum);

    return success;
}

/******************************************************************************
//
//  FUNCTIONNAME:   getAccNo
//
//  DESCRIPTION:    Takes a string input and performs checks to ensure it is an
//                  integer value, then convers the useable string values to an
//                  integer.  The value is returned for use.
//
//  PARAMETERS:     None.
//
//  RETURNVALUES:   int : Value inputed from the user.
//
******************************************************************************/

int getAccNo()
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: getAccNo" << endl;
    #endif
    int userInt;

    cout << "Please enter the account number: " << endl;
    while ((!(cin >> userInt)) || (userInt <= 0))
    {
        cout << "ERROR: You must enter a valid integer." << endl;
        cin.clear();
        cin.ignore(999, '\n');
        cout << "Please enter the account number: ";
    }
    cin.clear();
    cin.ignore(999, '\n');

    return userInt;
}

/******************************************************************************
//
//  FUNCTIONNAME:   getName
//
//  DESCRIPTION:    Function that gets input from the user and stores the value
//                  in an array who's address was passed into the function.
//                  The array does not allow special chars besides a space.
//
//  PARAMETERS:     text : Pointer to the location where the address will be
//                         stored.
//
//  RETURNVALUES:   None.
//
******************************************************************************/

void getName(char * text)
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: getName" << endl;
    #endif
    int i;
    char currentChar = '\0';
    char clearBuff = '\0';
    int MAXSIZE = 25;

    cout << "Please enter name (press Enter twice to exit): " << endl;
    for (i = 0; i < MAXSIZE; i++)
    {
        currentChar = fgetc(stdin);

        if(((int)currentChar == 32) || (currentChar == '\n') ||
        (((int)currentChar > 64) && ((int)currentChar < 91)) ||
        (((int)currentChar > 96) && ((int)currentChar < 123)))
        {
            text[i] = currentChar;
        }

        if(text[i] == '\n' && text[i-1] == '\n')
        {
            text[i-1] = '\0';
            for (; i < MAXSIZE; i++)
            {
                text[i] = '\0';
            }
        }
    }

    if(text[MAXSIZE - 1] != '\0')
    {
        cout << "Your entry has been truncated to 24 characters." << endl;
        text[MAXSIZE - 1] = '\0';
        while(clearBuff != '\n')
        {
            clearBuff = fgetc(stdin);
        }
    }
    cin.clear();
}



/******************************************************************************
//
//  FUNCTION NAME: getAddress
//
//  DESCRIPTION:   Function that gets input from the user and stores the value
//                 in an array who's address was passed into the function.
//                 The array allows all special chars and return lines.
//
//  PARAMETERS:    text : Pointer to the location where the address will be
//                        stored.
//                 size : Integer specifying the size of the array.
//
//  RETURN VALUES: None.
//
******************************************************************************/

void getAddress(char * text)
{
    #ifdef DEBUGMODE
        cout << "FUNCTION NAME: getAddress" << endl;
    #endif
    int i;
    int MAXSIZE = 80;
    char clearBuff = '\0';

    cout << "Please enter the address (press Enter twice to exit): " << endl;
    for (i = 0; i < MAXSIZE; i++)
    {
        text[i] = fgetc(stdin);
        if (text[i] == '\n' && text[i-1] == '\n')
        {
            text[i-1] = '\0';
            for (; i < MAXSIZE; i++)
            {
                text[i] = '\0';
            }
        }
    }

    if(text[MAXSIZE - 1] != '\0')
    {
        cout << "Your entry has been truncated to 24 characters." << endl;
        text[MAXSIZE - 1] = '\0';
        while(clearBuff != '\n')
        {
            clearBuff = fgetc(stdin);
        }
    }
    cin.clear();
}
