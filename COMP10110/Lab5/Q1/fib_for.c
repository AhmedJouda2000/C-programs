/*

This is Lab 5 Question 1a, Fibonacci using for loop

This is the work of Ahmed Jouda (Student Number 18329393)
Created on 9/10/2018

*/
#include <stdio.h>
#include <math.h>
int main(void)
{
int n, an, an_1, i;
an = 1;
an_1 = 1;
printf("Enter the value of n:");
scanf("%d", &n);

for (i = 1; i<=2 && i<=n; i++)
{
printf("1 ");
}

for (i=3; i <= n; i++) {
  an = an_1 + an;
  printf("%d ", an);
  an_1 = an - an_1;

}

return 0;
}
