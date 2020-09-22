/*
This is lab 9 questoion 2, Write	a	program	to	count	how
many times	the	word “dogs” occurs	in	a string,	where	the
case of	the	characters in	the	word is ignored.

This is the work of Ahmed Jouda (Student Number 18329393)
Created on 13/11/2018
*/
#include <stdio.h>
#include <string.h>
#define MAX_STR_LEN 100

int main(void)
{
//Get input from user for the sentence
char msg[MAX_STR_LEN];

printf("\nEnter the message:\n");
fgets(msg, MAX_STR_LEN, stdin);

int x= 0, i=0;

//Make the message all in lowercase
while (i < strlen(msg))
{

  if (msg[i] >= 'A' && msg[i] <= 'Z')
  {
    msg[i] = msg[i] + ('a' - 'A');
  }

  i++;
}
//print lowercase message
printf("\nThe message you entered in lowercase: %s\n", msg);

//Look for the word dogs by first finding the letters d,o,g,s in sequence
for (i = 0; i < strlen(msg); i++)
  {
   //check if before the letters d o g s there isnt a letter
    if ((msg[i-1] <= 'a' || msg[i-1] >= 'z') && msg[i] == 'd' && msg[i+1] == 'o' && msg[i+2] == 'g' && msg[i+3] == 's')
    {
      //Check if after the word dogs its the end of the string or its not a letter
      if ((msg[i+4] <= 'a' || msg[i+4] >= 'z') || msg[i+4] == '\0')
      {
       x++;
      }

    }
  }
//print the number of occurrences of the word dogs
printf("\n\nThere are %d occurrences of the word 'dogs' \n", x);



return 0;
}
