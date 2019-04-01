#include "syscalls.h"
#undef getchar

/* getchar: �o�b�t�@�Ȃ��̒P�ꕶ������ */
int getchar(void)
{
  char c;

  return (read(0, &c, 1) == 1) ? (unsigned char) c : EOF;
}

int main(void)
{
  int c;

  while ((c = getchar()) != EOF )
    putchar(c);
  return 0;
}