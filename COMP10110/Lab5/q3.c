/*

This is Lab 5 Question 3, to assign w the smallest value, x next smallest and so on.

This is the work of Ahmed Jouda (Student Number 18329393)
Created on 9/10/2018

*/
#include <stdio.h>
int main (void)
{

double w, x, y, z;
double a[3];


printf("\nEnter the four values:\n");
scanf("%lf%lf%lf%lf", &w, &x, &y, &z);

a[0]=w;    //Assign values to the array
a[1]=x;
a[2]=y;
a[3]=z;

for (int i = 0;i <= 3; i++)
{
  for (int j = 0;j <= 3; j++)
  {
    if (a[j] > a[i])
     {
        double t = a[i];    // This swaps the values around to order them
        a[i] = a[j];
        a[j] = t;
    }
  }
  }
w=a[0];   //Put the new ordered values back into the varibles back from the array
x=a[1];
y=a[2];
z=a[3];

printf("The ascending order is: %.0f %.0f %.0f %.0f", w, x, y, z);

return 0;
}
