#include <stdio.h>

int main(void)
{
  struct point {
    int x;
    int y;
  };
  struct point pt;

  pt.x = 3;
  pt.y = 5;
  printf("(%d,%d)\n",pt.x,pt.y);
  return 0;
}
