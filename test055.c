#include <stdio.h>

int i = 2345;

void f(int n)
{
  printf("i = %d\n",i);
  if (n > 0){
    int i;
    for ( i = 0; i < n ; i++)
      printf("i = %d\n",i);
  }
  printf("i = %d\n",i);
}

int main(void)
{
  f(10);
  return 0;
}
