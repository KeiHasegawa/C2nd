#include <stdio.h>

#define SIZE 100

int main(void)
{
  int n, array[SIZE], getint(int *);

  for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
    ;

  for ( --n; n > 0; --n)
    printf("%d\n",array[n]);

  return 0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getint: 入力から次の整数を取り出して * pn に入れる */
int getint(int *pn)
{
  int c, sign;

  while (isspace(c = getch()))	/* 空白を飛ばす */
    ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c);
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-')
    c = getch();
  for (*pn = 0; isdigit(c); c = getch())
    *pn = 10* *pn + (c - '0');
  *pn *= sign;
  if ( c != EOF )
    ungetch(c);
  return c;
}

#define BUFSIZE 100

char buf[BUFSIZE];    /* ungetch 用のバッファ */
int bufp = 0;         /* buf 中の次の空き位置 */

int getch(void)  /* (押し戻された可能性もある) 1 文字をとってくる */
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)  /* 文字を入力に戻す */
{
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}
