/*
This is set 9 Question 1. Write a C code snippet which creates 5 structs from
the integer array (myCustomers) and writes each struct to a binary file named
cutomers.dat. You can assume each struct is defined with the members shown below.
The integer array (myCustomers) has 2 columns. Column 0 contains the area/zip
code and column 1 contains the number of customers living there available as
shown below.


This is the work of Ahmed Jouda (Student Number 18329393)
Created on 10/04/2019
*/

//include the libraries needed
#include <stdio.h>

//create a struct as specified in the Question
struct zip_custs
{
    int zip_code;
    int customer_count;
};

//define the main function that returns nothing
int main(void)
{
    //declare loop counter
    int i;

    //declare and intialise array as specified in Question
    int myCustomers[5][2] = {{86965, 1}, {36568, 3}, {6565, 0}, {999555,22}, {85446, 88}};

    //declare an array of the struct type zip_custs
    struct zip_custs customers[5];

    //declare a pointer to a file
    FILE *cPtr;

    //open file customers.dat to write in binary wb
    if((cPtr = fopen("customers.dat", "wb")) == NULL)
        {
            printf("File failed to open, confirm it isn't damaged");
        }
    else
        {
            //Assign the value from the 2d array to the stuct array
            for(i = 0; i < 5; i++)
                {
                    customers[i].zip_code = myCustomers[i][0];
                    customers[i].customer_count = myCustomers[i][1];
                }
            //print those values from the struct array to the file
            for(i = 0; i < 5; i++)
                {
                    fprintf(cPtr, "%d %d\n", customers[i].zip_code, customers[i].customer_count);
                }
            //close file
            fclose(cPtr);
        }
    return 0;
}
