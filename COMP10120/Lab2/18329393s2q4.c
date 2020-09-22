/*
This is set 2 Question 4. Write a recursive function gcd that returns the
 greatest common divisor of x and y.

This is the work of Ahmed Jouda (Student Number 18329393)
Created on 06/02/2019
*/

//Include libraries needed
#include <stdio.h>

//insert the prototypes of the functions to be used
int gcd (int a, int b);

//Define the main function that returns nothing
int main (void)
{
  //Declare 2 integer variables x and y to place the user input in them later
  int x,y;

  //Take user input for the 2 number for which the gcd is to be found, place them in the variables "x" and "y"
  printf("Enter the 1st value: ");
  scanf("%d", &x);
  printf("Enter 2nd value: ");
  scanf("%d", &y);
  //Print the answer to the call of the function "gcd"
  printf("The GCD is %d\n", gcd(x,y));
}

//This function takes in 2 integer variables for which the gcd is to be found and returns the integer gcd
int gcd (int a, int b)
{
  //The base case is that if the 2nd integer is 0 then the gcd is the 1st integer so that is returned
  if (b == 0)
  {
    return a;
  }
  //Else we breakdown the problem by recurring the function gcd using the 2nd integer and the remainder of a/b
  else return gcd(b, a%b);
  //The recursion occurs till the base case is reached
  /*
For example:
12 and 9 are entered into gcd
therefore 9 and 3 are entered into gcd
therefore 3 and 0 are entered into gcd
so 3 is returned
  */
}
