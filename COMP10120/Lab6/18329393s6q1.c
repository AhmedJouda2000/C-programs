/*
This is set 6 Question 1. Write a C Program which demonstrates copying the
string below to a new string using pointer notation. The new string should not
contain any consonants and the letters should all be converted to uppercase.

This is the work of Ahmed Jouda (Student Number 18329393)
Created on 03/05/2019
*/

//include the libraries needed
#include <stdio.h>
//Define SIZE to 200, as it will be used in array intialization
#define SIZE 200

//insert the prototypes of the functions to be used
void EditString(char *old,char *new);

//define the main function that returns nothing
int main(void)
{
    //intialize a pointer to a char to the given String
    //it stores the address of the 1st char in the string
    char *slogan = "Comp10120 is my favourite module";

    //declare a new char array that will store the modified array
    char new_String[SIZE];

    //Print the string given (unmodified)
    printf("\nOld String:\n %s",slogan);

    //Pass both the unmodified string and the empty new string into "EditString"
    EditString(slogan,new_String);

    //Print the new string (modified by the function)
    printf("\n\nNew string:\n %s\n", new_String);

    return 0;
}

/*
  This function takes out the constants, converts the rest to upper and copies
  the string into the new string via pointers.
  The function takes in 2 pointers to the old and new strings and returns
  nothing.
*/
void EditString (char *old,char *new)
{
    //declare a char that will store each char as we iterate through the string
    char current_char;

    //iterate through the string until the null terminator(End) is reached
    while ( *old != '\0' )
    {
        /*at every iteration intialize "current_char" to the new char that
        "*old" is pointing to. */
        current_char = *old;

        //Check if the char is a number between 0 and 9
        if (current_char >= '0' && current_char <= '9')
        {
          //if it is then assign it the "*new" and increment "*new" by 1
          *new = current_char;
          new++;
        }

        //Check if the char is a vowel or space
        if(current_char == 'a' || current_char == 'e' || current_char == 'u' ||
           current_char == 'i' || current_char == 'o' || current_char == 'A' ||
           current_char == 'E' || current_char == 'U' || current_char == 'I' ||
           current_char == 'O' || current_char == ' ')
        {
            //If its a lowercase vowel then convert it to uppercase
            if (current_char >= 'a' && current_char <= 'z')
            {
                //Taking away 32 from a lowercase changes it to uppercase
                current_char -= 32;
            }
            //assign the  uppercase vowel/space to "*new", increment "*new" by 1
            *new = current_char;
            new++;
        }
        //increment old by 1 to move to the next char
        old++;
        //Null terminate the new string (at the end) in case its finished
        *new='\0';
    }
}
