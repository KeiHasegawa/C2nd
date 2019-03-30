#define max(A, B)  ((A) > (B) ? (A) : (B))

#include <stdio.h>

void f(int i, int j)
{
  printf("%d\n",max(i++,j++));
  printf("i = %d\n",i);
  printf("j = %d\n",j);
}

int main(void)
{
  f(1,2);
  return 0;
}
