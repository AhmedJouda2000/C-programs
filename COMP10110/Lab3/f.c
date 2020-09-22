/*
This is the work of Ahmed Jouda
Lab 3 Question 2 (Optional), Only partailly completed
1/10/2018
*/
#include <stdio.h>
#include <math.h>

int main(void)
{
double A, P, r, n, k;
char x;
k=12;
printf("Which do of the following do you want to find out: A,P, r or n\n");
scanf("%c", &x);

if (x=='A') {
  printf("Enter the value of P\n");
  scanf("%lf", &P);
  printf("Enter the value for r\n");
  scanf("%lf", &r);
  printf("Enter the value for n\n");
  scanf("%lf", &n );
  A=P*pow(1+(r/(100*k)),n*k);
  printf("A is:%lf\n", A);
}
  if (x=='P') {
    printf("Enter the value of A\n");
    scanf("%lf", &A);
    printf("Enter the value for r\n");
    scanf("%lf", &r);
    printf("Enter the value for n\n");
    scanf("%lf", &n );
    P=A/pow(1+(r/(100*k)),n*k);
    printf("P is:%lf\n", P);
  }
  if (x=='r') {
    printf("Enter the value of A\n");
    scanf("%lf", &A);
    printf("Enter the value for P\n");
    scanf("%lf", &P);
    printf("Enter the value for n\n");
    scanf("%lf", &n );
    P=A/pow(1+(r/(100*k)),n*k);
    printf("r is:%lf\n", r);
  }
  if (x=='n') {
    printf("Enter the value of A\n");
    scanf("%lf", &A);
    printf("Enter the value for r\n");
    scanf("%lf", &r);
    printf("Enter the value for P\n");
    scanf("%lf", &P );
    P=A/pow(1+(r/(100*k)),n*k);
    printf("n is:%lf\n", n);
  }


return 0;
}
