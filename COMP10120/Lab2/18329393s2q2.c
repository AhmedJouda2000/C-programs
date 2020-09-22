/*
This is set 2 Question 2. Write a function in C that calculates the day of the
week based on a date. You should also provide implementation to test the function.

This is the work of Ahmed Jouda (Student Number 18329393)
Created on 05/02/2019
*/

//Include libraries needed
#include <stdio.h>

//insert the prototypes of the functions to be used
int test(void);
int dayofweek(int d, int m, int y);

//Define the main function that returns nothing
int main(void)
{
  //Declare the 3 integer values that we will need to take from the user
  int day, month, year;

  //only continue with the program if the test function passes (returns 0)
  if (test() == 0)
  {
    //Declare the integer x and assign it the value 1, it will be used as a test if the input was enetred correctly by the user
    int x = 1;
    int daynumber;

    //Repeat this loop as long as the wrong format is being entered (x=1)
    while (x == 1)
    {
      //Take input for the date and assign it into the variables previosuly created
      printf("Enter the date in this format: day/month/year\n");
      scanf("%d/%d/%d", &day, &month, &year);

      //Check using an if statement if day, month and year entered are in a valid range
      if ((day<32&&day>0)&&(month>0&&month<13)&&year>0)
      {
        //if they are pass the values into the function "dayofweek" and Assign 0 to x to break the loop
        daynumber = dayofweek(day,month,year);
        x = 0;
      }
      //If the entered variables werent valid print "Wrong format" and therefore the loop will iterate
      else printf("\n**Wrong date Format Try again**\n");
    }
    //Print day number
    printf("The day is number: %d\n", daynumber);

    //To convert the day number to its name using a 2d array by mapping the number to the name
    char dayname [7][10] = {{"Saturday"}, {"Sunday"}, {"Monday"}, {"Tuesday"}, {"Wednesday"}, {"Thursday"}, {"Friday"}};
    //Print day name
    printf("The day is: %s\n", dayname[daynumber]);

  }
}


//This function takes in 3 integers that were provided by the user and returns number of day
//inside it, it prints both the day number and day name
int dayofweek(int d, int m, int y)
{
  //declare the integer variable "daynumber"
  int daynumber;

  //The formula specifies that january and february count as month 13 and 14 of the previous year
  //The following if statement implements that
  if (m == 1 || m == 2)
   {
     y -= 1;
     m += 12;
   }

  //For ease of read of formula, compress sum expressions into variables
  int q = d;
  int k = (y%100);
  int j = (y/100);

  //Assign the day number thats calculated using the formula provided to the variable "daynumber"
  daynumber = (q + ((13*(m+1))/5) + k + (k/4) + (j/4) + (5*j)) %7;


  //return the day number
  return daynumber;
}


//This function is called at the very start to test if the program runs correctly
//It returns either 0 or 1 to show that the program either passed of failed
int test(void)
{
  //I was born on Sunday 31/12/2000 so I will use that to test the program
  int day = 31, month = 12, year = 2000;
  int solution;
  //Sunday has the day number 1 so assign that to solution
  solution = 1;

  //Check if solution and the return from the dayofweek funtion is the same
  if (solution == dayofweek(day,month,year))
  {
    //If it is then we print the test has passed and return 0
    printf("\nTest has passed!\n\n");
    return 0;
  }
  
  else
  {
    //if they arent the same then we print the test has failed and return 1
    printf("\nTest has failed!\n\n");
    return 1;
  }
}
