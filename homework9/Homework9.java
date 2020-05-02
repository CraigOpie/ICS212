/**
 * <h1>Homework 9</h1>
 * The core concept for this lesson is the ability to code homework1 with Java handling the user interface.
 *
 * @author  Craig Opie
 * @version 1.0, 05/01/20
 * @throws  Exception
 * @class   SelectionSort
 * @concept This class demonstrates in depth understanding of JNI.
 *
 */
import java.util.Scanner;   // Required for user input

/**
 * <h2>Homework9</h2>
 * Demonstrates user interface calling JNI.
 *
 * @param userInput  Stores the user's input for exiting the program (Local Variable).
 *
 */
public class Homework9 
{
    /**
     * <h2>Native Code</h2>
     * This method loads the native library.
     *
     */
    static
    {
        System.loadLibrary("Homework9");
    }
    
    private native double convert(double inches);

    public static void main(String[] args) throws Exception {

        // Inform the user about this program
        System.out.println("** This program demonstrates in depth understanding of JNI **");
        System.out.println("");
        System.out.println("This program uses a for-loop to generate a list of inches vs");
        System.out.println("centimeters, starting from 0 inches to the user provided number,");
        System.out.println("with an interval of 0.50 inches (input must be > 0).");

        // Create scanner object to capture user input
        Scanner input_ = new Scanner(System.in);
        boolean loop = true;
        double userInput = 0.0;

        while(loop)
        {
            // Tell the user what you want for an input
            System.out.print("Please enter the maximum inches to show: ");

            // Verify the user entered an appropriate value
            try {
                if(!(input_.hasNextDouble())) throw new Exception();
                userInput = input_.nextDouble();
                if(userInput <= 0) throw new Exception();
                loop = false;
            }

            // The user did not enter a valid value so inform them and clear the input buffer
            catch (Exception e) {
                System.out.println("Error: Input must be a positive integer.  Please try again.");
                input_.nextLine();
            }
        }

        // The user wants to run the program
        input_.close();
        double loops = (userInput * 2);
        double inch;

        for(int i = 0; i <= loops; i++)
        {
            inch = (i / 2.0);
            if(i == 0)
            {
                System.out.format("%8s%12s%n", "inch", "cm");
            }
            System.out.format("%8.2f%12.2f%n", inch, new Homework9().convert(inch));
        }
    }
}
