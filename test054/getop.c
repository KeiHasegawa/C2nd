#include <ctype.h>
#include <stdio.h>

#include "calc.h"

/* getop: ���̉��Z�q���邢�͐��l�̔퉉�Z�����Ƃ��Ă��� */
int getop(char s[])
{
  int i, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  if (!isdigit(c) && c != '.')
    return c;    /* ���ł͂Ȃ� */
  i = 0;
  if (isdigit(c))    /* ���������W�߂� */
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == '.')    /* ���������W�߂� */
    while (isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  if (c != EOF)
    ungetch(c);
  return NUMBER;
}
