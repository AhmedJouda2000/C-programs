/*
This is the work of Ahmed Jouda
Lab 4 Question 2(B). This is the second part of Q2 only.
2/10/2018
*/
#include <stdio.h>
#include <math.h>

int main(void)
{

float a, b, c, x, y, z;

printf("Enter the value of a:");
scanf("%f", &a);
printf("Enter the value of b:");
scanf("%f", &b);
printf("Enter the value of c:");
scanf("%f", &c);
printf("Enter the value of x:");
scanf("%f", &x);
printf("Enter the value of y:");
scanf("%f", &y);
printf("Enter the value of z:");
scanf("%f", &z);



if (a>=b&&a>=c&&a>=x&&a>=y&&a>=z) {
  printf("The maximum is a:%f\n", a);
}
if (b>=a&&b>=c&&b>=x&&b>=y&&b>=z) {
  printf("The maximum is b:%f\n", b);
}
if (c>=b&&c>=a&&c>=x&&c>=y&&c>=z) {
  printf("The maximum is c:%f\n", c);
}
if (x>=b&&x>=a&&x>=c&&x>=y&&x>=z) {
  printf("The maximum is x:%f\n", x);
}
if (y>=b&&y>=a&&y>=x&&y>=c&&y>=z) {
  printf("The maximum is y:%f\n", y);
}
if (z>=b&&z>=a&&z>=x&&z>=y&&z>=c) {
  printf("The maximum is z:%f\n", z);
}




return 0;
}
