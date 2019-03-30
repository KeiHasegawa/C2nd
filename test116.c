#include <stdio.h>
#include <math.h>

int main(void)
{
  struct point {
    int x;
    int y;
  };
  double dist;
  struct point pt = { 20, 30 };

  dist = sqrt((double)pt.x * pt.x + (double)pt.y * pt.y);
  printf("distance(%d,%d) = %lf\n",pt.x,pt.y,dist);
  return 0;
}
