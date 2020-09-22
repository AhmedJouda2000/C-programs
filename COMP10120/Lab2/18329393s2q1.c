/*
This is set 2 Question 1. Write a function in C that calculates the volume of an
ellipsoid when presented with all the measurements needed to calculate it. The C
program should calculate the volume of 4 ellipsoids by asking the user to
specify the required measurements.

This is the work of Ahmed Jouda (Student Number 18329393)
Created on 05/02/2019
*/

//include the libraries needed
#include <stdio.h>
#include <math.h>

//insert the prototypes of the functions to be used
int test(void);
float volume(float length, float width, float height);

//define the main function that returns nothing
int main(void)
{
  /*
  Declare Floats for length, width, height and answer but used different names to
  avoid confusion with the function volume() arguments
  */
  float l, w, h, Answer;

  //declare and assign 1 to our loop counter
  int i=1;

  //Check if the function test passes(0) or not (1), if it does we enter the statement
  if (test() == 0)
  {
    //This loop will iterate 4 times so that it calculates the volume of 4 ellipsoids as asked for
    while (i<5)
    {
      //This is a header for each time we iterate to clarify what ellipsoid we are on
      printf("\n\n ** Calculating Volume of Elipsoid %d ** \n", i);

      //Here we take user input for the required measurements and assign them to the variables previously created
      printf("\nEnter the value for length:");
      scanf("%f", &l);
      printf("Enter the value for width:");
      scanf("%f", &w);
      printf("Enter the value for height:");
      scanf("%f", &h);

      //We call the function volume with the arguments being the measurements taken from the user
      //Then assign the returned value into the variable "Answer"
      Answer = volume(l,w,h);

      //This prints the volume of the ellipsoid with the ellipsoid's number
      printf("\nThe volume is of Elipsoid %d is %f\n", i, Answer);

      i++;
    }
  }
}

//This function takes in 3 floats and returns one, it calculates the volume of an ellipsoid
float volume(float length, float width, float height)
{
  //Declare the a float variable and assign the answer from the formula to it
  float VolumeOfEllipsoid = (4*M_PI*length*width*height)/3;
  //Return the the value of that variable to main
  return VolumeOfEllipsoid;
}

//This function is called at the very start to test if the program runs correctly
//It returns either 0 or 1 to show that the program either passed of failed
int test(void)
{
  //Declare floats for the 3 measurements, the result from the function and the known solution
  float a = 2, b = 3, c = 4, result, solution;

  //Call the volume function with the defined measurements above and assign the answer to "result"
  result = volume(a,b,c);
  //Assign the known correct answer calculated somewhere else into the variable "solution"
  solution = 100.530965;

  //Check if "result" is equal to "solution", if so the test has passed and 0 is returned
  //If they arent equal the test has failed and 1 is returned
  if (result != solution)
  {
    //"Test has failed!" and 1 is returned if "solution" and "result" arent equal
    printf("Test has failed!\n");
    return 1;
  }
  else
  {
    //"Test has passed!" and 0 is returned if "solution" and "result" are equal
    printf("Test has passed!\n");
    return 0;
  }
}
