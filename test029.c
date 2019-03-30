#include <stdio.h>

void f(char a)
{
  int i;
  char c;

  c = a;
  i = c;
  c = i;
  printf("%d %d\n",i,c);
  if ( c != a )
    printf("error\n");
}

int main(void)
{
  f(-128);
  f(-1);
  f(0);
  f(127);
  return 0;
}
