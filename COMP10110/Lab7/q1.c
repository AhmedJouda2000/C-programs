/*
This is lab 7 questoion 1a (small testcase), Write	a	program	to	Find, from amongst a
set of positive lengths, a pair of lengths that sum exactly to a target length.

This is the work of Ahmed Jouda (Student Number 18329393)
Created on 22/10/2018
*/
#include <stdio.h>
#include <stdlib.h>

#define N 500

int main(void)
{

  int n;  /* The number of lengths */
  int x; /* The target length */
  int lengths[N]; /* The array of available lengths */
  int i, j;
  char found = 'f';



  FILE *fp;

  fp = fopen("testcase_small.txt", "r");

  fscanf(fp, "%d", &x);
  fscanf(fp, "%d", &n);

  for (i=0;i<n;i++)
    {
      fscanf(fp, "%d", &lengths[i]);
    }



 x = x*10000000;

  fclose(fp);

  /* Now all the input data has been read in
     search for the required pair of lengths... */
i=0;
j=n-1;

/*
As the numbers are ordered we know j is the largest and i is the smallest
Therefore if i and j add up to x then we print those out and they are for sure
the pair with the biggest difference between them as we are closing in on the array and
the first pair found (greatest difference) is printed.
If they dont add up to x, 3 scenarios are possible, either j = i and no pair was
found after closing in on the array, or j+i > x meaning j has to be lowered, or
j+i <x in which case i has to be raised.
*/

      while(found == 'f')
 {

      if (lengths[i] + lengths[j] == x)
    {
      printf("they are %d %d", lengths[i], lengths[j]);
      found = 't';
    }


    else if (i==j)
    {
      printf("No values exist\n");
      found = 't';
    }

    else if ((lengths[i] + lengths[j]) > x) {
      j--;
    }

    else if ((lengths[i] + lengths[j]) < x) {
      i++;
    }
 }

  return 0;

}
