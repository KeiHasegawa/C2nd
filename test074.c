#include <stdio.h>

int main(void)
{
  int x = 1, y = 2, z[10];
  int* ip;          /* ip �� int �ւ̃|�C���^�ł��� */

  ip = &x;          /* ip �͂��� x ���w�� */
  printf("y = %d\n",y);
  y = *ip;          /* y �͂���� 1 �ƂȂ� */
  printf("y = %d\n",y);

  printf("x = %d\n",x);
  *ip = 0;          /* x �͂���� 0 �ƂȂ� */
  printf("x = %d\n",x);

  ip = &z[0];       /* ip �͂��� z ���w�� */
  *ip = 3;
  printf("z[0] = %d\n",z[0]);

  return 0;
}
