#include <stdio.h>

#define dprint(expr) printf(#expr " = %g\n", expr)

int main(void)
{
  double x = 123.45;
  double y = 1.8;
  dprint(x/y);
  return 0;
}
