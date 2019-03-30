#include <stdio.h>

void f(int a[], int n)
{
  int i;
  for (i = 0; i < n; ++i) {
    if (a[i] < 0)
      continue;
    a[i] *= 2;
  }
}

int main(void)
{
  int a[] = { 3, -2, 0, -5, 4 };
  int i;

  f(a,sizeof a/sizeof a[0]);
  for (i = 0; i < sizeof a/sizeof a[0]; i++)
    printf("%d ",a[i]);
  printf("\n");
  return 0;
}
