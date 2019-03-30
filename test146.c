#include "syscalls.h"
#undef getchar

/* getchar: �P��o�b�t�@�� */
int getchar(void)
{
  static char buf[BUFSIZ];
  static char *bufp = buf;
  static int n = 0;

  if (n == 0) {	/* �o�b�t�@�̓J�� */
    n = read(0, buf, sizeof buf);
    bufp = buf;
  }
  return (--n >= 0) ? (unsigned char) *bufp++ : EOF;
}

int main(void)
{
  int c;

  while ((c = getchar()) != EOF )
    putchar(c);
  return 0;
}
