#include <stdio.h>

void f(int arr[])
{
  int i;

  for (i = 0; i < 8; i++)
    printf("arr[%d] = %d\n", i, arr[i]);
}

void g(int *arr)
{
  int i;

  for (i = 0; i < 8; i++)
    printf("arr[%d] = %d\n", i, arr[i]);
}

void h(int arr[3])
{
  int i;

  for (i = 0; i < 8; i++)
    printf("arr[%d] = %d\n", i, arr[i]);
}


int main(void)
{
  int a[10], i;

  for (i = 0; i < 10; ++i)
    a[i] = 100 + i;

  f(&a[2]);
  f(a+2);
  g(&a[2]);
  g(a+2);
  h(&a[2]);
  h(a+2);
  return 0;
}
