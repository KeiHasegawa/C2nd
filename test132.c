#include <stdio.h>

#define KEYWORD  01
#define EXTERNAL 02
#define STATIC   04

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
  int flags = 0;
  flags |= EXTERNAL | STATIC;
  f(flags);
  return 0;
}
