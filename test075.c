#include <stdio.h>

int main(void)
{
  int* ip, x = 3, y;
  ip = &x;
  printf("x = %d\n",x);
  *ip = *ip + 3;
  printf("x = %d\n",x);

  y = *ip + 1;
  printf("y = %d\n",y);

  printf("x = %d\n",x);
  *ip += 1;
  printf("x = %d\n",x);

  printf("x = %d\n",x);
  ++*ip;
  printf("x = %d\n",x);

  printf("x = %d\n",x);
  (*ip)++;
  printf("x = %d\n",x);

  return 0;
}
