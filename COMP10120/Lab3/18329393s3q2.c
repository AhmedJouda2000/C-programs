/*
This is set 3 Question 2. Write a C program which initially creates 2 two-dimensional
integer arrays. The size of the arrays should be equal and specified by user. Each array
should be filled with random numbers between 100 and 1500 with no duplicate numbers in a single array.

The program should then create new arrays for each of the following situations:
DONE • An array containing the product of corresponding cells in arrayA and arrayB
DONE • An array containing the sum of corresponding cells in arrayA and arrayB
DONE • An array containing the sum of corresponding rows in arrayA and arrayB
DONE • An array containing the sum of corresponding columns in arrayA and arrayB
The program should also
DONE • Print the contents of arrayA and arrayB.
• Print the number of total number of numbers that occur in both arrays (if any)
DONE • Print the word Wow if the same number appears in the same cell in the two arrays.

This is the work of Ahmed Jouda (Student Number 18329393)
Created on 15/02/2019
*/

//include the libraries needed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int r; //declre integer variable for row size
	int c;//declare integer variable for column size
	int i, j;//declare integer variables for loop counters

	int arrayA[20][20];	//2d ArrayA that will be filled randomly
	int arrayB[20][20]; //2d ArrayB that will be filled randomly
	int array1[400]; //1d array to help check for no duplicates
	int array2[400];//1d array to help check for no duplicates

	int product[20][20]; //2d array to store the product of arrayA and ArrayB
	int sumofcells[20][20]; //2d array to store the sum of corresponding cells of arrayA & arrayB
	int sumofcols[20]; //1d array to store the sum of corresponding columns of arrayA & arrayB
	int sumofrows[20]; //1d array to store the sum of corresponding rows of arrayA & arrayB

	//Instead of inputing a seed every time, the following statement allows the seed to be determined at run time by the system
	srand(time(0));

	//Take user input for the number of rows and columns and store them in the variables r & c
	printf("Enter the size of the matrices arrayA & arrayB: (MAX 20*20)\n");
	scanf("%d%d", &r, &c);


	//FILLING & PRINTING arrayA
	printf("--------------------------\narrayA:\n\n");

	//Fill the 1d array "array1" with random integers between 100 - 1500
	for (i = 0; i < r*c; i++)
	{
		array1[i] = rand()%1401 + 100;
		//Check if the random number has been added to the array already, if so randomise again to avoid duplicates
		for (j = 0; j < i; j++)
		{
			if (array1[i] == array1[j])
			{
				i = j;
				break;
			}
		}
	}

	//Move the contents of the 1d array "array1" into the 2d array "arrayA" row by row

	int a =0; //counter for elements
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			arrayA[i][j] = array1[a++];
		}
	}

	//Print out the arrayA as a matrix
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			printf("%d\t", arrayA[i][j]);
		}
		printf("\n");
	}


	//FILLING & PRINTING arrayB
    printf("--------------------------\narrayB:\n\n");

		//Fill the 1d array "array2" with random integers between 100 - 1500
		for (i = 0; i < r*c; i++)
		{
			//Check if the random number has been added to the array already, if so randomise again to avoid duplicates
			array2[i] = rand()%1401 + 100;
			for (j = 0; j < i; j++)
			{
				if (array2[i] == array2[j])
				{
					i = j;
					break;
				}
			}
		}

		//Move the contents of the 1d array "array1" into the 2d array "arrayA" row by row
		int b = 0;//counter for elements
		for (i = 0; i < r; i++)
		{
			for (j = 0; j < c; j++)
			{
				arrayB[i][j] = array2[b++];
			}
		}

			//Print out the arrayA as a matrix
			for (i = 0; i < r; i++) {
				for (j = 0; j < c; j++) {
					printf("%d\t", arrayB[i][j]);
				}
				printf("\n");
			}

	//Multiplying the corresponding elements of arrayA & arrayB and printing out the result
	printf("--------------------------\nArray of products of corresponding cells:\n\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			product[i][j]=arrayA[i][j]*arrayB[i][j];
			printf("%d\t",product[i][j]);
		}
	printf("\n");
	}

	//Adding up the corresponding cells in arrayA and arrayB and printing out the result
	printf("--------------------------\nArray of sums of the corresponding cells:\n\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			sumofcells[i][j]=arrayA[i][j]+arrayB[i][j];
			printf("%d\t",sumofcells[i][j]);
		}
	printf("\n");
	}

	//Summing up the corresponding rows in arrayA & arrayB and printing out the result
	printf("--------------------------\nArray of the sums of the corresponding rows:\n\n");

	for(i=0;i<c;i++)
	{
		for(j=0;j<r;j++)
		{
			sumofrows[i]= sumofrows[i]+arrayA[i][j]+arrayB[i][j];
		}
		printf("Row %d sum = %d\n",i,sumofrows[i]);
	}
	printf("\n");

	//Summing up the corresponding columns in arrayA & arrayB and printing out the result
	printf("--------------------------\nArray of the sums of the corresponding columns:\n\n");


    for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			sumofcols[i]= sumofcols[i]+arrayA[j][i]+arrayB[j][i];
		}
		printf("Column %d sum = %d\n",i,sumofcols[i]);
	}
	printf("\n");


	//Counting the number of common elements in between arrayA & arrayB and printing it
	printf("--------------------------\nNumber of Duplicates in arrayA & arrayB\n\n");
	int x, z; //loop conuters

	int total = 0; //intialise the counter to 0 and increment it by 1 everytime a duplicate is found

	//using for loops iterate through the rows and columns of the 2 arrays and if a match is found increment "total" by 1
	for ( i = 0; i < c; i++)
	{
		for (j = 0; j < r; j++)
		{
			for (x = 0; x < c; x++)
			{
				for (z = 0; z < r; z++)
				{
					if (arrayA[i][j] == arrayB[x][z])
					{
						total++;
					}
				}
			}
		}
	}
	//print out the value in "total"
	printf("The total number of numbers in both arrays is %d\n--------------------------\n\n",total);

	//Checking if the same number is in the same place in both arrays and if so printing "Wow"
	//This is done by using for loops to iterate through the arrays until a match is found in the same indecies
	for(i=0;i<c;i++)
	{
		for(j=0;j<r;j++)
		{
			if(arrayA[i][j] == arrayB[i][j])
			{
				printf("Wow\n");
			}
		}
	}
return 0;
}
