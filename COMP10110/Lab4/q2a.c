/*
This is the work of Ahmed Jouda
Lab 4 Question 2(A). This is the first part of Q2 only.
2/10/2018
*/
#include <stdio.h>
#include <math.h>

int main(void)
{
//Floats used as required in the question
float x, y, z;

printf("Enter the value of x:");
scanf("%f", &x);
printf("Enter the value of y:");
scanf("%f", &y);
printf("Enter the value of z:");
scanf("%f", &z);



if (x>=y&&x>=z) {
  printf("The maximum is x:%f\n", x);
}

if (y>=x && y>=z) {
  printf("The maximum is y:%f\n", y);
}

if (z>=y&&z>=x) {
  printf("The maximum is z:%f\n", z);
}



return 0;
}
