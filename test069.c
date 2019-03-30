#include <stdio.h>

#undef getchar
int getchar(void)
{
  return printf("hello, world\n");
}

int main(void)
{
  getchar();
  return 0;
}
