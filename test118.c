#include <stdio.h>

struct point {
  int x;
  int y;
};

/* makepoint: x および y から点を構成する */
struct point makepoint(int x, int y)
{
  struct point temp;

  temp.x = x;
  temp.y = y;
  return temp;
}

struct rect {
  struct point pt1;
  struct point pt2;
};

#define XMAX 840
#define YMAX 460

int main(void)
{
  struct rect screen;
  struct point middle;
  struct point makepoint(int, int);

  screen.pt1 = makepoint(0,0);
  screen.pt2 = makepoint(XMAX, YMAX);
  middle = makepoint((screen.pt1.x + screen.pt2.x)/2,
		     (screen.pt1.y + screen.pt2.y)/2);

  printf("((%d,%d),(%d,%d))\n",
	 screen.pt1.x,screen.pt1.y,
	 screen.pt2.x,screen.pt2.y);
  printf("(%d,%d)\n",middle.x,middle.y);

  return 0;
}
