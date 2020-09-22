/*
This is lab 10 questoions 1 - 5, Write a bunch of programs and have the main
function call them.

This is the work of Ahmed Jouda (Student Number 18329393)
Created on 19/11/2018
*/
#include <stdio.h>
#include <math.h>
void triangle(void);
void circle(void);
void currency(void);
void roots(void);
void count(void);

int main (void)
{
  int x;

  printf("Pick: \nEnter '1' for Area of triangle\nEnter '2' for Area of circle\nEnter '3' for Currency exchange\nEnter '4' to compute the roots of a quadratic\nEnter '5' to count how many words in a string\n");
  scanf("%d", &x);
  getchar(); // getchar used to solve the scanf - gets problem for question 5

//Calling the functions
  if (x==1)
  {
  triangle();
  }
  if (x==2)
  {
    circle();
  }
  if (x==3)
  {
    currency();
  }
  if (x==4)
  {
    roots();
  }
  if (x==5)
  {
    count();
  }


}

// Question 1
void triangle(void)
{

  double area;
  double base, height;

  printf("Please enter the base length of the triangle.\n");
  scanf("%lf", &base);
  printf("Please enter the base height of the triangle.\n");
  scanf("%lf", &height);

  area=0.5*base*height;

  printf("The area of the triangle is %lf\n", area);
}

//Question 2
void circle(void)
{
  double area, radius;
  printf("Enter the value for the radius\n");
  scanf("%lf", &radius);
  area = M_PI*(radius*radius);

  printf("The area of the circle is %lf\n", area);
}

//Question 3
void currency(void)
{
  double euro, pound;
  printf("Enter the amount in Euro\n");
  scanf("%lf", &euro);

  pound = euro * 0.8;

  printf("%lf\n", pound);
}

//Question 4
void roots(void)
{
  double a, b, c;
  double r1, r2;
  double d;
  int z;

  printf("Enter the value for a:\n");
  scanf("%lf", &a);
  printf("Enter the value for b:\n");
  scanf("%lf", &b);
  printf("Enter the value for c:\n");
  scanf("%lf", &c);
  printf("Do you want root 1 or 2\n");
  scanf("%d", &z);

  r1 = (-b+ sqrt((b*b)-(4*a*c)))/(2*a);
  r2 = (-b- sqrt((b*b)-(4*a*c)))/(2*a);


  d = ((b*b)-(4*a*c));

  if (a!=0 & d>0)
  {
  printf("Roots are real\n",r1,r2 );
  if (z == 1)
  {
    printf("The root r1 is: %f\n",r1 );
  }
  else printf("The root r2 is:%f\n",r2 );
  }
  //for when the roots dont exist
  if (d<0)
  {
    printf("Roots are imaginary");
  }

  if (a==0)
  {
    printf("There is only one root\n",r1);
    printf("The root r1 is: %f\n",r1 );
  }

}

//Question 5
void count(void)
{
  char msg[100];
  int i, y = 0, w=0;

  printf("Enter the string\n");
  gets(msg);

  printf("\n\nYou entered: %s\n", msg);


  for (i = 0; msg[i] != '\0'; i++)
  {
    if (msg[i+1] == '\0' && w == 0) {
      msg[i+1] = ' ';
      msg[i+2] = '\0';
      w = 1;
    }
    if (msg[i] == ' ' || msg[i] == '\n' || msg[i] == '\t')
    {
      if (msg[i-1] != ' ' && msg[i-1] != '\n' && msg[i-1] != '\t' && i != 0)
      {
          y++;
      }

    }

  }
  printf("The message contains %d words!\n", y);

}
