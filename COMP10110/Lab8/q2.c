/*
This is lab 8 question 2, Write	a	simple	substitution	code	for
an	alphabetic	string.	Improve	your	solution	so	that	it	will
handle	uppercase	characters	too.

This is the work of Ahmed Jouda (Student Number 18329393)
Created on 05/11/2018
*/

#include <stdio.h>
#define MAX_SIZE 100

int main(void)
{
char perm[] = "qjczieaungsdfxmphybklortvw";
char permx[] = "QJCZIEAUNGSDFXMPHYBKLORTVW";
char msg[] = "Secret Message To Encode";     //Message to be encoded
int i, j=0;
int x;

//Convert msg into int
/*
We take away the value of the letter from the value of a/A depending on if
 its captial or not, save that into variable x, then assign prem/(x)[x] to
 msg[j] to replace the actual letter. In the case of another symbol it remains
 unchanged as seen in the else statement
 */

for (i = 0; i < MAX_SIZE; i++) {

  if (msg[i] >= 'a' && msg[i] <= 'z')  {
    x = msg[i] - 'a';
    msg[j++] = perm[x];
  }

  else if (msg[i] >= 'A' && msg[i] <= 'Z') {
    x = msg[i] - 'A';
    msg[j++] = permx[x];
  }

  else {msg[j++] = msg[i];}
}

//print the coded message
printf("%s\n", msg);

return 0;
}
