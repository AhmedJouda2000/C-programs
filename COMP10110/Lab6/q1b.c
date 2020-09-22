/*
This is lab 6 questoion 1, Program to compute the kth largest
value in an array that is greater than 0.5 taking input from user

  This is the work of Ahmed Jouda (Student Number 18329393)
  Created on 15/10/2018
*/
#include <stdio.h>
#define MAX_SIZE 5000
int main(void)
{


  int i, j, k, maxndx, n;
  double tmp, max;
  double a[MAX_SIZE];
printf("Enter the size of the array\n");
scanf("%d", &n);

printf("Enter the values of the array\n");
  for (size_t i = 0; i < n; i++) {
      scanf("%lf", &a[i]);
  }



printf("Enter the size of k(kth largest value)\n");
scanf("%d", &k);


  for (j=0;j<k;j++)
    {
      max = a[j];
      maxndx=j;


      for (i = j+1;i<10;i++)
	{

	  if (a[i]>0.5&&a[i]>max)
	    {
	      max = a[i];
	      maxndx = i;
	    }

	}

      /* swap a[j] and a[maxndx] */
      tmp = a[j];
      a[j] = a[maxndx];
      a[maxndx] = tmp;
    }

    if (a[k-1]<=0.5) {
      printf("Doesn't exist\n");
    }
    else printf("The kth(%d) largest value, greater than 0.5, in the array is %lf\n", k, a[k-1]);



return 0;
}
