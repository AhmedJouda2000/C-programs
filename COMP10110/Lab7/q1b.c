/*
This is lab 7 questoion 1b (larege testcase), Write	a	program	to	Find, from
amongst a set of positive lengths, a pair of lengths that sum exactly to a
target length.

This is the work of Ahmed Jouda (Student Number 18329393)
Created on 22/10/2018
*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{

  int n;  /* The number of lengths */
  int x; /* The target length */
  int *lengths; /* The array of available lengths */
  int i, j;
  char found = 'f';

  FILE *fp;

  fp = fopen("testcase_large_sorted.txt", "r");

  fscanf(fp, "%d", &x);
  fscanf(fp, "%d", &n);

  /* create the lengths array dynamically.
     We haven't covered this yet. It is enough to
     know that after the execution of the statement
     below, lengths is now just like an ordinary
     int array of size n */
  lengths = (int *)malloc(sizeof(int)*n);
  if (!lengths)
    {
      printf("ERROR: Insufficient memory for lenghts array.\n");
      return -1;
    }

  for (i=0;i<n;i++)
    fscanf(fp, "%d", &lengths[i]);

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



  /* finished work, so free up the dynamic array
     This should be done whenever dynamic allocation
     is used.
   */
  free(lengths);
  return 0;

}
