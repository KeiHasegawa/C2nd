#define max(A, B)  ((A) > (B) ? (A) : (B))

#include <stdio.h>

void f(int p, int q, int r, int s)
{
  printf("%d\n",max(p+q,r+s));
}

int main(void)
{
  f(1,2,3,4);
  return 0;
}
