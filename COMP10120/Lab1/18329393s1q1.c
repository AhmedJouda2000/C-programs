/*
This is lab 1 question 1, Write a C program that inputs the height of 3 children in a class (in cm).
The programme should then calculate the tallest, shortest and the average height.

This is the work of Ahmed Jouda (Student Number 18329393)
Created on 30/01/2019
*/

//include the libraries needed
#include<stdio.h>

//declare the main function that returns nothing
int main(void)
{
  //declare the 3 variables we want to find, they have to be floats in case the averge has decimals
  float average, tallest, shortest;
  //declare a float array to store the user input in it
  float h[3];

  //take input from the user and store the input into the array
  printf("Enter height 1:\n");
  scanf("%f", &h[0]);
  printf("Enter height 2:\n");
  scanf("%f", &h[1]);
  printf("Enter height 3:\n");
  scanf("%f", &h[2]);

  //Now to get the average assign the value of the 3 numbers added and divided by 3 to the variable "average" and print that
  average = (h[0] + h[1] + h[2])/3;
  printf("The average is: %f\n", average);

  /*
    Assign the 1st inputed value to the variable "tallest"
    Then loop over the other inputed values and compare them to
    variable "tallest", if they are bigger then place them into
    "tallest" instead. By the end of the loop we will have the
    tallest value in the variable "tallest", then we can print it
  */
  tallest = h[0];
  for (int i =1; i < 3; i++)
  {
    if (tallest<h[i])
    {
    tallest = h[i];
    }
  }
printf("The tallest is %f\n", tallest);

/*
  Assign the 1st inputed value to the variable "shortest"
  Then loop over the other inputed values and compare them to
  variable "shortest", if they are smaller then place them into
  "shortest" instead. By the end of the loop we will have the
  shortest value in the variable "shortest", then we can print it
*/
  shortest = h[0];
  for (int j = 1; j < 3; j++)
  {
    if (shortest>h[j])
    {
    shortest = h[j];
    }
  }
  printf("The shortest is %f\n", shortest);


}
