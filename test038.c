#include <stdio.h>

int f(int n, int z, int a, int b)
{
  if (n > 0)
    if (a > b)
      z = a;
    else
      z = b;
  return z;
}

int main(void)
{
  printf("%d\n",f(3,10,3,2));
  printf("%d\n",f(3,10,3,4));
  printf("%d\n",f(-3,10,3,4));
  return 0;
}
