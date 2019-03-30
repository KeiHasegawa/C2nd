#include <stdio.h>

void f(int year)
{
  if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    printf("%d is a leap year\n",year);
  else
    printf("%d is not a leap year\n",year);
}

int main(void)
{
  f(0);
  f(4);
  f(100);
  f(200);
  f(400);
  f(2000);
  f(256);
  return 0;
}
