#include <stdio.h>
#include <ctype.h>
#undef tolower

int main()	/* ���͂��������ɕϊ����� */
{
  int c;

  while ((c = getchar()) != EOF)
    putchar(tolower(c));
  return 0;
}
