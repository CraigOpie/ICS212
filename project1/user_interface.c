/*******************************************************************************
//
//  NAME:          Craig Opie
//
//  HOMEWORK:      project1
//
//  CLASS:         ICS 212
//
//  INSTRUCTOR     Ravi Narayan
//
//  DATE:          Feb 11, 2020
//
//  FILE:          user_interface.c
//
//  DESCRIPTION:   This file uses functions to interact with the user to allow
//                 the user to navigate a menu to access and modify a database.
//
******************************************************************************/

#include <stdio.h>
#include <time.h>
#include <string.h>
#include "user_interface.h"

/******************************************************************************
//
//  FUNCTION NAME: introMessage
//
//  DESCRIPTION:   introMessage function prints a description about the program
//                 for the user upon first loading the program.
//
//  PARAMETERS:    None.
//
//  RETURN VALUES: None.
//
******************************************************************************/

void introMessage()
{
    if (debugMode == 0)
    {
        printf("\n\nFUNCTION NAME: introMessage\n");
    }
    printf("\n");
    printf("================================================================");
    printf("================\n\n");
    printf("Welcome to the 'School of Hard Knocks' Student Banking and ");
    printf("Transaction System\n");
    printf("================================================================");
    printf("================\n");
}

/******************************************************************************
//
//  FUNCTION NAME: menu
//
//  DESCRIPTION:   Provides the user with an interface menu to navigate the
//                 program and its features.
//
//  PARAMETERS:    dataBase : Pointer to the record database.
//
//  RETURN VALUES: 0 : Continue Loop
//                 1 : Exit Loop
//
******************************************************************************/

int menu(struct record ** dataBase)
{
    char user_input[3];
    int option;

    if (debugMode == 0)
    {
        printf("\n\nFUNCTION NAME: menu\n");
    }

    printf("\nPlease choose a menu option by typing the corresponding number ");
    printf("and pressing enter.\n");
    printf("1: Add a new record.\n");
    printf("2: Print a record.\n");
    printf("3: Print all records.\n");
    printf("4: Change a records address.\n");
    printf("5: Delete a record.\n");
    printf("6: Quit.\n");

    printf("Option: ");
    fgets(user_input, 3, stdin);

    option = (int)user_input[0];
    if (option > 48 && option < 55)
    {
        option -= 48;
    }
    else
    {
        option = 0;
    }
    
    return callMenuItem(dataBase, option);
}

/******************************************************************************
//
//  FUNCTION NAME: callMenuItem
//
//  DESCRIPTION:   Uses a switch statement to direct which functions to call
//                 based on the users menu item selection.
//
//  PARAMETERS:    dataBase : Pointer to the record database.
//                 choice   : Indicates the menu item selected by the user.
//
//  RETURN VALUES: 0 : Success.
//                 1 : Failure or user quits.
//
******************************************************************************/

int callMenuItem(struct record ** dataBase, int choice)
{
    int result = 0;

    if (debugMode == 0)
    {
        printf("\n\nFUNCTION NAME: callMenuItem\n");
        printf("choice: %d\n", choice);
    }
    
    switch(choice)
    {
        case 1: result = userAddRecord(dataBase);
                break;
        case 2: result = userPrintRecord(*dataBase);
                break;
        case 3: printAllRecords(*dataBase);
                break;
        case 4: result = userModifyRecord(*dataBase);
                break;
        case 5: result = userDeleteRecord(dataBase);
                break;
        case 6: result = 1;
                break;
        default:printf("Invalid input.  Please try again.\n\n");
    }

    return result;
}

/******************************************************************************
//
//  FUNCTION NAME: userAddRecord
//
//  DESCRIPTION:   Obtains the account number, name, and address of the new
//                 user and creates the record in the database.
//
//  PARAMETERS:    dataBase : Address of a pointer to the new record in the 
//                            database.
//
//  RETURN VALUES: 0 : Success.
//
******************************************************************************/

int userAddRecord(struct record ** dataBase)
{
    int accNum = 0;
    char name[25];
    char address[80];

    if (debugMode == 0)
    {
        printf("\n\nFUNCTION NAME: userAddRecord\n");
    }

    printf("Please enter the account number:\n");
    accNum = getIntFromUser();
    printf("\nPlease enter name (press Enter twice to exit):\n");
    getName(name, 25);
    printf("Please enter the address (press Enter twice to exit):\n");
    getAddress(address, 80);
    addRecord(dataBase, accNum, name, address);

    return 0;
}

/******************************************************************************
//
//  FUNCTION NAME: userPrintRecord
//
//  DESCRIPTION:   Obtains the account number from the user and prints the
//                 record information.
//
//  PARAMETERS:    dataBase : Pointer to the record location.
//
//  RETURN VALUES: 0 : Success.
//
******************************************************************************/

int userPrintRecord(struct record * dataBase)
{
    int accNum = 0;
    
    if (debugMode == 0)
    {
        printf("\n\nFUNCTION NAME: userPrintRecord\n");
    }
    
    printf("Please enter the account number:\n");
    accNum = getIntFromUser();
    printRecord(dataBase, accNum);

    return 0;
}

/******************************************************************************
//
//  FUNCTION NAME: userModifyRecord
//
//  DESCRIPTION:   Obtains the account number and new address from the user
//                 and updates the record in the database.
//
//  PARAMETERS:    dataBase : Pointer to the record location.
//
//  RETURN VALUES: 0 : Success.
//
******************************************************************************/

