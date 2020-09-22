/*

This is Lab 5 Question 4, to compute the first N pavodan numbers

This is the work of Ahmed Jouda (Student Number 18329393)
Created on 9/10/2018

*/
#include <stdio.h>
int main(void)
{

int n, i;

printf("How many terms do you want?\n");
scanf("%d", &n);

int P[n];
P[0] = 1; P[1] = 1; P[2] = 1;  //Assign the first 3 array slots 1,1,1 as these are the first 3 pavodan numbers that dont change

for (i = 3; i < n; i++) {
P[i] = P[i-2] + P[i-3];
}
for (i = 0; i < n; i++) {
  printf("%d\n", P[i]);    
}






return 0;
}
