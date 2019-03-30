#include <stdio.h>

void f(int n)
{
  int x;
  x = n++;
  printf("x = %d n = %d\n", x, n);
}

void g(int n)
{
  int x;
  x = ++n;
  printf("x = %d n = %d\n", x, n);
}

int main(void)
{
  f(5);
  g(5);
  return 0; 
}
