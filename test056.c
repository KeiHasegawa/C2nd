#include <stdio.h>

int x = 1234;
int y = 5678;

void f(double x)
{
  double y;
  y = x - 1;
  printf("%lf - %d = %lf\n",x,1,y);
}

int main(void)
{
  printf("x = %d\n",x);
  f(1.234);
  printf("y = %d\n",y);
  return 0;
}
