unsigned getbits(unsigned x, int p, int n)
{
  return (x >> (p+1-n)) & ~(~0 << n);
}

#include <stdio.h>

int main(void)
{
  unsigned x;
  int p;
  int n;

  x = 0x1234;
  p = 15;
  n = 8;
  printf("getbits(0x%x,%d,%d) = 0x%x\n",x,p,n,getbits(x,p,n));

  x = 0x9abcdef0;
  p = 27;
  n = 16;
  printf("getbits(0x%x,%d,%d) = 0x%x\n",x,p,n,getbits(x,p,n));
  return 0;
}
