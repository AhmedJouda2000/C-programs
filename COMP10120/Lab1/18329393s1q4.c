/*
This is lab 1 question 4, Write a C Program which takes in the systolic
and diastolic measures from the keyboard and determines if the blood
pressure is high, pre-high, ideal or low based on the data provided.

This is the work of Ahmed Jouda (Student Number 18329393)
Created on 30/01/2019
*/

//include the libraries needed
#include<stdio.h>

//Declare the main function that returns nothing
int main(void)
{
  //Declare the integer variables systolic and diastolic
  int systolic, diastolic;

  /*
    Take user input using scanf for systolic and diastolic pressure and
    store them in their respective variables
  */
  printf("Enter the systolic pressure: \n");
  scanf("%d", &systolic);
  printf("Enter the diastolic pressure: \n");
  scanf("%d", &diastolic);

  /*
    Firstly, using an if statement we check if either the systolic or diastolic
    pressures are in the high pressure range(more than or equal to). If either
    of them is, then we print out "HIGH BLOOD PRESSURE" and the program ends.
    If not then we skip this statement.
  */
  if (systolic>=140 || diastolic>=90)
  {
    printf("HIGH BLOOD PRESSURE\n");
  }

  /*
    If the above statement is skipped then we check if either systolic or diastolic
    is high enough to be in the "PRE-HIGH BLOOD PRESSURE", if so we print that out
    and the program ends.
    If both are lower, then this statement is skipped.
  */
    else if (systolic>120 || diastolic>80)
    {
    printf("PRE-HIGH BLOOD PRESSURE\n");
    }

    /*
      If the above 2 statements are skipped then we check if either systolic or
      diastolic are high enough to be in the ideal range. If they are then we print
      out "IDEAL BLOOD PRESSURE" and the program ends.
      If both are lower than the specified range then this statement is skipped.
    */
    else if (systolic>90 || diastolic>60)
    {
    printf("IDEAL BLOOD PRESSURE\n");
    }

    /*
      If all the above if statements were skipped then we check if either systolic
      or diastolic is lower than or equal to the range specified in the graph.
      If eithr of them is, then we print "LOW BLOOD PRESSURE".
    */
    else if (systolic<=90 || diastolic<=60)
    {
    printf("LOW BLOOD PRESSURE\n");
    }


}
