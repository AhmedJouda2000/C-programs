/*
This is set 7 Question 3. Write a C Program which has functions to do the
following:
• Jumble the order of words
• Print the words
• Select a random word

This is the work of Ahmed Jouda (Student Number 18329393)
Created on 27/03/2019
*/

//include the libraries needed (note time.h is for srand(time(NULL)))
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 12  //define MAX to be 12

//define the function "JUMBLE" that takes in a pointer to an int array
//it returns nothing, it randomises the array
void JUMBLE(int array[])
{
  //Instead of inputing a seed every time, the following statement allows the
  //seed to be determined at run time by the system
  srand(time(NULL));

  //iterate over the entire numbers array, which has the indicies of the actual
  //array, so this basically randomises the indicies array "numbers"
  for (size_t i = 0; i < MAX; i++)
  {
    //generate a random number from 1 to i and store it in j
    int j = rand()%(i+1);
    //swap the element in the indicies array at position j with the one at i
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
  }
}

//define the function "PRINT" that takes in a pointer to a pointer and an
//integer array
//we pass the array we wnat printed("myArray") and the indicies array ("numbers")
//it returns nothing, it prints out the contents of the array "myArray"
void PRINT(char **myArray, int array[])
{
  //use a for loop to iterate through the numbers array(indicies) (0 - MAX)
  for (size_t i = 0; i < MAX; i++)
  {
    //at each iteration print the string at position numbers[i] in "myArray"
    //This will print the 12 different strings, one at each iteration
    printf("%s ", myArray[array[i]]);
  }
  printf("\n");
}

//define the function "RANDOM" that takes in a pointer to a pointer
//it returns nothing, it randomises an index and prints myArray with that index
//hence a random word is printed
void RANDOM(char **myArray)
{
  //declare an integer i and assign it a random number between 0 - 11
  int i = rand()%MAX;
  //print the string at the index i in the array "myArray"
  //A random word is printed
  printf("%s\n", myArray[i]);
}


//define the main function that takes in nothing
int main(void)
{
  //declare and initialise an array of pointers of size MAX, as specified in the question
  char *myArray[MAX] = {"COMP10120", "is", "my", "favourite", "module", "and", "I", "learn", "lots", "of", "interesting", "things"};

  //declare and initialise an integer array of size MAX, it will contain the indicies
  int numbers[MAX] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

  //delcare an integer x
  int x; //it will be used to store the user's choice
  //declare an integer y and assign 1 to it, it will act as a bool.
  int y = 1;

  //loop until the user inputs 0 to exit
  while (y == 1)
  {
    //Ask the user for what action they want and store the number in x
    printf("\n-----------------------------------------\n");
    printf("\nEnter the number of the action you want:\n");
    printf("\n1) Print the words\n2) Jumble the order of words and print\n3) Print a random word\n");
    printf("Enter 0 if you are done\n");
    scanf("%d", &x);

    //if the user picks 1 (Print array)
    if (x == 1)
    {
      //call the function "PRINT" with myArray and numbers as arguments
      //This will print the sentence
      printf("\nThe array:\n");
      PRINT(myArray, numbers);
    }

    //if the user picks 2 (Jumble)
    else if (x == 2)
    {
      //first call "JUMBLE" with the argument "numbers", it will jumble the indicies
      //Then call "PRINT" with the arguments "myArray" & "numbers" to print the
      //array with the jumbled indicies, hence a jumbled sentence
      printf("The jumbled array: \n");
      JUMBLE(numbers);
      PRINT(myArray, numbers);
    }

    //if the user picks 3 (Random Word)
    else if (x == 3)
    {
      //call "RANDOM" with the argument "myArray" to print a random array(Word)
      printf("The random word is ->\n");
      RANDOM(myArray);
    }
    //otherwise assign 0 to y to exit the loop and end the program
    else y = 0;
  }
}
