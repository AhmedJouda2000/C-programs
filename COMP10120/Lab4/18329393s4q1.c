/*
This is set 4 Question 1. Write a C Program which prints the size (in bytes)
of the specified variables to the screen.

This is the work of Ahmed Jouda (Student Number 18329393)
Created on 19/02/2019
*/

//Include libraries needed
#include <stdio.h>

//Define the main function that returns nothing
int main (void)
{

char a; //declare variable "a" of type char
int b;  //declare variable "b" of type integer
long c; //declare variable "c" of type long
long long d;  //declare variable "d" of type long long
double e; //declare variable "e" of type double
long double f;  //declare variable "f" of type long double
float g;  //declare variable "g" of type float
int h[5]; //declare an integer array of size 5 called "h"
int *ptr = h; //declare an integer pointer "ptr" and assign it the address of the array (it now points to the 1st element of array "h")


//Now print using the "sizeof" operator the sizes of all the varibales declared above
printf("Size of a character: %d byte\n", sizeof(a));  //This prints 1 as a char takes up 1 byte
printf("Size of an integer: %d bytes\n", sizeof(b));  //This prints 4 as an int takes up 4 bytes
printf("Size of a long: %d bytes\n", sizeof(c));  //This prints 4 as a long takes up 4 bytes
printf("Size of a long long: %d bytes\n", sizeof(d)); //This prints 8 as a long long takes up 8 bytes
printf("Size of a double: %d bytes\n", sizeof(e));  //This prints 8 as a double takes up 8 bytes
printf("Size of a long double: %d bytes\n", sizeof(f)); //This prints 12 as a long double takes up 12 bytes
printf("Size of a float: %d bytes\n", sizeof(g)); //This prints 4 as a float takes up 4 bytes
printf("Size of an integer array of size 5: %d bytes\n", sizeof(h));   //This prints 20 as each integer takes up 4 and there are 5 elements, so 4*5= 20 bytes
printf("Size of a pointer to the previous array: %d bytes\n", sizeof(ptr)); //This prints 4 as the pointer only points to the 1st element of the array which os 1 integer which takes up 4 bytes



}
