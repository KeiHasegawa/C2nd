#include <stdio.h>

struct point {
  int x;
  int y;
};

struct point f()
{
  struct point a = { 12, 34 };
  return a;
}

int main(void)
{
  struct point b;

  b = f();
  printf("(%d,%d)\n",b.x,b.y);
  return 0;
}