int userModifyRecord(struct record * dataBase)
{
    int accNum = 0;
    char address[80];

    if (debugMode == 0)
    {
        printf("\n\nFUNCTION NAME: userModifyRecord\n");
    }

    printf("Please enter the account number:\n");
    accNum = getIntFromUser();
    printf("\nPlease enter the address (press Enter twice to exit):\n");
    getAddress(address, 80);
    modifyRecord(dataBase, accNum, address);

    return 0;
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

int userDeleteRecord(struct record ** dataBase)
{
    int accNum = 0;
    
    if (debugMode == 0)
    {
        printf("\n\nFUNCTION NAME: userDeleteRecord\n");
    }
    
    printf("Please enter the account number:\n");
    accNum = getIntFromUser();
    deleteRecord(dataBase, accNum);

    return 0;
}

/******************************************************************************
//
//  FUNCTION NAME: getIntFromUser
//
//  DESCRIPTION:   Takes a string input and performs checks to ensure it is an
//                 integer value, then convers the useable string values to an
//                 integer.  The value is returned for use.
//
//  PARAMETERS:    None.
//
//  RETURN VALUES: int : Value inputed from the user.
//
******************************************************************************/

int getIntFromUser()
{
    char user_input[25];
    int i;
    int size_user_input = 0;
    int bad_input = 1;
    int length = 25;
    int digits;
    int valid_int;
    
    if (debugMode == 0)
    {
        printf("\n\nFUNCTION NAME: getIntFromUser\n");
    }
    
    do
    {
        fgets(user_input, 25, stdin);

        for (i = 0; i < length; i++)
        {
            if (((int)user_input[i] > 47) && ((int)user_input[i] < 58))
            {
                user_input[size_user_input] = user_input[i];
                size_user_input++;
            }
        }
        for (i = (size_user_input - 1); i < length; i++)
        {
            user_input[i] = '\0';
        }
        for (i = 0; i < length; i++)
        {
            if ((int)user_input[i] == 3)
            {
                user_input[i] = '\0';
            }
        }
        digits = 0;
        valid_int = 0;
        for (i = size_user_input; i >= 0; i--)
        {
            if (((int)user_input[i] > 47) && ((int)user_input[i] < 58))
            {
                bad_input = 0;
                valid_int += (exponent(10, digits) * ((int)user_input[i] - 48));
                digits++;
            }
        }
        if (((int)user_input[0] == 45) || (valid_int <=0))
        {
            bad_input = 1;
        }
        for (i = 0; i < size_user_input; i++)
        {
            if ((int)user_input[i] == 46)
            {
                bad_input = 1;
            }
        }
        if (bad_input == 1)
        {
            printf("That value was not a valid integer. ");
            printf("Please try again.\n");
            for (i = 0; i < 25; i++)
            {
                user_input[i] = '\0';
            }
        }
    }
    while(bad_input == 1);

    return(valid_int);
}

/******************************************************************************
//
//  FUNCTION NAME: getName
//
//  DESCRIPTION:   Function that gets input from the user and stores the value
//                 in an array who's address was passed into the function.
//                 The array does not allow special chars besides a space.
//
//  PARAMETERS:    text : Pointer to the location where the address will be
//                        stored.
//                 size : Integer specifying the size of the array.
//
//  RETURN VALUES: None.
//
******************************************************************************/

void getName(char * text, int size)
{
    int i;
    char currentChar;
    
    if (debugMode == 0)
    {
        printf("\n\nFUNCTION NAME: getName\n");
        printf("size: %d\n", size);
    }

    for (i = 0; i < size; i++)
    {
        currentChar = fgetc(stdin);

        if (((int)currentChar == 32) || (currentChar == '\n') ||
        (((int)currentChar > 64) && ((int)currentChar < 91)) ||
        (((int)currentChar > 96) && ((int)currentChar < 123)))
        {
            text[i] = currentChar;
        }

        if (text[i] == '\n' && text[i-1] == '\n')
        {
            text[i-1] = '\0';
            for (i = i; i < size; i++)
            {
                text[i] = '\0';
            }
        }
    }
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

void getAddress(char * text, int size)
{
    int i;
    
    if (debugMode == 0)
    {
        printf("\n\nFUNCTION NAME: getAddress\n");
        printf("text: %s\n", text);
        printf("size: %d\n", size);
    }

    for (i = 0; i < size; i++)
    {
        text[i] = fgetc(stdin);
        if (text[i] == '\n' && text[i-1] == '\n')
        {
            text[i-1] = '\0';
            for (i = i; i < size; i++)
            {
                text[i] = '\0';
            }
        }
    }
}

/******************************************************************************
//
//  FUNCTION NAME: exponent
//
//  DESCRIPTION:   exponent function returns the int of the base raised to the
//                 exp specified by the call.
//
//  PARAMETERS:    base : The radix of the number system
//                 exp  : The distance from the radix point
//
//  RETURN VALUES: int  : The result of the math.
//
******************************************************************************/

int exponent(int base, int exp)
{
    int i;
    int number =1;
    
    if (debugMode == 0)
    {
        printf("\n\nFUNCTION NAME: exponent\n");
        printf("base: %d\n", base);
        printf("exp: %d\n", exp);
    }

    for (i = 0; i < exp; ++i)
    {
        number *= base;
    }
    return(number);
}
