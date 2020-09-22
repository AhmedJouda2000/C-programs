/*
This is set 5 Question 2. Write a C Program which receives an integer array as a
parameter and modifies the array elements by multiplying each one by 10. You
must use pointers and not array indexing.

This is the work of Ahmed Jouda (Student Number 18329393)
Created on 26/02/2019
*/

//Include libraries needed
#include <stdio.h>

//Include function prototypes needed
void multbyten(int number[], int size);
//define the main function that returns nothing
int main (void)
{
  //declare an integer variable that will store the size of the array
  int size;
  //Take user input for the size of array from the user and store it in "size"
  printf("Enter the size of the array\n");
  scanf("%d", &size);

  //declare an integer array of size "size" which was inputted by the user
  int array[size];

  /*
  Take user input for the array elements using a for loop to iterate through
  the array positions and fill them up.
  */
  printf("Enter the array elements\n");
  for (size_t i = 0; i < size; i++)
  {
    scanf("%d", &array[i]);
  }

  //Call the function "multbyten" and pass the array name and size as arguments
  multbyten(array, size);

  //print the newly modified array by the function "multbyten"
  //print it used a for loop to iterate through all the elements
  printf("\nNew array:\n");
  for (size_t i = 0; i < size; i++)
  {
    printf("%d ", array[i]);
  }

return 0;
}



//This function returns nothing
//It takes in the array of integers and its size
void multbyten(int number[], int size)
{
  //This for loop will iterate until the last element of the array
  for (int i = 0; i < size; i++)
  {
    /*
    This is a pointer to the array element, we multiply it by 10 & assign it 
    back.
    As i increments at each iteration, we add i to the pointer and henece
    moving to the next array element.
    */
    *(number + i) *= 10;
  }
}
