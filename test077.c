void swap(int x, int y)		/* ‚Ü‚¿‚ª‚¢ */
{
  int temp;

  temp = x;
  x = y;
  y = temp;  
}

#include <stdio.h>

int main(void)
{
  int x = 12;
  int y = 34;

  swap(x,y);
  printf("x = %d\n",x);
  printf("y = %d\n",y);
  return 0;
}
