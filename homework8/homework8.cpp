/******************************************************************************
//
//  NAME:           Craig Opie
//
//  HOMEWORK:       8
//
//  CLASS:          ICS 212
//
//  INSTRUCTOR:     Ravi Narayan
//
//  DATE:           Mar 30, 2020
//
//  FILE:           homework8.c
//
//  DESCRIPTION:    This program uses a function containing a for-loop to
//                  generate a list of inches vs centimeters, starting from 0
//                  inches to the user provided numer, with an interval of 0.50
//                  inches.
//
//
******************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

int user_interface();
void convert(double, double &);
void print_table(int);

/******************************************************************************
//
//  FUNCTIONNAME:   main
//
//  DESCRIPTION:    A userinterface function that asks the user for an integer
//                  and then verifies that the user did not enter a negative
//                  value or decimal place.  The function also ignores inputs
//                  that are not integers = such as charaters = and produces
//                  an error message if the value is not as expected.  These
//                  functions were accomplished deliberately using only the
//                  <stdio.h> header.
//
//  PARAMETERS:     None
//
//  RETURNVALUES:   0 : success
//
******************************************************************************/

int main (int argc, char *argv [])
{
    int user_int;

    cout << "This program generates a list of inches vs centimeters, \n"
            "starting from 0 inches to the user provided number, with an \n"
            "interval of 0.50 inches (input must be > 0).\n" << endl;
    user_int = user_interface();
    print_table(user_int);

    return 0;
}

/******************************************************************************
//
//  FUNCTIONNAME:   user_interface
//
//  DESCRIPTION:    A user interface function that asks the user for an integer
//                  and then verifies that the user did not enter a negative
//                  value or decimal place.  The function also ignores inputs
//                  that are not integers = such as characters = and produces
//                  an error message if the value is not as expected.  This
//                  function was accomplished deliberately using only the
//                  <stdio.h> header.
//
//  PARAMETERS:     None
//
//  RETURNVALUES:   valid_int (int) : Integer value input by the user.
//
******************************************************************************/

int user_interface()
{
    int user_input_int;
    
    cout << "Please enter the maximum inches to show: ";
    while ((!(cin >> user_input_int)) || (user_input_int <= 0))
    {
        cout << "ERROR: You must enter a valid integer: ";
        cin.clear();
        cin.ignore(999, '\n');
    }

    return (user_input_int);
}    

/******************************************************************************
//
//  FUNCTIONNAME:   convert
//
//  DESCRIPTION:    Converts the provided double 'inch' value to centimeters
//                  as a double.
//
//  PARAMETERS:     inch (double) : Contains the user input as inches to be
//                                  converted to centimeters.
//                  cm (double &) : Contains the location of the cm value.
//
//  RETURNVALUES:   None
//
******************************************************************************/

void convert(double inch, double & cm)
{
    cm = (inch * 2.54);
}

/******************************************************************************
//
//  FUNCTIONNAME:   print_table
//
//  DESCRIPTION:    Iterates over a loop to generate a list of inches vs
//                  centimeters, starting from 0 inches, to the user provided
//                  number with an interval of 0.50 inches.
//
//  PARAMETERS:     max_inch (int) : Contains the user provided end value for
//                                   the list.
//
//  RETURNVALUES:   None
//
******************************************************************************/

void print_table(int max_inch)
{
    double cm;
    double inch;
    float i;
    int loops = (max_inch * 2);

    cout.precision(2);
    cout.width(10);

    for (i = 0.0; i <= loops; i++)
    {
        inch = (i / 2.0);
        convert(inch, cm);
        if (i == 0.0)
        {
            cout << right << setw(10) << setfill(' ') << "inch";
            cout << right << setw(10) << setfill(' ') << "cm" << endl;
        }
        cout << right << setw(10) << setfill(' ') << fixed << inch;
        cout << right << setw(10) << setfill(' ') << fixed << cm << endl;
    }
}
