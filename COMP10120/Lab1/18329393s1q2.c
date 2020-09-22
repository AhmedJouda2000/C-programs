/*
This is lab 1 question 2, Write a C program that allows you to enter your student
number from the keyboard and then prints each individual digit on a new line.
It should also sum the numbers.

This is the work of Ahmed Jouda (Student Number 18329393)
Created on 30/01/2019
*/

//include the needed libraries
#include<stdio.h>

//declare the main function that returns nothing
int main(void)
{

  /*
    declare the 3 integer values needed.
    "number" will store the user input (student number).
    "first_digit" will store the first digit of the student number.
    "digit" will continously store the next first_digit
  */
  int number, first_digit, digit;

  //Take user input for the 8 digit student number and store it in "number"
  printf("Enter your 8 digit student number:");
  scanf("%d", &number);

  //declare the divisors, x will be used to get the remaider and y will be used to divide in the loop
  int x = 10000000;
  int y = 1000000;

  /*
    To get the first digit, as its first we dont need to get the remainder so I
    took it out of the loop and just divided by 10000000 then printed it
  */
  first_digit = number/x;
  printf("%d\n", first_digit);

  /*
  Now I declare the integer sum where I will add all the digits, now I assign
  the first digit to it
  */
  int sum = first_digit;

  /*
  using this loop we iterate 7 more times to print the 7 other digits.
  At every iteration we get the remainder of the number using the modulus then
  divide by the divisor. Then we assign this to "digit" and print it. Then I divided
  both the divisor and the modulus divisor by 10 to get the next digit in the next iteration.
  And before the next iteration starts, I added the new digit to sum and assigned it to sum.
  */
  for (int i = 1; i < 8; i++)
  {
    digit = (number%x)/y;
    printf("%d\n", digit);
    x = x/10;
    y = y/10;
    sum = sum + digit;
  }


//print the sum
  printf("The sum is %d\n", sum);

}
