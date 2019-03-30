#include <stdio.h>

int main(void)
{
  int x, *ip;
  int y, *iq;

  x = 1234;
  y = 5678;
  ip = &x;
  iq = &y;
  iq = ip;
  printf("x = %d\n",x);
  printf("y = %d\n",y);
  *iq = 3333;
  printf("x = %d\n",x);
  printf("y = %d\n",y);
  return 0;
}
