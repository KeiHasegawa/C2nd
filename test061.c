#include <stdio.h>

int main(void)
{
  int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  int i;

  for (i = 0; i < sizeof days/sizeof days[0]; i++)
    printf("days[%d] = %d\n",i,days[i]);
  return 0;
}
