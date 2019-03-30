#include <stdio.h>

struct point { int x, y; };

int main(void)
{
  struct point origin, *pp;

  origin.x = 1234;
  origin.y = 5678;
  pp = &origin;
  printf("origin is (%d,%d)\n",(*pp).x, (*pp).y);
  (*pp).x = -5678;
  pp->y = 1234;
  printf("origin is (%d,%d)\n",pp->x, pp->y);

  return 0;
}
