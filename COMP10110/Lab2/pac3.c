#include <stdio.h>
void Go(int steps) ;
int main (void)
{
int sx , sy , dx , dy;
int diff_x , diff_y ;
sx = 2;   /*Now the pacman goes up or down before left or right, 2 R = D, 0 R = U*/
sy = 1;
dx = 3;
dy = 5;
diff_x = dx - sx;
diff_y = dy - sy;
if(diff_x>0&&diff_y>0)
{
printf("RR ");
Go(diff_y);
printf ("L ");
Go(diff_x);
}
if(diff_x>0&&diff_y< 0)
{
Go(-diff_y);
printf("R ");
Go(diff_x);
}
if(diff_x<0&&diff_y>0)
{
printf ("RR ");
Go(diff_y);
printf ("R ");
Go(-diff_x);
}
if(diff_x<0&&diff_y<0)
{
Go(-diff_y);
printf ("L ");
Go(-diff_x);
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
