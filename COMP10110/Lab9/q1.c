/*
This is lab 9 questoion 1, Write	a	program	to	count	how	many
words	occur	in	a	string	inputted	by	a	user,	where	a	word is
a	sequence	of	characters	that	are	not	separated	by spaces.

This is the work of Ahmed Jouda (Student Number 18329393)
Created on 12/11/2018
*/
#include <stdio.h>
#define MAX_STR_LEN 50

int main(void)
{
char msg[MAX_STR_LEN];
int i, y = 0, w=0;

printf("Enter the string\n");
fgets(msg, MAX_STR_LEN, stdin);

printf("\n\nYou entered: %s\n", msg);


for (i = 0; msg[i] != '\0'; i++)
{
  if (msg[i+1] == '\0' && w == 0) {
    msg[i+1] = ' ';
    msg[i+2] = '\0';
    w = 1;
  }
  if (msg[i] == ' ' || msg[i] == '\n' || msg[i] == '\t')
  {
    if (msg[i-1] != ' ' && msg[i-1] != '\n' && msg[i-1] != '\t' && i != 0)
    {
        y++;
    }

  }

}
printf("The message contains %d words!\n", y);

}
