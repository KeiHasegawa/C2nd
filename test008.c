#include <stdio.h>

/* ���͂���镶�����J�E���g; ��1�� */
int main()
{
  long nc;

  nc = 0;
  while (getchar() != EOF)
    ++nc;
  printf("%ld\n",nc);
  return 0;
}
