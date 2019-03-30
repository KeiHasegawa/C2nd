#define ALLOCSIZE 10000		/* 使用可能な場所の大きさ */
static char allocbuf[ALLOCSIZE];     /* alloc のための記憶場所 */
static char *allocp = allocbuf;	/* 次の空き位置 */

char *alloc(int n)		/* n 文字へのポインタを返す */
{
  if (allocbuf + ALLOCSIZE - allocp >= n) { /* 入りきる */
    allocp += n;
    return allocp - n;    /* 古い p */
  } else    /* 十分な空きがないとき */
    return 0;
}

void afree(char *p)    /* p によって指される領域を解放する */
{
  if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
    allocp = p;
}

#include <stdio.h>

void f(int n)
{
  char* p = alloc(n);
  if (p == &allocbuf[0])
    printf("ok\n");
  else
    printf("error\n");

  if (p)
    afree(p);
}

void g(void)
{
  int i;
  char* p[ALLOCSIZE/10];

  for (i = 0; i < ALLOCSIZE/10; i++)
    p[i] = alloc(ALLOCSIZE/10);

  for (i = ALLOCSIZE/10; i > 0; --i)
    afree(p[i-1]);

  f(ALLOCSIZE);
  f(ALLOCSIZE-1);
  f(ALLOCSIZE-5);
  f(ALLOCSIZE);
}

int main(void)
{
  f(ALLOCSIZE);
  f(ALLOCSIZE-1);
  f(ALLOCSIZE-5);
  f(ALLOCSIZE);

  g();

  return 0;
}
