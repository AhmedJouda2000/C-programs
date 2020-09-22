#include <stdio.h>
#include <stdlib.h>
/*
  Written by: Neil Hurley (neil.hurley@ucd.ie)
  Program to write out a random array of floating point
  numbers, using the drand48 library function that is available
  in the stdlib library.
  Input:
  Output: MAX_SIZE floating point numbers between 0 and 1
  Note that it should be easily possible to convert this program
  to one that writes out integer values rather than floating point
  values. A random integer between 1 and M, for some value M can
  be computed using (rand()%M)+1
*/

#define MAX_SIZE 5000
int main(void)
{
  int i;
  FILE *fp;
  fp = fopen("floats.txt", "w");

  for (i=0;i<MAX_SIZE;i++)
    fprintf(fp, "%lf\n", (1.0*rand())/RAND_MAX);

  fclose(fp);

 return 0;
}
