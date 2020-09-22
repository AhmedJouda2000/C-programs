/*
This is set 5 Question 3. Write a C Program that asks users to rate the
performance of political parties by rating the party’s performance out of ten.
After asking for the rating, the program should ask the questions again for the
next user and so on. After the last user has indicated that there are no more
users, the program should summarise the results, showing which political party
had the highest and lowest rating.

This is the work of Ahmed Jouda (Student Number 18329393)
Created on 28/02/2019
*/

//Include libraries needed
#include <stdio.h>

//define the main function that returns nothing
int main(void)
{

  //Declare and initialise an array of pointers to constant strings
  const char *party[5] = {"FineF", "FineG", "SinnF", "GreenP", "IndependA"};
  //Declare an integer array to store the ratings and intialise it to 0
  int ratings[5] = {0};

  //Declare an integer "finished" and initialise it to 0
  //This will act as a check to see if there are more users
  int finished = 0;
  //Declare an integer i that will act as a loop counter
  int i=0;
  //Declare a temporary variable that will be used to store the rating inputted
  //by the user, then it will be added onto the rating in the the ratings array
  int temp;

  //Keep asking for input (looping) from a new user until 1 is inputted
  while (finished == 0)
  {
    //Prompt user to input a rating from 0 to 10 for each party
    printf("Enter your rating (0-10) for:\n");

    //iterate the while loop 5 times, once for each party for this current user
    while (i<5)
    {
      //Print the party's name so the user can input his rating
      printf("%s: ", party[i]);
      //store the user's rating for this party in the temporary variable "temp"
      scanf("%d", &temp);
      //Add the value in temp to the corresponding party's total in "ratings[]"
      ratings[i] += temp;
      //Increment i by 1 to move to the next party
      i++;
    }
    //print a new line for cleaner display
    printf("\n");
    /*
    assign i to 0 again so that it goes through the 5 parties again for the
    next user
    */
    i = 0;
    //Ask if there is a new user or not, and store the answer in "finished"
    printf("Enter 0 if there is another user:\nOR\nEnter 1 if you are finished:\n");
    scanf("%d", &finished);
    //print a new line for cleaner display
    printf("\n");
  }

  //The following is to get the maximum
  //declare an integer "max" and intialise it as 0, this will act as an array index
  int max = 0;
  //loop over the whole ratings array
  for (size_t i = 0; i < 5; i++)
  {
    //if an element is found to be higher in value than ratings[max]
    if (ratings[i]>ratings[max])
    {
      //assign this index to max
      max = i;
    }
  }
  //Now we have the index of the element with the highest ratings = "max"

  //Say that you are printing the summary
  printf("--------------------------------------------------\nThe summary:\n");
  //Print out the party with the maximum ratings
  /*
    The for loop iterates 5 times to check the 5 parties
    The if statement looks for the party that has the same number of rating
    as that at index max.
    Once that party is found, it's name is printed.
    This allows for mutliple parties having the same max rating and prints both.
  */
  //We also print the actual max rating at "ratings[max]"
  printf("The party(ies) with the the max rating of %d is/are\n", ratings[max]);
  for (size_t i = 0; i < 5; i++)
  {
    if (ratings[max] == ratings[i])
    {
      printf("%s\n", party[i]);
    }
  }


  //The following is to get the minimum
  //declare an integer "min" and intialise it as 0, this will act as an array index
  int min = 0;
  //loop over the whole ratings array
  for (size_t i = 0; i < 5; i++)
  {
    //if an element is found to be lower in value than ratings[max]
    if (ratings[i]<ratings[min])
    {
      //assign this index to min
      min = i;
    }
  }

  //Print out the party with the minimum ratings
  /*
    The for loop iterates 5 times to check the 5 parties
    The if statement looks for the party that has the same number of rating
    as that at index min.
    Once that party is found, it's name is printed.
    This allows for mutliple parties having the same min rating and prints both.
  */
  //We also print the actual min rating at "ratings[min]"
  printf("The party(ies) with the min rating of %d is/are\n", ratings[min]);
  for (size_t i = 0; i < 5; i++)
  {
    if (ratings[min] == ratings[i])
    {
      printf("%s\n", party[i]);
    }
  }


return 0;
}
