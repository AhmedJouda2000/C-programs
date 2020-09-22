/*
This is set 7 Question 1. Write a C Program that defines and uses a  macro to
calculate the minimum of 4 integers. This extended program must reuse the macro
which calculates the minimum of 2 integers. The two programs should get the
input from the command line as the program is run.

This is the work of Ahmed Jouda (Student Number 18329393)
Created on 26/03/2019
*/

//include the libraries needed
#include <stdio.h>
#include <stdlib.h>
//define macro that finds the minimum of 2 numbers
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
//define another macro that finds the minimum of 4 numbers using the previous
//Macro
#define  MIN2(a, b, c, d) (MIN(MIN(a,b), MIN(c, d)))

//define the main function that takes in input from the command line
int main(int argc, char *argv[])
{
  //if the user didnt input 5 arguments in the command line print an error
  if (argc != 5)
  {
    printf("Wrong amount of arguments - after the file name enter 4 numbers\n");
  }

  //if the user entered the right arguments proceed.
  else if (argc == 5)
  {
    //declare 4 integer variables in which the numbers will be stored
    int a, b, c, d;

    //store each of the numbers inputed by the user in the command line into the
    //variables created. These numbers are stored as chars in the array argv[]
    //To change them to integers use the function atoi from stdlib.h
    a = atoi(argv[1]);
    b = atoi(argv[2]);
    c = atoi(argv[3]);
    d = atoi(argv[4]);

    //declare an integer variable z
    //call the second macro MIN2 with the 4 numbers as arguments
    //store the return value in z, it will be the minimum of the 4 numbers
    int z = MIN2(a, b, c, d);

    //print the minimum of the 4 numbers which has been assigned to 'z'
    printf("\n The minimum is %d", z);
  }

}
