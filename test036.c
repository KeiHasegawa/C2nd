/* bitcount: x �̒���1�ł���r�b�g�𐔂��� */ 
int bitcount(unsigned x)
{
  int b;

  for (b = 0; x != 0; x >>= 1)
    if ( x & 01)
      b++;
  return b;
}

#include <stdio.h>

int main(void)
{
  printf("bitcount(0x98765432) = %d\n",bitcount(0x98765432));
  return 0;
}
