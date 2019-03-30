#include <stdio.h>

struct point {
  int x;
  int y;
};

/* addpoint: “ñ‚Â‚Ì“_‚ð‰Á‚¦‚é */
struct point addpoint(struct point p1, struct point p2)
{
  p1.x += p2.x;
  p1.y += p2.y;
  return p1;
}

int main(void)
{
  struct point a = { 12, 34 };
  struct point b = { 56, 78 };
  struct point c = addpoint(a,b);
  printf("(%d,%d) + (%d,%d) = (%d,%d)\n",
	 a.x, a.y, b.x, b.y, c.x, c.y);
  return 0;
}
