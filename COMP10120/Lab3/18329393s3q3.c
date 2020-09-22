/*
This is set 3 Question 3. Write a C Program which prompts the user to enter the
size of 2 two-dimensional arrays. The user should also be requested to fill the
arrays. The program should then compute the product of the arrays using matrix
multiplication rules and print the resulting array.

This is the work of Ahmed Jouda (Student Number 18329393)
Created on 14/02/2019
*/

//include the libraries needed
#include <stdio.h>

//define the main function that returns nothing
int main()
{
  //declare all the needed variables for array sizes, loop counters etc.
  int m, n, p, q, c, d, k;
  //declare an integer variable "sum" and instialise it to 0, it will be used to store temporarily values during matrix multiplication
  int sum = 0;

  //Take user input for the number of rows and columns of the 1st matrix and store that in "m" & "n"
  printf("Enter number of rows of first matrix\n");
  scanf("%d", &m);
  printf("Enter number of columns of first matrix\n");
  scanf("%d", &n);

  //Declare the first matrix as a 2d array with indecies m and n
  int first[m][n];

  //Take user input to fill up the matrix(array) elements
  //Use nested for loops to fill up row by row, c and d are loop counters to iterate over all positions in the matrix
  printf("\n\nEnter elements of first matrix\n");

  for (c = 0; c < m; c++)
    for (d = 0; d < n; d++)
      scanf("%d", &first[c][d]);

  //Take user input for the number of rows and columns of the 2nd matrix and store that in "p" & "q"
  printf("Enter number of rows of second matrix\n");
  scanf("%d", &p);
  printf("Enter number of columns of second matrix\n");
  scanf("%d", &q);

  //Declare the second matrix as a 2d array with indecies p and q
  //Also declare the 2d array that will store the multiplication result "multiply" with indecies "m" for the 1st matrix and "q" from the 2nd matrix
  int second[p][q], multiply[m][q];

  //Take user input to fill up the 2nd matrix(array) elements
  //Use nested for loops to fill up row by row, c and d are loop counters to iterate over all positions in the matrix
  printf("Enter elements of second matrix\n");

  for (c = 0; c < p; c++)
    for (d = 0; d < q; d++)
      scanf("%d", &second[c][d]);

  //Check if the multiplication of the 2 arrays is possible by checking if the index "n" and "p" are the same or not
  if (n != p)
    //if they arent the same then the multiplication is not possible and we print that out
    printf("The matrices can't be multiplied with each other.\n");
  //if they are equal then its possible and the else statement is enetered to proceed with the multiplication
  else
  {
    //using 3 nested for loops iterate over the entire matrices and multiply the corresponding rows and columns
    //the 3rd for loop is used as common factor to map the 2 matrices onto each other accordingly
    //The sum of the corresponding row & colum multiplication is then stored in the corresponding location in the "multiply" array
    for (c = 0; c < m; c++)
    {
      for (d = 0; d < q; d++)
      {
        for (k = 0; k < p; k++)
        {
          sum = sum + first[c][k]*second[k][d];
        }
        multiply[c][d] = sum;
        //sum is assigned 0 again to start the next iteration
        sum = 0;
      }
    }


    //print out the resulting matrix, "multiply", using nested for loops to iterate over all rows and columns in the 2d array and print all elements
    printf("Product of the matrices:\n");

    for (c = 0; c < m; c++)
    {
      for (d = 0; d < q; d++)
        printf("%d\t", multiply[c][d]);

      printf("\n");
    }
  }

  return 0;
}
