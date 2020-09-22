#include <stdio.h>
#include <stdlib.h>
void Go(int steps) ;
int main (void)

{
int sx , sy , dx , dy;
int diff_x , diff_y , diff_p;
sx = 4;
sy = 1;
dx = 6;
dy = 3;
diff_x = dx - sx;
diff_y = dy - sy;
diff_p = abs(diff_y) + abs(diff_x); /*This gives us the number of steps needed to
get to the destination*/

/*This should do the zigzag for when diff in x and y are positive*/
if(diff_x>0&&diff_y>0)
{
  printf("R R W ");
  {

for (size_t i = diff_p; i < 0; i--);
Go(1);
  }
}


printf("\n");
return 0;
}
void Go(int steps)
{
int i;
for (i=0;i< steps ;i++)
{
printf("L W ") ;
}
}
