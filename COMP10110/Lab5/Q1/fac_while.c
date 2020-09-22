/*

This is Lab 5 Question 1a, factorial using while loop

This is the work of Ahmed Jouda (Student Number 18329393)
Created on 9/10/2018

*/
#include <stdio.h>
int main(void)
{
int n, i, x=1;
i=1;
printf("Enter the value of the number you want the factorial for:\n");
scanf("%d", &n);

while (i<=n) {
  x=x*i;
  i++;
}

printf("The answer is %d\n", x);


return 0;
}
