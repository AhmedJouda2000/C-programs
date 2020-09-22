#include <stdio.h>
void Go(int steps) ;
int main (void)
{
int sx , sy , dx , dy;
int diff_x , diff_y ;
sx = 4;
sy = 1;
dx = 3;
dy = 5;
diff_x = dx - sx;
diff_y = dy - sy;
if(diff_x>0&&diff_y>0)
{
printf("R ");
Go(diff_x);
printf ("R ");
Go(diff_y);
}
if(diff_x>0&&diff_y< 0)
{
printf("R ");
Go(diff_x);
printf("L ");
Go(-diff_y);
}
if(diff_x<0&&diff_y>0)
{
printf ("L ");
Go(-diff_x);
printf ("L ");
Go(diff_y);
}
if(diff_x<0&&diff_y<0)
{
printf("L ");
Go(-diff_x);
printf ("R ");
Go(-diff_y);
}
printf("\n");
return 0;
}
void Go(int steps)
{
int i;
for (i=0;i< steps ;i++)
{
printf("W ") ;
}
}
