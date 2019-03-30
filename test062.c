#include <stdio.h>

void f(void)
{
  char pattern[] = "ould";
  printf("%s\n",pattern);
}

void g(void)
{
  char pattern[] = { 'o', 'u', 'l', 'd', '\0' };
  printf("%s\n",pattern);
}

int main(void)
{
  f();
  g();
  return 0;
}
