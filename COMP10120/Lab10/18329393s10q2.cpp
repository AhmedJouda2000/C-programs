/*
This is set 10 Question 2. In C++, write a program to find the area of different
shapes. The user should be able to specify the required parameters, however, the
following default parameters for each area function should also be provided.

This is the work of Ahmed Jouda (Student Number 18329393)
Created on 17/04/2019
*/

//include the libraries needed
#include <iostream>
using namespace std;

//define the functions for each shape, assign the default values if present
double triangle(double height = 1, double base = 2.3);
double square(double side = 10);
double rectangle(double width, double length = 20);
double rhombus(double diagonal1 = 10.2,double diagonal2 = 3.8);
double circle(double radius = 3.6);
double trapezoid(double Theight, double Tbase,double base = 8);

/*
  For each function return the answer to the formula of the area for that shape.
*/
double triangle(double height, double base)
{
  return (height*base)/2;
}

double square(double side)
{
  return side*side;
}

double rectangle(double width,double length)
{
  return (length) * (width);
}

double rhombus(double diagonal1,double diagonal2 )
{
  return (diagonal1*diagonal2)/2;
}

double circle(double radius)
{
  return (radius*radius)*3.14159;
}

double trapezoid(double Theight, double Tbase, double base)
{
  return ((base+Tbase)/2)*Theight;
}

//declare the function main that takes in nothing
int main(void){

  //declare variables that will be used to store the user's input for each shape
  double height;
  double base;
  double side;
  double width;
  double length;
  double diagonal1;
  double diagonal2;
  double radius;
  double Tbase;
  double Theight;

  //declare a variable choice to store the user's shape choice
  int choice;

//while the user didn't choose to exit (choice != 0) keep repeating
while (choice != 0)
{
  //prompt user to input their choice
  cout<<"\n\nPick a shape to find the area for using your values:";
  cout<<"\n1) Triangle\n2) Square\n3) Rectangle\n4) Rhombus\n5) Circle\n6) Trapezoid\n";
  cout<<"Enter 0 to exit\n";
  cin>>choice;  //store their choice in the variable "choice"
  cout<<endl;

//depending on what shape they choose, take input for their measurements and
//print out the area of that using the appropriate function call, then print
//out the default answer of the area of that shape using the predefined values
//in the function
if (choice == 1)
{
  cout<<"Enter value for lenght of the triangle: ";
  cin>>height;
  cout<<"Enter value for width of the triangle: ";
  cin>>base;
  cout<<"\nThe new area of the triangle: ";
  cout<<triangle(height,base);
  cout<<endl;
  cout<<"\n\nThe default area of the triangle: ";
  cout<<triangle();
  cout<<endl;
}

else if (choice == 2)
{
  cout<<"Enter value for side of the square: ";
  cin>>side;
  cout<<"\nThe new area of the square: ";
  cout<<square(side);
  cout<<endl;
  cout<<"\n\nThe default area of the square: ";
  cout<<square();
  cout<<endl;
}

else if (choice == 3)
{
  cout<<"Enter value for length of the rectangle: ";
  cin>>length;
  cout<<"Enter value for width of the rectangle: ";
  cin>>width;
  cout<<"The new area of the rectangle: ";
  cout<<rectangle(length,width);
  cout<<endl;
  cout<<"\n\nThe default area of the rectangle: ";
  cout<<rectangle(width);
  cout<<endl;
}

else if (choice == 4)
{
  cout<<"Enter value for diagonal-1 of the rhombus: ";
  cin>>diagonal1;
  cout<<"Enter value for diagonal-2 of the rhombus: ";
  cin>>diagonal2;
  cout<<"The new area of the rhombus: ";
  cout<<rhombus(diagonal1,diagonal2);
  cout<<endl;
  cout<<"\n\nThe default area of the rhombus: ";
  cout<<rhombus();
  cout<<endl;
}

else if (choice == 5)
{
  cout<<"Enter value for radius of the circle: ";
  cin>>radius;
  cout<<"The new area of the circle: ";
  cout<<circle(radius);
  cout<<endl;
  cout<<"\n\nThe default area of the circle: ";
  cout<<circle();
  cout<<endl;
}

else if (choice == 6)
{
  cout<<"Enter value for height of the trapezoid: ";
  cin>>Theight;
  cout<<"Enter value for Top base of the trapezoid: ";
  cin>>Tbase;
  cout<<"Enter value for base of the trapezoid: ";
  cin>>base;
  cout<<"The new area of the trapezoid: ";
  cout<<trapezoid(Theight,Tbase,base);
  cout<<endl;
  cout<<"\n\nThe default area of the trapezoid: ";
  cout<<trapezoid(Theight,Tbase);
  cout<<endl;
}
}


}
