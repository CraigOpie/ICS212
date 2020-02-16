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
//  FILE:          user_interface.c
//
//  DESCRIPTION:   This file uses functions to interact with the user to allow
//                 the user to navigate a menu to access and modify a database.
//
******************************************************************************/

#include <stdio.h>
#include <time.h>
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
    printf("\n");
    printf("================================================================");
    printf("================\n\n");
    printf("Welcome to the 'School of Hard Knocks' Student Banking and ");
    printf("Transaction System\n");
    printf("================================================================");
    printf("================\n\n");
}

int menu(struct record * dataBase)
{
    char user_input[3];
    int option;

    printf("Please choose a menu option by typing the corresponding number ");
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

int callMenuItem(struct record * dataBase, int choice)
{
    int result = 0;
    switch(choice)
    {
        case 1: result = userAddRecord(&dataBase);
                break;
        case 2: result = userPrintRecord(dataBase);
                break;
        case 3: printAllRecords(dataBase);
                break;
        case 4: result = userModifyRecord(dataBase);
                break;
        case 5: result = userDeleteRecord(&dataBase);
                break;
        case 6: result = 1;
                break;
        default:printf("Invalid input.  Please try again.\n\n");
    }

    return result;
}

int userAddRecord(struct record ** dataBase)
{
    int accNum = 0;
    char name[25];
    char address[80];

    printf("Please enter the account number:\n");
    accNum = getIntFromUser();
    printf("\nPlease enter name (press Enter twice to exit):\n");
    getStringFromUser(name, 25);
    printf("Please enter the address (press Enter twice to exit):\n");
    getStringFromUser(address, 80);
    addRecord(dataBase, accNum, name, address);

    return 0;
}

int userPrintRecord(struct record * dataBase)
{
    int accNum = 0;
    
    printf("Please enter the account number:\n");
    accNum = getIntFromUser();
    printRecord(dataBase, accNum);

    return 0;
}

int userModifyRecord(struct record * dataBase)
{
    int accNum = 0;
    char address[80];

    printf("Please enter the account number:\n");
    accNum = getIntFromUser();
    printf("\nPlease enter the address (press Enter twice to exit):\n");
    getStringFromUser(address, 80);
    modifyRecord(dataBase, accNum, address);

    return 0;
}

int userDeleteRecord(struct record ** dataBase)
{
    int accNum = 0;
    
    printf("Please enter the account number:\n");
    accNum = getIntFromUser();
    deleteRecord(dataBase, accNum);

    return 0;
}

int getIntFromUser()
{
    char user_input[25];
    int i;
    int size_user_input;
    int bad_input = 1;
    int digits;
    int valid_int;
    do
    {
        fgets(user_input, 25, stdin);
        size_user_input = (sizeof(user_input) / sizeof(user_input[0]));
        digits = 0;
        valid_int = 0;
        for (i = (size_user_input -1); i >= 0; i--)
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
        }
    }
    while(bad_input == 1);

    return(valid_int);
}

void getStringFromUser(char * text, int size)
{
    int i;

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

int exponent(int base, int exp)
{
    int i;
    int number = 1;

    for (i = 0; i < exp; ++i)
    {
        number *= base;
    }
    return(number);
}
