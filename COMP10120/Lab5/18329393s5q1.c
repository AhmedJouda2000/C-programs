/*
This is set 5 Question 1. Write a C Program to demonstrate pointers to functions.
The program should contain three functions: reverseArray, randomiseArray and
printArray. ReverseArray should swap reverse the order of all elements in an
array; randomiseArray should randomly mix the order of elements in an array;
printArray should print the contents of the array in reverse order or random
order depending on user input.

This is the work of Ahmed Jouda (Student Number 18329393)
Created on 26/02/2019
*/

//Include libraries needed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Include function prototypes needed
void printArray(int arraySize, int a[], void (*arrayFunction)(int arraySize, int a[]));
void reverseArray(int arraySize, int a[]);
void randomiseArray(int arraySize, int a[]);

//define the main function that returns nothing
int main(void)
{
  /*
  Instead of inputing a seed every time, the following statement allows the
  seed to be determined at run time by the system
  */
	srand(time(0));
	//Declare and intialise the array given in the question
  int myArray[10] = {2,4,6,8,10,12,14,16,18,20};
	//declare the variable "c" that will store the choice of the user
  int c;
	//This while loop will only terminate when the user input 0, other than that
	//the prgram will keep running
  while (c!=0)
  {
		//Print the array that we intialised already
    printf("\n--------------------------------------------\n");
    printf("Current Array:\n");
		//Printing the array using a for loop to iterate through it
    for (size_t i = 0; i < 10; i++)
    {
      printf("%d ", myArray[i]);
    }
		//Print the menu of options and prompt the user to choose a number
    printf("\nEnter the number of the action required:\n");
    printf("\nEnter 0 to exit\n1) Reverse Array\n2)Randomise Array\n");
		//Take user input and place it into the variable c
    scanf("%d", &c);

		//If the user picked 1 then enter this if statement
    if (c == 1)
    {
			//Call the function "printArray" with the size of the array, name of the
			//array and the function required
      printArray(10, myArray, reverseArray);
    }
		//If the user picked 2 then enter this if statement
    if (c ==2)
    {
			//Call the function "printArray" with the size of the array, name of the
			//array and the function required
      printArray(10, myArray, randomiseArray);
    }
		//If the number enter is not given as a choice, print appropriate message
		//And loop through the while loop again to let them try again.
    else if (c != 1 && c != 2 && c!=0)
    {
      printf("Wrong number iputted. Try again.\n");
    }
  }

return 0;
}



//This function returns nothing
//It takes in the array name and size as well as a function name
void printArray(int arraySize, int a[], void (*arrayFunction)(int arraySize, int a[]))
{
  //send array into required function to be proccessed
  (*arrayFunction)(arraySize, a);

  //print array the new edited array using a for loop
  for (size_t i = 0; i < 10; i++)
  {
    printf("%d ", a[i]);
  }
}



//This function returns nothing
//It takes in the array name and size
void reverseArray(int arraySize, int a[])
{
  int Temp;	//This integer variable is used to swap the elements of the array
  int i = 0;	//This is a loop counter that will be used as an array index
  int j = arraySize-1; //This is a loop counter that will be used as an array index

	//This loop works swaps the 1st and last elements of the array and then the
	//2nd last element with the 2nd element and so on as long as i<j, meaning until
	//i and j meet on the middle element
	//i starts at the 1st element and j starts at the last element
  while (i < j)
   {
		 	//swapping the elements
      Temp = a[i];
      a[i] = a[j];
      a[j] = Temp;
			//closing in by incrementing i and decrementing j
      i++;
      j--;
   }
}




//This function returns nothing
//It takes in the array name and size
void randomiseArray(int arraySize, int a[])
{

	//declaring needed integers
	//i is needed to iterate through the array elements
	// j is randomised at each iteration
	//swap is needed to swap array elements
  int j, i, swap;

	/*
	In this for loop we iterate through the entire array at each iteration, j is
	assigned a random number within the range of the size of the array this random
	number is then used as an index and is swapped with the current element at
	index i. This randomises the array.
	*/
  for (i = 0; i < arraySize; i++)
  {
		//Assigns j a random number between 0-9 at each iteration
    j = rand()%10;
    swap = a[i];
    a[i] = a[j];
    a[j] = swap;
    i++;
  }
}
