/*
This is set 10 Question 1. In C++, demonstrate function overloading by creating
4 functions called addTwo in the one program which have two arguments of the
same type (floats, integers, doubles and longs) and return the two numbers
added together.

This is the work of Ahmed Jouda (Student Number 18329393)
Created on 16/04/2019
*/

//include the libraries needed
#include <iostream>
using namespace std;

/*
  Declare 4 functions called "addTwo".
  Each of them takes in 2 variables of the same type(int, float, double, long),
  and each of them return one variable of the same type as its arguments.
  Inside all of the functions print out the 2 variables in this format "x + y ="
  then return the value of x + y.
*/
int addTwo(int x, int y)
{
  cout<<x<<"+"<<y<<"= ";
  return x + y;
}

float addTwo(float x, float y)
{
  cout<<x<<"+"<<y<<"= ";
  return x + y;
}

double addTwo(double x, double y)
{
  cout<<x<<"+"<<y<<"= ";
  return x + y;
}

long addTwo(long x, long y)
{
  cout<<x<<"+"<<y<<"= ";
  return x + y;
}

//declare the main function that takes in nothing
int main(void)
{
  /*
    Print out the return value from the function addTwo with 2 numbers of each
    type to test each variable type. The program finds out what type the variables
    passed in the parameter are and calls the appropriate function.
  */
  cout<<addTwo(2,2);
  cout<<endl;
  cout<<addTwo(222.5127635,235.63537);
  cout<<endl;
  cout<<addTwo(20.6353,20.12);
  cout<<endl;
  cout<<addTwo(12345678,91234567);
  cout<<endl;
}
