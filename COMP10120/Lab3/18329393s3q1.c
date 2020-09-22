/*
This is set 3 Question 1. Write a C program which is used to keep track of the
number of people passing a turn style at the local stadium. The program should
have four functions, one which is called when a person enters the stadium and
one which is called when a person leaves the stadium.  It costs €20 for a ticket
to the concert so a function should keep a track of total amount of money that
has been taken and print that to the screen. The final function should report
the current number of people at the concert.

This is the work of Ahmed Jouda (Student Number 18329393)
Created on 12/02/2019
*/

//include the libraries needed
#include <stdio.h>

//Declare the global variable "people_inside" and intialise it to 0, this means that it has a global scope over all the functions
int people_inside = 0;

//declare the prototypes of the functions to be used
void price(int value_of_x);
void people(void);
void leave(void);
void enter(void);

//define the main function that returns nothing
int main(void)
{
  //declare the integer variable 'x' which will be used to store the user's action temporarily
  int x;

  //start a while loop that doesnt break unless the user inputs 4 (end) into the variable "x"
  while (x!=4)
  {
      //Take user input for the action required and place it into the variable "x"
      printf("\n\nEnter your action:\n\n");
      printf("1) Person Enters\n2) Person Leaves\n3) Money collected\n4) End\n");
      scanf("%d", &x);

      //if the user inputs 1 (Person Enters) into "x" then call the following functions inside the statement
      if (x==1)
      {
        enter();
        //x is passed into the function "price"
        price(x);
        people();
      }

      //if the user inputs 2 (Person Leaves) into "x" then call the following functions inside the statement
      if (x==2)
      {
        leave();
        people();
      }

      //if the user inputs 3 (Money Collected) into "x" then call the following functions inside the statement
      if (x==3)
      {
        //x is passed into the function "price"
        price(x);
      }

      //If the user inputs a number not on the option (less than 1 or larger than 4) list printout "Invalid Input"
      if (x<1||x>4)
      {
        printf("Invalid input\n");
      }

  }

}

//Define the function "enter" that takes in and returns nothing
void enter(void)
{
  //Once the function "enter" is called the variable "people_inside" is incremented by 1
 people_inside++;
}

//Define the function "leave" that takes in and returns nothing
void leave(void)
{
  //Check using an if statement that there is people currently inside
  if (people_inside > 0)
  {
    //If there is then decrement the variable "people_inside" by one
    people_inside--;
  }
  //Else print out there is no people inside
  else printf("Noone is inside!\n");

}

//Define the function "people" that takes in and returns nothing
void people(void)
{
  //Once the function "people" is called print out the number of people currently inside
  printf("\nPeople inside: %d\n", people_inside);
}

//Define the function "price" that returns nothing and takes in an integer
void price(int value_of_x)
{
  //Declare a static local variable "price" meaning its lifetime is the same as the program's
  static int price;

  //Check if the function is called with the user input of "Person Enters"
  if (value_of_x == 1)
  {
    //if so then add 20 euros to the total collected money "price"
    price = price + 20;
  }

  //else check if the function is called with the user input of "Money Collected" (3)
  if (value_of_x == 3)
  {
    //if so then printout the variable "price" which has the total collected money
    printf("Collected money: %d Euro(s)\n", price);
  }
}
