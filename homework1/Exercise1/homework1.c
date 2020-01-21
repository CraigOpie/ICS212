/******************************************************************************
//
//  NAME:          Craig Opie
//
//  HOMEWORK:      1
//
//  CLASS:         ICS 212
//
//  INSTRUCTOR     Ravi Narayan
//
//  DATE:          Jan 14, 2020
//
//  FILE:          homework1.c
//
//  DESCRIPTION:   This program uses a function containing a for-loop to
//                 generate a list of inches vs centimeters, starting from 0
//                 inches to the user provided numer, with an interval of 0.50
//                 inches.
//
//
******************************************************************************/

#include <stdio.h>

int user_interface();
double convert(double);
void print_table(int);
int exponent(int, int);

/******************************************************************************
//
//  FUNCTION NAME: main
//
//  DESCRIPTION:   A userinterface function that asks the user for an integer
//                 and then verifies that the user did not enter a negative
//                 value or decimal place.  The function also ignores inputs
//                 that are not integers = such as charaters = and produces
//                 an error message if the value is not as expected.  These
//                 functions were accomplished deliberately using only the
//                 <stdio.h> header.
//
//  PARAMETERS:    None
//
//  RETURN VALUES: 0 : success
//
******************************************************************************/

int main()
{
    int user_int;

    printf("This program uses a for-loop to generate a list of inches vs\n"
           "centimeters, starting from 0 inches to the user provided number,\n"
           "with an interval of 0.50 inches (input must be > 0).\n\n");
    /* Get user input and verify it is a valid integer                       */
    user_int = user_interface();
    /* Take the valid input and print the conversion table for the user      */
    print_table(user_int);

    return(0);
}

/******************************************************************************
//
//  FUNCTION NAME: user_interface
//
//  DESCRIPTION:   A user interface function that asks the user for an integer
//                 and then verifies that the user did not enter a negative
//                 value or decimal place.  The function also ignores inputs
//                 that are not integers = such as characters = and produces
//                 an error message if the value is not as expected.  This
//                 function was accomplished deliberately using only the
//                 <stdio.h> header.
//
//  PARAMETERS:    None
//
//  RETURN VALUES: valid_int (int) : Integer value input by the user.
//
//  COMMENT:       Not using the Google Style Guide for function naming
//                 convention by direction of homework assignment.
//
******************************************************************************/

int user_interface()
{
    char user_input[6]; 
    int valid_int;
    int digits;
    int i;
    int bad_input = 1;
    int size_user_input;
    
    do
    {
        printf("Please enter the maximum inches to show: ");
        scanf("%s", user_input);
        /* Determine the number of digits entered by the user */
        size_user_input = (sizeof(user_input) / sizeof(user_input[0]));
        digits = 0;
        valid_int = 0;

        /* Only iterate over the values entered by the user and check if the */
        /* user entered a valid integer using the ASCII value of the char    */
        for (i = (size_user_input - 1); i >= 0; i--)
        {
            if (((int)user_input[i] > 47) && ((int)user_input[i] < 58))
            {
                bad_input = 0;
                /* Take the char[] and turn it into a useable integer        */
                valid_int += (exponent(10, digits) * ((int)user_input[i] - 48));
                digits++;
            }
        }
        /* If the user input a negative sign or a zero, reject the input     */
        if (((int)user_input[0] == 45) || (valid_int <= 0))
        {
            bad_input = 1;
        }
        /* If the user input a value with a decimal, reject the input        */
        for (i = 0; i < size_user_input; i++)
        {
            if ((int)user_input[i] == 46)
            {
                bad_input = 1;
            }
        }
        if (bad_input == 1)
        {
            printf("That value was not a valid integer.  Please try again\n");
        }
    }
    while(bad_input == 1);
    
    return(valid_int);
}    

/******************************************************************************
//
//  FUNCTION NAME: convert
//
//  DESCRIPTION:   Converts the provided double 'inch' value to centimeters
//                 as a double.
//
//  PARAMETERS:    inch (double) : Contains the user input as inches to be
//                                 converted to centimeters.
//
//  RETURN VALUES: (double) : Returns the converted inches to centimeters
//
//  COMMENT:       Not using the Google Style Guide for function naming
//                 convention by direction of homework assignment.
//
******************************************************************************/

double convert(double inch)
{
    return (inch * 2.54);
}

/******************************************************************************
//
//  FUNCTION NAME: print_table
//
//  DESCRIPTION:   Iterates over a loop to generate a list of inches vs
//                 centimeters, starting from 0 inches, to the user provided
//                 number with an interval of 0.50 inches.
//
//  PARAMETERS:    max_inch (int) : Contains the user provided end value for
//                                  the list.
//
//  RETURN VALUES: None
//
//  COMMENT:       Not using the Google Style Guide for function naming
//                 convention by direction of homework assignment.
//
******************************************************************************/

void print_table(int max_inch)
{
    int loops = (max_inch * 2);
    double inch;
    double cm;
    char string_inch[8];
    char string_cm[12];
    float i;

    for (i = 0.0; i <= loops; i++)
    {
        inch = (i / 2.0);
        cm = convert(inch);
        sprintf(string_inch, "%.2f", inch);
        sprintf(string_cm, "%.2f", cm);
        /* Print the header row for the table only on the first iteration    */
        if (i == 0.0)
        {
            printf("%8.8s %12.12s\n", "inch", "cm");
        }
        /* Print the remaining rows with the correct formatting for columns  */
        printf("%8.8s %12.12s\n", string_inch, string_cm);
    }
}


/******************************************************************************
//
//  FUNCTION NAME: exponent
//
//  DESCRIPTION:   Takes a radix (base) and raises it to the specified power
//                 (exp).  Then returns that value.
//
//  PARAMETERS:    base (int) : Contains the user specified radix value
//                 exp (int) : Contains the user specified exponent value
//
//  RETURN VALUES: number (int) : Value is the radix value raised to the exp
//
******************************************************************************/

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
