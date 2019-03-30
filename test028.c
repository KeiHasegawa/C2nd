#include <stdio.h>

int lower(int c)
{
  if (c >= 'A' && c <= 'Z')
    return c + 'a' - 'A';
  else
    return c;
}

int main(void)
{
  printf("lower('%c') = %c\n",'A',lower('A'));
  printf("lower('%c') = %c\n",'a',lower('a'));
  printf("lower('%c') = %c\n",'Z',lower('Z'));
  printf("lower('%c') = %c\n",'_',lower('_'));
  return 0;
}
