#include <stdio.h>

void f(int (*a)[13])
{
  int i, j;

  for (i = 0; i < 2; i++){
    for (j = 0; j < 13; j++)
      printf("%d ",a[i][j]);
    printf("\n");
  }
}

int main(void)
{
  int daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
  };
  f(daytab);
  return 0;
}
