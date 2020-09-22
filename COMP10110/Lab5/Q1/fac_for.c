/*

This is Lab 5 Question 1a, Factorial using for loop
This is the work of Ahmed Jouda (Student Number 18329393)
Created on 9/10/2018

*/
#include <stdio.h>
int main(void)
{
int n, i, x=1;

printf("Enter the value of the number you want the factorial for:\n");
scanf("%d", &n);


for (i = 1; i<=n; i++) {
  x=x * i;

}
printf("The answer is %d\n", x);


return 0;
}
