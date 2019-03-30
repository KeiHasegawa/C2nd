#include <stdio.h>

struct {
  unsigned int is_keyword : 1;
  unsigned int is_extern  : 1;
  unsigned int is_static  : 1;
} flags;

void f(void)
{
  if (flags.is_keyword)
    printf("keyword ");
  if (flags.is_extern)
    printf("external ");
  if (flags.is_static)
    printf("static ");
  printf("\n");
}

int main(void)
{
  flags.is_extern = flags.is_static = 1;
  f();
  return 0;
}
