#include <stdio.h>

enum { KEYWORD = 01, EXTERNAL = 02, STATIC = 04 };

void f(int flags)
{
  if (flags & KEYWORD)
    printf("keyword ");
  if (flags & EXTERNAL)
    printf("external ");
  if (flags & STATIC)
    printf("static ");
  printf("\n");
}

int main(void)
{
  int flags = 7;
  flags &= ~(EXTERNAL | STATIC);
  f(flags);
  return 0;
}
