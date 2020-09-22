/*
This is set 8 Question 2. Use dynamic memory allocation (calloc, realloc) to
write a C Program which achieves the following:
• Prompts the user to enter the type (integer or float) and number of elements
  they wish to store in an array
• Create sufficient memory to store the array
• Ask the user to enter each of the values they want to store
• After all elements haverage been entered and stored in the array, calculate the
  average and print to the screen.
• Ask the user if there are more elements to be added to the array, if yes,
  prompt the user to enter the number of additional elements.
• Reallocate sufficient memory to the array to store the new number of elements
• Ask the user to enter each of the new values they want to store
• After all the new elements have been entered and stored in the array,
  calculate the average and print to the screen.

This is the work of Ahmed Jouda (Student Number 18329393)
Created on 04/04/2019
*/

//include the libraries needed
#include <stdio.h>
#include <stdlib.h>

//declare the function main that returns nothing
int main(void)
{
    //declare a variable x to store the user's choice
    int x;
    //Prompts the user to enter the type (integer or float) they wish to store
    printf("Do you want:\n1) Floats\n2) Integers\n");
    scanf("%d", &x);

    //declare a variable num to store the user's number of elements
    int num;
    //Prompts the user to enter the  number of elements they wish to store in
    // an array
    printf("Enter the size of your array: \n");
    scanf("%d", &num);




    //if the user picks  floats type (x = 1)
    if (x == 1)
    {
      //declare a pointer to a float
      float *ptr;
      //declare a float called "average" and assign 0 to it
      float average = 0;

      //create sufficient memory to store the array using calloc
      //calloc take in the type float and the number of elements and works out
      // the memory needed to store them
      ptr = (float*) calloc(num, sizeof(float));

      //if space is not available print an error message and exit
      if(ptr == NULL)
      {
          printf("Error!\n");
          exit(0);
      }

      //declare a variable i as a loop counter
      int i;

      //delcare a float called "sum" and assign it to 0
      //it will contain the sum of the elements
      float sum = 0;

      //prompt the user to enter the elements of the array
      //scan them in order into the location of the pointer
      //each time you scan a new number add it to the sum and assign that back to sum
      printf("Enter elements of array: \n");
      for(i = 0; i < num; ++i)
      {
          scanf("%f", ptr + i);
          sum += *(ptr + i);
      }
      //assign average the answer to the float division of sum/num
      average = sum/num;
      //print the average
      printf("The average is = %f \n", average);


      // For Additional elements

      //creat an int variable to store the user's choice
      int response;
      //creat an int variable to store the number of new elements to be added
      int new_elements;

      //prompt the user to say if he wants to add elements or not
      //store the answer in "response"
      printf("Do you want to add elements to the array?\n");
      printf("Enter 1 or 2\n1) YES\n2) NO\n");
      scanf("%d", &response);

      //if the user says he want to add new elements (response = 1)
      if (response == 1)
      {
        //prompt the user to input the number of additional elements
        //store that in the variable new_elements
      	printf("Enter the number of additional elements you want : \n");
      	scanf("%d",&new_elements);

        //declare a new int variable called total_elements and store in it the
        //sum of the original number of elements and the new amount
      	int total_elements = new_elements + num;

        //create sufficient memory to store the total elements using calloc
        //calloc take in the type float and the number of elements and works out
        // the memory needed to store them
      	ptr = (float *) realloc(ptr, total_elements * sizeof(float));

        //print to the user the Previous array size and the new one
      	printf("Previous array size %d \n", num);
      	printf("New array size %d \n", total_elements);

        //prompt the user to enter the additional array elements
      	printf("Enter additional elements of array: \n");
        //use the same mechanism above to store them and add them to "sum"
  	    for(i = num; i < total_elements; ++i)
  	    {
  	        scanf("%f", ptr + i);
  	        sum += *(ptr + i);
  	    }
        //calculate the float average and assign it to "average"
  	    average = sum/total_elements;
        //print the final average
  	    printf("The new and final average is = %f \n", average);
      }
      //if the user doesnt want additional elements print the original average
      else
      {
      	printf("The final average is = %f \n", average);
      }

      free(ptr);  //free the memory dynamically allocated
    }




    //Below is if the user chooses the integer type
    //it uses the exact same mechanism as the floats with the different that
    //the elements and "sum" and "average" are float type instead of int
    else if (x==2)
    {
      int *ptr;
      int average = 0;

      ptr = (int*) calloc(num, sizeof(int));
      if(ptr == NULL)
      {
          printf("Error!\n");
          exit(0);
      }

      int i;
      int sum = 0;

      printf("Enter elements of array: \n");
      for(i = 0; i < num; ++i)
      {
          scanf("%d", ptr + i);
          sum += *(ptr + i);
      }
      average = sum/num;
      printf("The average is = %d \n", average);

      // Additional elements
      int response;
      int new_elements;

      printf("Do you want to add elements to the array?\n");
      printf("Enter 1 or 2\n1) YES\n2) NO\n");
      scanf("%d", &response);
      if (response == 1)
      {
      	printf("Enter the number of additional elements you want : \n");
      	scanf("%d",&new_elements);
      	int total_elements = new_elements + num;
      	ptr = (int *) realloc(ptr, total_elements * sizeof(int));

      	printf("Previous array size %d \n", num);
      	printf("New array size %d \n", total_elements);

      	printf("Enter additional elements of array: \n");

  	    for(i = num; i < total_elements; ++i)
  	    {
  	        scanf("%d", ptr + i);
  	        sum += *(ptr + i);
  	    }
  	    average = sum/total_elements;
  	    printf("The new and final average is = %d \n", average);
      }
      else
      {
      	printf("The final average is = %d \n", average);
      }

      free(ptr);
    }


    return 0;
}
