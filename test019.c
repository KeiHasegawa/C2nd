#include <stdio.h>

enum boolean { NO, YES };

int f(void)
{
  return 10;
}

int main(void)
{
  enum boolean b;
  if ( f() )
    b = YES;
  else
    b = NO;
  printf("b = %d\n",b);
  return 0;
}
