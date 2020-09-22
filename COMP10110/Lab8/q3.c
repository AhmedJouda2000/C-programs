/*
This is lab 8 question 3, Write	a	program	that,	given	the	same	permutation
string,	can	decode a message that	was	encoded	with the method of Question 2.

This is the work of Ahmed Jouda (Student Number 18329393)
Created on 06/11/2018
*/

#include <stdio.h>
#define MAX_SIZE 100

int main(void)
{
char perm[] = "qjczieaungsdfxmphybklortvw";
char permx[] = "QJCZIEAUNGSDFXMPHYBKLORTVW";
char alpha[] = "abcdefghijklmnopqrstuvwxyz";
char alphax[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char code[] = "Bicyik Fibbqai Km Ixcmzi";  //Message to be decoded
int i, j;
/*
We compare each letter of the coded message with the permutation array till we
match it, we then get its position and find the letter in the same position in
the alphabet array and replace the coded letter with it. This loops till we hit
the null terminator.
*/
  for (i = 0;code[i] != '\0'; i++)
 {
    for (j = 0; j < 26; j++)
    {
      if (code[i] == perm[j])
        {
        code[i] = alpha[j];
        break;
        }
      else if (code[i] == permx[j])
        {
        code[i] = alphax[j];
        break;
        }

        else {code[i] = code[i];}

    }
}
//Print the decoded message
printf("%s\n", code);

return 0;
}
