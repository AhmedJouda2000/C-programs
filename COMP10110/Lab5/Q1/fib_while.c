/*

This is Lab 5 Question 1a, Fibonacci using while loop

This is the work of Ahmed Jouda (Student Number 18329393)
Created on 9/10/2018

*/
#include <stdio.h>
#include <math.h>
int main(void)
{
int n, an, an_1, i, k, inc;
an = 1;
an_1 = 1;
k = 1;
i = 3;
printf("Enter the value of n:");
scanf("%d", &n);

while (k<=n && k<=2) {
  printf("1 ");
  k++;
}

while (i<= n) {
  an=an_1 + an;
  printf("%d ", an);
  an_1 = an - an_1;
  i++;
}



return 0;
}
