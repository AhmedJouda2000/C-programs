/*
This is lab 7 questoion 2, Write	a	program	to find	all	the	prime
numbers	less than a	given	positive	number	N.

This is the work of Ahmed Jouda (Student Number 18329393)
Created on 23/10/2018
*/
#include <stdio.h>
int main(void)
{
int N, i, j;
int k=0;

//Ask for the number N
printf("Please enter the value of N:\n");
scanf("%d", &N);
printf("\n\nThe first array including all numbers from 2 to N:\n");
int a[N];

//print the array from 2 to N-1
for (i = 0; i < N-2; i++) {
  a[i] = i + 2;
  printf("%d ", a[i]);
}
/*Get the modulus between the numbers and each time remainder is 0 we change
that number to 1 as its not prime, this leaves us with prime numbers and 1's */
for (i = 0; i < N-2; i++)
  for ( j = i+1; j < N-2; j++)
    if (a[j] % a[i] == 0 && a[i]!=1)
      a[j] =1;

//Create a new array for the prime numbers excluding the 1's
    for (i = 0; i < N-2; i++)
      if (a[i]!=1)
        a[k++] = a[i];

//Print out the prime numbers array
printf("\n\n\nPrime numbers array:\n");
for(i=0;i<k;i++){
  printf(" %d ", a[i]);
}




return 0;
}
