/*
This is the work of Ahmed Jouda
Lab 3 Question 1
1/10/2018
*/
#include <stdio.h>
#include <math.h>

int main(void)
{
double a, b, c;
double r1, r2;
double d;

printf("Enter the value for a:\n");
scanf("%lf", &a);
printf("Enter the value for b:\n");
scanf("%lf", &b);
printf("Enter the value for c:\n");
scanf("%lf", &c);

r1 = (-b+ sqrt((b*b)-(4*a*c)))/(2*a);
r2 = (-b- sqrt((b*b)-(4*a*c)))/(2*a);


d = ((b*b)-(4*a*c));

if (a!=0 & d>0) {
printf("Roots are real\n",r1,r2 );
printf("The root r1 is: %f\n",r1 );
printf("The root r2 is:%f\n",r2 );

  }
//for when the roots dont exist
if (d<0) {
  printf("Roots are imaginary");
}

if (a==0) {
  printf("There is only one root\n",r1);
  printf("The root r1 is: %f\n",r1 );

}


return 0;
}
