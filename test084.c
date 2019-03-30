#include <stdio.h>

int main(void)
{
  int *a;
  int b[10];
  int *c;

  c = b;

  for (a = &b[0]; a != &b[10]; ++a)
    *a = 10*(a - c);

  for (a = &b[0]; a != &b[10]; ++a)
    printf("%d %ld\n", *a, a-c);

  return 0;
}
