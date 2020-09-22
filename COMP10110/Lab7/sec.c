#include <stdio.h>
#include <stdlib.h>

#define N 1000000
int compare(const void *ap, const void *bp);
int main(void)
{
  int *lengths;
  int x;
  FILE *fp = fopen("testcase.txt", "w");
  int numSolns = 3; /* number of pairs whose sum matches target to embed */
  int j;
  int len1, len2;

  /* generate a random target */
  x = rand()%20+1;
  lengths = (int *)malloc(sizeof(int)*N);

  /* Generate some solutions */
  for (j=0;j<2*numSolns;j+=2)
    {
      len1 = (rand()%(x*10000000))+1;
      len2 =   x*10000000 - len1;
      lengths[j] = len1;
      lengths[j+1]=len2;
      printf("%d %d\n", lengths[j],lengths[j+1]);
    }

  for (;j<N;j++)
    {
      lengths[j] = (rand()%100000000+1);
    }

  /* sort the lengths using the qsort()
     library function */
  qsort(lengths, N, sizeof(int), compare);

  /* write to the file */
  fprintf(fp, "%d\n", x); /* First the target */
  fprintf(fp, "%d\n", N); /* Next the number of values */
  for (j=0;j<N;j++)
    {
      fprintf(fp, "%d\n", lengths[j]); /* Then the lengths */
    }
  fclose(fp);

  free(lengths);
  return 0;

}

int compare(const void *ap, const void *bp)
{
  int a = *(int *)ap;
  int b = *(int *)bp;
  return (a<b) ? -1 : (a==b) ? 0 : 1;
}
      
