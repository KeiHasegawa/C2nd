#include <stdio.h>

int main(void)
{
  int x = 1, y = 2, z[10];
  int* ip;          /* ip は int へのポインタである */

  ip = &x;          /* ip はいま x を指す */
  printf("y = %d\n",y);
  y = *ip;          /* y はこれで 1 となる */
  printf("y = %d\n",y);

  printf("x = %d\n",x);
  *ip = 0;          /* x はこれで 0 となる */
  printf("x = %d\n",x);

  ip = &z[0];       /* ip はいま z を指す */
  *ip = 3;
  printf("z[0] = %d\n",z[0]);

  return 0;
}
