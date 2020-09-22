/*
This is set 7 Question 2.Write a C Program that defines and uses 2 macros; one
macro should print the elements of an integer array and the other macro should
print the elements in reverse order.

This is the work of Ahmed Jouda (Student Number 18329393)
Created on 26/03/2019
*/

//include the libraries needed
#include <stdio.h>
/*
  define a macro "PRINTARRAY" that takes in 2 arguments, array name & size
  using a for loop, loop over every element of the array starting at index 0
  till (size - 1) while printing each one of them and hence printing the array
*/
#define PRINTARRAY(name, size) \
        for(int i = 0; i < size; i++) \
        printf("%d\t", name[i]);
/*
  define a macro "REVERSEPRINT" that takes in 2 arguments, array name & size
  using a for loop, loop over every element of the array starting with the last
  element at index (size - 1) and decrement till 0 while printing each one of
  them and hence printing the array.
*/
#define REVERSEPRINT(name, size) \
        for (int i = (size-1); i >= 0; i--) \
        printf("%d\t", name[i]);

//define the main function that returns nothing
int main(void)
{
//declare an integer array "myArray" of size 5 and intialise it with 5 numbers
int myArray[5] = {1, 4, 8, 16, 32};

//call the macro "PRINTARRAY" with "myArray" and "5" as arguments
//This will print t
PRINTARRAY(myArray, 5);
printf("\n\n\n");
//call the macro "REVERSEPRINT" with "myArray" and "5" as arguments
REVERSEPRINT(myArray, 5);

}
