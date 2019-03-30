#include <stdio.h>

int main(void)
{
  struct point {
    int x;
    int y;
  };
  struct point a = { 12, 34 };
  struct point b;

  b = a;
  printf("(%d,%d)\n",b.x,b.y);
  return 0;
}
