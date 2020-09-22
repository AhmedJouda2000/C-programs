/*

This is Lab 5 Question 1c, Fibonacci using for loop after 50 terms

This is the work of Ahmed Jouda (Student Number 18329393)
Created on 9/10/2018

*/
#include <stdio.h>
int main(void)
{
double an, an_1;
int i, n;
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
  printf("%.0f ", an);
  an_1 = an - an_1;

}

return 0;
}
