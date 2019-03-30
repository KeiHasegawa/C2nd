#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

struct point {
  int x;
  int y;
};

struct rect {
  struct point pt1;
  struct point pt2;
};

/* canonrect: 長方形の座標を標準形にする */
struct rect canonrect(struct rect r)
{
  struct rect temp;

  temp.pt1.x = min(r.pt1.x, r.pt2.x);
  temp.pt1.y = min(r.pt1.y, r.pt2.y);
  temp.pt2.x = max(r.pt1.x, r.pt2.x);
  temp.pt2.y = max(r.pt1.y, r.pt2.y);
  return temp;
}

#include <stdio.h>

int main(void)
{
  struct rect screen = { 20, -1, -3, 5 };

  printf("((%d,%d),(%d,%d))\n",
	 screen.pt1.x,screen.pt1.y,
	 screen.pt2.x,screen.pt2.y);

  screen = canonrect(screen);

  printf("((%d,%d),(%d,%d))\n",
	 screen.pt1.x,screen.pt1.y,
	 screen.pt2.x,screen.pt2.y);

  return 0;
}
