#include <stdio.h>

void f(void)
{
  int a[10];
  int *pa;
  int x;
  int i;

  a[0] = 9876;
  a[1] = 2345;
  pa = &a[0];
  x = *pa;
  printf("x = %d\n", x);
  printf("*(pa+1) = %d\n", *(pa+1));

  i = 5;
  a[i] = 100;
  printf("*(pa+%d) = %d\n", i, *(pa+i));
}

void g(int i)
{
  int a[10];
  int *pa;
  int x;

  pa = a;
  *pa = x = 5678;
  printf("x = %d pa[0] = %d\n", x, pa[0]);
  *(pa+1) = 147258;
  printf("pa[1] = %d\n", pa[1]);

  *(a+i) = 777;
  printf("pa[%d] = %d\n", i, pa[i]);
}

int main(void)
{
  f();
  g(5);
  return 0;
}
