struct point {
  int x;
  int y;
};

struct rect {
  struct point pt1;
  struct point pt2;
};

#include <stdio.h>

int main(void)
{
  struct rect screen;

  screen.pt1.x = 1;
  screen.pt1.y = 2;
  screen.pt2.x = 3;
  screen.pt2.y = 4;
  printf("((%d,%d),(%d,%d))\n",
	 screen.pt1.x,screen.pt1.y,screen.pt2.x,screen.pt2.y);
  return 0;
}
