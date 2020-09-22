/*
This is set 2 Question 5. Using recursive techniques, write a C program to
convert a decimal to binary.

To show your understanding and reasoning of the approach, provide a demonstration of how the conversion works in comments at the start of the program.

This is the work of Ahmed Jouda (Student Number 18329393)
Created on 07/02/2019
*/

/*
For example: 2
convert(2) = 2%2 + 10(convert(1))
convert(1) = 1%2 + 10(convert(0))
convert(0) = 0
Sub back:
so convert 1 = 1 + 0 = 1
so convert 2 = 0 + 10 = 10 which is correct!

We can confirm this by regular binary conversion:
2%2 = 0
1%2 = 1
hence 2 = 10
*/

//Include libraries needed
#include <stdio.h>

//insert the prototypes of the functions to be used
int convert(int dec);

//Define the main function that returns nothing
int main(void)
{
  //Declare the integer "decimal", where we will place the user input
  int decimal;

  //Take user input for the decimal number and place it into the variable "decimal"
  printf("Input a decimal number: ");
  scanf("%d", &decimal);

  //Print the binary number, which is the return from the function call convert
  printf("Binary number: %d", convert(decimal));

}

//This funtion takes in one variable and returns its binary format
int convert(int dec)
{
  //The base case is that if the number is 0 then return 0
  if (dec == 0)
  {
    return 0;
  }
  //Else implement the following formula recurringly until the base case is reached then sub back in
  else return (dec%2 + 10 * convert(dec/2));
}
