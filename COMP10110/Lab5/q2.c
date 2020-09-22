/*

This is Lab 5 Question 2, to compute the first N pell numbers

This is the work of Ahmed Jouda (Student Number 18329393)
Created on 9/10/2018

*/

#include <stdio.h>
int main(void)
{

int a=0, b=1, i, c, n;

printf("How many terms do you want?\n");
scanf("%d", &n);
printf("Sequence is:\n 0\n 1\n");    //This is to print the first 2 numbers in the sequence that are always fixed (n=0 & n=1)

for (i = 1; i <=n-2; i++) {
  c= (2*b) + a;
  printf("%d\n", c);
  a=b;
  b=c;

}



return 0;
}
