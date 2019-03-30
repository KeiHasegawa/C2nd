#include <stdio.h>

int binsearch(int x, int v[], int n)
{
  int low = 0;
  int high = n - 1;
  int mid;
  int* p = v;

  printf("low = %d\n",low);
  printf("high = %d\n",high);
  printf("*p = %d\n",*p);

  return 0;
}

int main(void)
{
  int a = 20;
  return binsearch(5,&a,a);
}
