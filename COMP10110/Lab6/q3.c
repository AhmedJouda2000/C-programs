/*
This is lab 6 questoion 3, Write	a	program	to	find	the	value	in	an
integer	array	a[] of	length	N	that	occurs	at	least
(N/2 + 1) times,	if	such	a	value	exists.

  This is the work of Ahmed Jouda (Student Number 18329393)
  Created on 15/10/2018
*/
#include <stdio.h>
#define MAX 5000


int main(void)
{

int x, n, i, j;
int a[MAX];

printf("Enter the size of the array\n");
scanf("%d", &n);

printf("Enter the values of the array\n");
  for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
  }

printf("\n\n");

  for (int i = 0;i < n; i++)
  {

    for (int j = 0;j < n; j++)
    {
      if (a[j] > a[i])
       {
          double t = a[i];    // This swaps the values around to order them
          a[i] = a[j];
          a[j] = t;
      }
    }
    }

printf("The ordered array:\n");
//Print the ordered array

    for (i = 0; i < n; i++) {
      printf("%d\n", a[i]);
    }


     /*for the case that no value occurs more than n/2 times we say no such value exists
     If it does exist print it*/


    if (a[n/2] == a[(n/2)-1] && a[n/2] == a[(n/2)+1]) {
      printf("\nThe value that occurs atleast (n/2 + 1) times is: %d\n", a[n/2]);
    }
    else printf("No such value exists");




return 0;
}
