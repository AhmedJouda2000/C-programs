/*
This is lab 8 question 1, Write	a	program	that	reads	a	message	from
a	string	and	changes	all	the lowercase	characters	in	the	string	to
uppercase.

This is the work of Ahmed Jouda (Student Number 18329393)
Created on 05/11/2018
*/

#include <stdio.h>
#define MAX_STR_LEN 50

int main(void)
{
//Create the string array
char msg[MAX_STR_LEN]={"Make this string uppercase"};
int i=0;

//print original message
printf("\nThe original string:\n%s\n", msg);

/* As long as we dont encounter the null terminator or exceed the maximum array size
we check if the character is between a and z, if it is then we change it to its captial
by taking away small a from captial A, this all works due to the ASCII system */

while (i<MAX_STR_LEN && msg[i] != '\0')
{

  if (msg[i] >= 'a' && msg[i] <= 'z')
  {
    msg[i] = msg[i] - ('a' - 'A');
  }

  i++;
}

//print the updated string
printf("\nThe uppercase string is: \n%s\n", msg);


return 0;
}
