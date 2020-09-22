/*
This is set 2 Question 3. Write a program in C that selects a random set
of numbers for the Thunderball draw. The C program should give a different
set of numbers each time.

This is the work of Ahmed Jouda (Student Number 18329393)
Created on 05/02/2019
*/

//Include libraries needed
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//Define the main function that returns nothing
int main(void)
{
  //Declare the integer loop counters needed and assign 0 to i
  int i=0,a;
  //Declare an interger array of size 5 to store the main numbers in
  int main_numbers[5];
  //Instead of inputing a seed every time, the following statement allows the seed to be determined at run time by the system
  srand (time(0));

  //loop to place random numbers between 1 and 39 into the 5 array spots
  //The following nested loops check if  any of the 5 numbers is a repeat of a previous one
  //If the number is a repeat then it randomises again
  while (i<5) {
    //we declare and assign integer r a random number at each iteration
    int r = rand() % 39 + 1;

  // Search the existing numbers to check if the new random number "r" has already been added to the array 
  for ( a = 0; a < i; a++ ) {
    if ( main_numbers[a] == r )
      break;
  }
  //If we broke early, don't do anything, if it didnt break assign "r" to the next array space and increment i
  if ( a == i )
    main_numbers[i++] = r;
}

   //declare a integer variable to be a loop counter
   int loop=0;

   //printing the 5 main numbers in a loop out of the array
   printf("Your main numbers are:\n");
   for (loop; loop < 5; loop++)
   {
     printf("%d ", main_numbers[loop]);
   }

   //printing a random number between 1 and 14 to be the thunderbolt number
   printf("\nYour thunderbolt number is:\n");
   printf("%d ", (rand() % 14) + 1);
}
