#include <stdio.h>

void f(int valid)
{
  if ( !valid )
    printf("not valid\n");
  else
    printf("valid\n");
}

int main(void)
{
  f(0);
  f(1);
  f(0);
  f(3);
  return 0;
}
