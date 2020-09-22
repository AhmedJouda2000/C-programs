/*
This is set 7 Question 4.

Write a C program which has the following functions:
a. A function called adder which has variable number of integers as arguments
and returns the sum of the integers/
b. A function called multiplier which has variable number of integers as
arguments and returns the product of the integers.
c. A function myPrinter which takes in a variable number of arguments of any
type and prints each one a separate line.

This is the work of Ahmed Jouda (Student Number 18329393)
Created on 28/03/2019
*/

//include the libraries needed
#include<stdio.h>
#include<stdarg.h>

//Declare the functions to be used in the program for compiler use
int myPrinter(const char *type, ...);
int adder(int i, ...);
int multiplier(int i, ...);

//define the main function that takes in nothing
int main(void)
{

//declare 4 variables and intialise them to any values you want
int x = 7;
int y = 10;
int z = 3;
int w = 2;

//print the sum of the numbers by calling the adder funtion with the variables
//as arguments and the number of the variables before them, in this case 4
printf("\nThe sum of the numbers is: %d\n", adder(4, x, y, z ,w));
printf("\n");

//print the product of the numbers by calling the multiplier funtion with the
//variables as arguments and the number of the variables before them, in this
// case 4
printf("The product of the numbers is: %d\n", multiplier(4, x, y, z, w));
printf("\n");

/*
  call the myPrinter function with arguments of what u want to print, first
  argument must specify the types of the elements to be printed (s = string,
  f = float, d = integer etc.), then the rest of the arguments are the actual
  elements to be printed.
*/
//Therefore this will print the 2 int, then 2 floats, then 2 strings
myPrinter("ddffss", 7, 10, 99.92, 97.7, "Gavin", "COMP10120");

}

//define the function "adder" that takes in a variable number of integers
//it returns an integer which is the sum of the arguments
int adder(int i, ...)
{
  //declare an integer "total" and intialise it to 0
  //it will store the sum contiously
  int total = 0;

  va_list ap; //stores information needed by va_start, va_arg and va_end
  va_start(ap, i);  //intialises the va_list object

  /*
    Using a for loop process the variable length argument list (hence va_arg).
    Each time va_arg is called, the nexr argument is used.
    It will iterate through them and add each variable to the total and assign
    that to total
  */
  for (size_t j = 1; j <= i; ++j)
  {
    total += va_arg(ap, int);
  }

  va_end(ap); //clean up variable length argument list
  return total; //return the total sum of the arguments
}

//define the function "multiplier" that takes in a variable number of integers
//it returns an integer which is the product of the arguments
int multiplier(int i, ...)
{
  //declare an integer "total" and intialise it to 1 (As 0 wouldnt work here)
  //it will store the product contiously
  int total = 1;

  va_list ap; //stores information needed by va_start, va_arg and va_end
  va_start(ap, i);  //intialises the va_list object

  /*
    Using a for loop process the variable length argument list (hence va_arg).
    Each time va_arg is called, the nexr argument is used.
    It will iterate through them and multiply each variable by the total and
    assign that to total.
  */
  for (size_t j = 1; j <= i; ++j)
  {
    total *= va_arg(ap, int);
  }

  va_end(ap); //clean up variable length argument list
  return total; //return the total product of the arguments
}


//define the function "myPrinter" that takes in a variable number of arguments
//it returns nothing, it prints out each argument on a new line
int myPrinter(const char *type, ...)
{
    va_list az; //stores information needed by va_start, va_arg and va_end
    int tally;

    va_start(az, type);  //intialises the va_list object

    tally = 0; //to keep count of what argument number this is

    //using a while loop, we keep iterating through the arguments until the
    //first one, "ddffss", reaches a null terminator
    while (*type != '\0')
    {
        //using a switch statement to determine what is the type of the argument
        //eveytime we do this step we increment the pointer to the string type
        //to get the next char in "ddffss"
        switch (*type++)
        {
            /*if *type points to a "d" we printout the argument number(tally)
            and the argument itself, this one would be an integer hence the %d*/
            case 'd':
                fprintf(stdout, "Argument number %d: %d\n", tally, va_arg(az, int));
                break;
            /*if *type points to a "f" we printout the argument number(tally)
            and the argument itself, this one would be a float hence the %f */
            case 'f':
                fprintf(stdout, "Argument number %d: %f\n", tally, va_arg(az, double));
                break;
            /*if *type points to an "s" we printout the argument number(tally)
            and the argument itself, this one would be a string hence the %s */
            case 's':
                fprintf(stdout, "Argument number %d: %s\n", tally, va_arg(az, const char *));
                break;
        }

        //increment tally each time we are done with one of the arguments
        tally ++;
    }
    va_end(az); //clean up variable length argument list
    return 0; //return nothing
}
