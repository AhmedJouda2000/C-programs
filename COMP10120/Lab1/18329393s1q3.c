/*
This is lab 1 question 3, Write a C program that asks the quarry worker
to input the number of bags to be purchased and calculated the total cost.

This is the work of Ahmed Jouda (Student Number 18329393)
Created on 30/01/2019
*/

//include the libraries needed
#include<stdio.h>

//start the main function that returns nothing
int main(void)
{
  /*
    declare the variables we need, the integer input we will get from the user
    "bags" and the "price" whcih we will calculate, "price" must be a float as
    it may be a decimal number
  */
  int bags;
  float price;

  //We take user input for the number of bags to be bought and store that value into "bags"
  printf("Enter the number of bags to be purchased:\n");
  scanf("%d", &bags);

  /*
  As stated, the first if statement will be enetred if the number of bags
  purchased is between 1 and 10 inclusive, once it enters it will multiply the
  number of bags bought by 10 as stated and then assign that to the variable
  "price" and skip the other if statements
  */
  if (bags>=1 && bags <= 10)
  {
    price = bags * 10;
  }

    /*
      If the above case wasnt true then we check using the following else if statements
      if the number of bags purchased is between 11 and 50 inclusive. If it is then the
      else if statement is entered and we take away 10 from the number of bags and add
      100 to the price as those are fixed (10 bags * 10 euro) then add this to the rest
      of the bags multiplied by 9.5 euro as stated in the question. This is then assigned
      to the variable "price" and skips the rest else if statements.
    */
    else if (bags > 10 && bags <= 50)
    {
      price = (bags - 10)*9.50 + 100;
    }

    /*
      If the above 2 cases weren't true then we check if the number of bags is over
      50 as stated in the question. If it is the following statement is entered. We add
      a 100 to the price for the reason explained above, but more over we add 380 to the
      price as the bags between 11 and 50 are fixed at price 9.50 euro (40 bags * 9.50),
      then I take away 50 from the number of bags as we already added the price of the first
      50 bags and multiply the remainder by 9.00 euro as stated in the question. Those numbers
      are added and then assigned to the variable "price".
      If non of the if statements were entered that means the user inputed a value less than 1
      so the price shows up as 0.00 Euro.
    */
    else if (bags>50)
    {
      price = (bags - 50)*9 + 100 + 380;
    }

//Here I just printed the value in the variable "price" to show the cost of the bags
printf("The total price is %f Euros.\n", price);

}
