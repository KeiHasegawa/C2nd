#include <stdio.h>

int stack[10];
int *p = stack;

void f(int val)
{
  *p++ = val;    /* val ���X�^�b�N�ɐς� */  
}

void g(void)
{
  int val;

  val = *--p;    /* �X�^�b�N�̈�ԏ�� val �ɍ~�낷 */
  printf("val = %d\n",val);
}

int main(void)
{
  f(10);
  f(3);
  f(-5);
  f(777);
  g();
  g();
  g();
  f(132.24);
  g();
  g();
  return 0;
}
