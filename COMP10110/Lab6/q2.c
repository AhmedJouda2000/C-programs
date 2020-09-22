/*
This is lab 6 questoion 2, Write	a	program	to read	an integer N and write out the base	2
representation of	N

  This is the work of Ahmed Jouda (Student Number 18329393)
  Created on 15/10/2018
*/
#include <stdio.h>
#define MAX 5000


int main(void)
{

int N, i;
int digit=0;
int a[MAX], x = 0;

printf("Enter the value of N\n");
scanf("%d", &N);

int Num=N;

/*
Do the calculation for getting binary from decimal in a while
loop so that its done till we get 0
*/
while (Num!=0) {
  digit = Num%2;
  Num = Num/2;
  a[x] = digit;
  x++;
}

// Now print out the array of remainders
printf("The binary representation is: ");
for (i = x-1; i >=0; i--) {
  printf("%d", a[i]);
}

return 0;
}
