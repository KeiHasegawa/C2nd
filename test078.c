void swap(int *px, int *py)	/* *px ‚Æ *py ‚ðŒðŠ·‚·‚é */
{
  int temp;

  temp = *px;
  *px = *py;
  *py = temp;
}

#include <stdio.h>

int main(void)
{
  int x = 12;
  int y = 34;

  swap(&x,&y);
  printf("x = %d\n",x);
  printf("y = %d\n",y);
  return 0;
}
