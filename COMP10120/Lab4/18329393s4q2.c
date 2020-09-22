/*
This is set 4 Question 2. Write a C Program that mimics a two-horse race.
The horses’ names are Firefoot and Shadowfox. Each horse will start at the first
grid/space on the race track. The finish line is at 100 hops/spaces away and the
first horse to reach the end wins the race!

This is the work of Ahmed Jouda (Student Number 18329393)
Created on 19/02/2019
*/

//Include the libraries needed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes - pay attention to the use of pointers instead of global variables
void moveFirefoot( int *FirefootPtr);
void moveShadowfox( int *ShadowfoxPtr);
void printCurrentPositions(unsigned int, unsigned int);

//Define the main function that returns nothing
int main()
{
   //Instead of inputing a seed every time, the following statement allows the seed to be determined at run time by the system
   srand(time(NULL));

   int Firefoot  = 1; // Firefoot  current position
   int Shadowfox = 1; // Shadowfox current position
   int counter = 0; // counter for the for loop controling the race.

   //Print "The Race has started"
   puts("The Race has started");

   // loop through the progress on the track and check if the race has ended or not yet
   while (Firefoot  != 100 && Shadowfox != 100)
   {
   //neither of the horses has reached the end of the track (while both are not 100)
   //call functions to move horses on the track and print their current positions
   moveShadowfox(&Shadowfox);
   moveFirefoot(&Firefoot);
   printCurrentPositions(Firefoot, Shadowfox);

   //increment the conuter so we count the iterations
   counter++;

   }

   // After that determine the winner and print message - one horse has passed the end as it is outside the loop.
   //Check if firefoot is higher than Shadowfox, if so print "Firefoot has won!"
   if (Firefoot  > Shadowfox)
   {
      printf("Firefoot has won!\n");
   }

   //Check if Shadowfox is higher than Firefoot, if so print "Shadowfox has won!"
   if (Firefoot  < Shadowfox)
   {
      printf("Shadowfox has won!\n");
   }

   //Check if firefoot & Shadowfox are equal, if so print "Race tied"
   else if (Firefoot == Shadowfox)
   {
     printf("Race tied\n");
   }

   //Print out the number of iterations it took to reach the end of the race
   printf("iterations: %u \n", counter);
}

// progress for Shadowfox
void moveShadowfox( int *ShadowfoxPtr)
{
   // generate random number from 1-10 and assign it to an integer variable "x"
   int x = rand()%10 + 1;

   // determine progress

   //If x is between 1 and 5 (50% of the time) move horse 2 steps forward
   if (x >= 1 && x <= 5)
   {

   // full speed 50% of the time, move it 2 steps forward
      *ShadowfoxPtr += 2;
   }

   //if x is 6 (10%  of the time), move horse 1 step forward
   if (x==6)
   {
     *ShadowfoxPtr += 1;
   }

   //if x is 7 (10% of the time), move horse 3 steps forward
   if (x==7)
   {
     *ShadowfoxPtr += 3;
   }

   //if x is 8 (10% of the time), dont move horse
   if (x==8)
   {
     *ShadowfoxPtr = *ShadowfoxPtr;
   }

   //if x is 9 or 10 (20% of the time), move the horse 2 steps back
   if (x==9 || x==10)
   {
     *ShadowfoxPtr -= 2;
   }

   // check boundaries
   //To stop the horse from going backwards at the start, reset it to position 1
   if (*ShadowfoxPtr < 1)
   {
      *ShadowfoxPtr = 1;
   }

   //if the horse goes over the finish line, reset it back to position 100
   if (*ShadowfoxPtr > 100)
   {
      *ShadowfoxPtr = 100;
   }
}

// progress for Firefoot
void moveFirefoot ( int *FirefootPtr)
{
  // generate random number from 1-10 and assign it to an integer variable "x"
  int x = rand()%10 + 1;

  // determine progress

  //If x is between 1 and 5 (50% of the time) move horse 2 steps forward
  if (x >= 1 && x <= 5)
  {

  // full speed 50% of the time, move it 2 steps forward
     *FirefootPtr += 2;
  }

  //if x is 6 (10%  of the time), move horse 1 step forward
  if (x==6)
  {
    *FirefootPtr += 1;
  }

  //if x is 7 (10% of the time), move horse 3 steps forward
  if (x==7)
  {
    *FirefootPtr += 3;
  }

  //if x is 8 (10% of the time), dont move horse
  if (x==8)
  {
    *FirefootPtr = *FirefootPtr;
  }

  //if x is 9 or 10 (20% of the time), move the horse 2 steps back
  if (x==9 || x==10)
  {
    *FirefootPtr -= 2;
  }

  // check boundaries
  //To stop the horse from going backwards at the start, reset it to position 1
  if (*FirefootPtr < 1)
  {
     *FirefootPtr = 1;
  }
  //if the horse goes over the finish line, reset it back to position 100
  if (*FirefootPtr > 100)
  {
     *FirefootPtr = 100;
  }
}

// display new position
void printCurrentPositions(unsigned int Firefoot, unsigned int Shadowfox)
{
   // loop through race
   for (unsigned int count = 1; count <= 100; ++count)
   {
      // this loop will print a 100 characters at each run: either F = Firefoot,S = Shadowfox,T=tie or a space to
      //give the user an idea of where the horses are at every iteration

      //if both firefoot and Shadowfox are at the same count(position), then print "T" at that position
      if (count == Firefoot  && count == Shadowfox)
      {
        printf("T");
      }

      //if Shadowfox is at count(position) print "S"
      else if (count == Shadowfox)
      {

         printf("S", count);
      }

      //if firefoot is at count(position) print "F"
      else if (count == Firefoot )
      {
         printf("F");
      }

      //if nothing is at that count(position) print a space " "
      else
      {
         printf(" ");
      }
   }

   puts("");
}
