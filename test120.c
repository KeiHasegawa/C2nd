#include <stdio.h>

struct point {
  int x;
  int y;
};

struct rect {
  struct point pt1;
  struct point pt2;
};

/* ptinrect: p ‚ª r ‚Ì’†‚È‚ç 1, ‚»‚¤‚Å‚È‚¯‚ê‚Î 0 ‚ð•Ô‚·  */
int ptinrect(struct point p, struct rect r)
{
  return p.x >= r.pt1.x && p.x < r.pt2.x
      && p.y >= r.pt1.y && p.y < r.pt2.y;
}

void f(void)
{
  struct point pt = { 5, 3 };
  struct rect rc = { { 0, 0 }, { 10, 10 } };

  if ( ptinrect(pt,rc) )
    printf("ok\n");
  else
    printf("error\n");
}

void g(void)
{
  struct point pt = { -5, 3 };
  struct rect rc = { { 0, 0 }, { 10, 10 } };

  if ( ptinrect(pt,rc) )
    printf("error\n");
  else
    printf("ok\n");
}

int main(void)
{
  f();
  g();
  return 0;
}
