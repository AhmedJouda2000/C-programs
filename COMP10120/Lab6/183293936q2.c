/*
This is set 6 Question 2. Write a C Program which prompts the user for student
records and then writes each record to a file called students.txt. The user
should be prompted to enter each student’s first name, surname, student number,
phone number, field of study, and GPA. A separate function in your programme
should be able to process students.txt and print each student’s student number
and indicate if the student’s GPA corresponds to a 1st, a 2.1 a 2.2 or pass.

This is the work of Ahmed Jouda (Student Number 18329393)
Created on 08/05/2019
*/

//include the libraries needed
#include <stdio.h>

//include the function prototypes
int function(void);

//declare the function main that returns nothing
int main(void)
{
    //declare pointer to the file
    FILE *cfPtr;

    //fopen opens the file, if a problem occurs it exists and print an error message
    if ((cfPtr = fopen("students.txt", "w")) == NULL )
    {
        puts("File could not be opened");
    }

    //if the file opens:
    else
    {
        //print the list of things needed
        puts("Enter:\n1) First name\n2) Surname\n3) Student number\n4) Phone number\n5) Field of study (No spaces)\n6) GPA");


        char name[30];            //declare a char array for the 1st name
        char surname[30];         //delcare a char array for the last name
        long int student_number;  //declare a long int for the student number
        char phone_number[20];    /*
                                  declare a char array for the phone number
                                  we use an array instead of an integer so we
                                  can take 0 as input
                                  */
        char field_of_study[30];  //declare a char array for field of study
        double GPA;               // delcare a double for the GPA

        //declare an integer and intialize it to 1, it will act as a bool
        int x = 1;

        //This loop acts as a check for invalid data
        //while x is 1 loop
        while (x == 1)
        {
          //prompt the user to enter details and store them appropriatly
          printf( "Enter Details:\n" );
          scanf ("%s %s %ld %s %s %lf", name,surname, &student_number,phone_number,field_of_study,&GPA);

          //Check if the GPA is outside the correct range
          //if its outside the range print an error message
          if ((GPA > 4.2) || (GPA < 0))
          {
            printf("ERROR - GPA outside range - retry\n");
          }

          //Check if the student number is a positive number
          //If it isnt show the error message
          else  if (student_number<0)
          {
            printf("ERROR - Student number has to be a positive number - retry\n");
          }

          //otherwise assign 0 to x to exit the loop
          else x = 0;
        }





        //loop as long as the end of file is not reached
        while( !feof(stdin) )
        {
            //print to the file the values of the variables entered by the user
            fprintf(cfPtr, "%s %s %ld %s %s %.2f\n",name,surname,student_number,phone_number,field_of_study,GPA);
            int z = 1;
            while (z == 1)
            {
              //Ask the user to either input details of the next student or to end file
              //if he inputs data store it in the appropriate variables
              printf("Enter Details for next user: (ctrl+z to end)\n" );
              scanf ("%s %s %ld %s %s %lf", name,surname,&student_number,phone_number,field_of_study,&GPA);

              //Check if the GPA is outside the correct range
              //if its outside the range print an error message
              if ((GPA > 4.2) || (GPA < 0))
              {
                printf("ERROR - GPA outside range - retry\n");
              }

              //Check if the student number is a positive number
              //If it isnt show the error message
              else  if (student_number<0)
              {
                printf("ERROR - Student number has to be a positive number - retry\n");
              }

              //otherwise assign 0 to z to exit the loop
              else z = 0;
            }


        }
        //close the file
        fclose(cfPtr);
    }
    //call the function "function" to display the results
    function();
}


//declare the function "function" that takes in nothing
//It will check the GPAs and print the class and student numbers
int function(void)

{
    //declare a file pointer
    FILE *cfPtr;

    //fopen opens the file, if a problem occurs it exists and print an error message
    if ((cfPtr = fopen("students.txt", "r")) == NULL )
    {
      puts("File could not be opened");
    }

    //if the file is opened:
    else
    {
        char name[30];            //declare a char array for the 1st name
        char surname[30];         //delcare a char array for the last name
        long int student_number;  //declare a long int for the student number
        char phone_number[20];    /*
                                  declare a char array for the phone number
                                  we use an array instead of an integer so we
                                  can take 0 as input
                                  */
        char field_of_study[30];  //declare a char array for field of study
        double GPA;               // delcare a double for the GPA

        //Print the headers for the table with appropriate spacing
        printf("%-20s          Class\n","Student number");
        //output the required data from the file to the variables created
        fscanf (cfPtr,"%s%s%ld%s%s%lf", name,surname,&student_number,phone_number,field_of_study,&GPA);

        //while the end of file is not reached
        while (!feof(cfPtr) )
        {
            //check the GPA and accordingly print the students number and class
            if (GPA>=3.68)
            {
                printf("%-20ld          1st Class Honours\n",student_number);
            }

            if (GPA<=3.67 && GPA>=3.08)
            {
                printf("%-20ld          2nd Class Honours - Grade 1\n",student_number);
            }

            if (GPA<=3.07 && GPA>=2.48)
            {
                printf("%-20ld          2nd Class Honours - Grade 2\n",student_number);
            }

            if (GPA<=2.47 && GPA>=2)
            {
                printf("%-20ld          Pass\n",student_number);
            }

            if (GPA<2 && GPA>=0)
            {
                printf("%-20ld          Failed\n",student_number);
            }

            printf("************************************\n");

            //Output the next set variables from the file and place them in the variables created
            fscanf (cfPtr,"%s%s%ld%s%s%lf", name,surname,&student_number,phone_number,field_of_study,&GPA);
        }
        //Close the file
        fclose(cfPtr);
    }
}
