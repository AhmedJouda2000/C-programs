/*
This is set 3 Question 4. Write a C Program that creates a two-dimensional array
to record the average daily acceleration of 5 of your customers over the past 10
trips. The data are shown below. The program should prompt you (the user) for a
driver number and then return the data of that driver along with a summary of the
data and some advice regarding the discount.

This is the work of Ahmed Jouda (Student Number 18329393)
Created on 14/02/2019
*/

//include the libraries needed
#include <stdio.h>

//define the main function that returns nothing
int main(void)
{
  //declare the integer variable "driver_number" which we will store in the user input for driver number
  int driver_number;

  //Take user input for the driver number and assign it to the integer variable "driver_number"
  printf("Enter the driver number:\n");
  scanf("%d", &driver_number);

  //Declare and intialise the 2d array "drivers" that has 5 rows and 10 columns
  //Store in it the average accelerations given in the question for each driver
  int drivers[5][10] = {
      {3,1,3,4,6,7,3,2,5,3},
      {2,2,2,3,4,4,3,3,3,2},
      {5,6,7,6,5,3,3,3,3,3},
      {3,3,3,3,4,4,3,2,1,3},
      {2,3,4,6,6,2,5,1,3,3},
    };



  //The following is to find the maximum acceleration of the selected driver
  //declare an integer variable "max" and assign to it the first average acceleration value of the selected driver
  int max;
  max = drivers[driver_number-1][0];

  //Then iterate over the entire row to see if that driver has a higher average acceleration
  for (size_t i = 1; i < 11; i++)
  {
    //if the there is a higher value in that row then assign it to "max"
    if (drivers[driver_number-1][i]>max)
    {
      max = drivers[driver_number-1][i];
    }
  }



  //The following is to find the average of the average daily accelerations of the selected driver
  //Declare a float variable "driver_average" that will be assigned the driver's average of his average accelerations
  float driver_average;
  //iterate over the entire row that contains the driver's daily average accelerations and sum all of them and assign it to the variable "driver_average"
  for (size_t j = 0; j < 10; j++)
  {
    driver_average += drivers[driver_number-1][j];
  }
  //Then divide the value in "driver_average" by 10 and assign it back to "driver_average" to get the average
  driver_average = (driver_average/10);

  //Print out the header of the driver's summary including his number
  printf("Driver %d summary:\n\n", driver_number);

  //printout the driver's 10 daily average acceleration recordings given in the 2d array
  printf("Acceleration recordings: ");
  for (size_t k = 0; k < 10; k++)
  {
    printf("%d ", drivers[driver_number-1][k]);
  }

  //Print out the max average daily acceleration for the selected driver, we stored this in the variable "max"
  printf("\nMax average Acceleration for driver %d in trip: %d mph\n", driver_number, max);

  //Print out the average of the 10 daily average accelerations of the selected driver, we stored this in "driver_average"
  printf("Average Acceleration over all of driver %d trips: %.1f mph\n", driver_number, driver_average);

  //Check if the driver passes the discount coundition (no daily average more than 6 & no overall average more than 5)
  if (driver_average>5 || max>6)
  {
    //if the driver doesnt pass then printout no discount to be applied
    printf("Discount: No discount to be applied\n");
  }
  //if the driver does pass then printout discount applied
  else printf("Discount: Discount applied\n");

  //The following is to get the average acceleration of ALL drivers over all their trips
  //Declare a float sum and intialise it to 0
  float sum = 0;
  //iterate over all the rows and columns in the 2d array to sum up all the elemets and store in "sum"
  for (size_t m = 0; m < 5; m++)
  {
    for (size_t n = 0; n < 10; n++)
    {
      sum += drivers[m][n];
    }
  }
  //Then divide the value in "sum" by 50 and assign it back to sum to have the average
  sum = (sum/50);
  //Printout the average acceleration of all drivers over all trips which is stored in "sum"
  printf("\n\nThe average Acceleration of all drivers over all trips is: %.2f mph\n", sum);
}
