#include <stdio.h>

/* ���͂��o�͂ɕ���; ��1�� */
int main()
{
  int c;

  c = getchar();
  while (c != EOF) {
    putchar(c);
    c = getchar();
  }
  return 0;
}
