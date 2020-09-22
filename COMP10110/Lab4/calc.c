/*
This is the work of Ahmed Jouda
Lab 4 Question 1, simple calculator
2/10/2018
*/
#include <stdio.h>
#include <math.h>

int main(void)
{
int x, y;
char z;

printf("\nEnter the expression (without spaces):");
scanf("%d", &x);
scanf("%c", &z);
scanf("%d", &y);

if (z=='+') {
  printf("\nThe answer is: %d", (x+y));
}

if (z=='-') {
  printf("\nThe answer is: %d", (x-y));
}

if (z=='*') {
  printf("\nThe answer is: %d", (x*y));
}

if (z=='/'&y!=0) {
  printf("\nThe answer is: %d", (x/y));
}
//This is the special case in division as its not possible to divide by 0
if (z=='/'&y==0) {
  printf("This is not possible\n");
}



return 0;
}
