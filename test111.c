#include <stdio.h>

int main(void)
{
  struct {
    int x;
    int y;
  } x, y, z;

  x.x = 1; x.y = 2;
  y.x = 3; y.y = 4;
  z.x = 5; z.y = 6;
  printf("(%d,%d)\n",x.x,x.y);
  printf("(%d,%d)\n",y.x,y.y);
  printf("(%d,%d)\n",z.x,z.y);
  return 0;
}
