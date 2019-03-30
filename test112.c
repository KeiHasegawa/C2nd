#include <stdio.h>

int main(void)
{
  struct point {
    int x;
    int y;
  };
  struct point maxpt = { 320, 200 };

  printf("(%d,%d)\n",maxpt.x,maxpt.y);
  return 0;
}
