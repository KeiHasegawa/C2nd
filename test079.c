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

/* getint: ���͂��玟�̐��������o���� * pn �ɓ���� */
int getint(int *pn)
{
  int c, sign;

  while (isspace(c = getch()))	/* �󔒂��΂� */
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

char buf[BUFSIZE];    /* ungetch �p�̃o�b�t�@ */
int bufp = 0;         /* buf ���̎��̋󂫈ʒu */

int getch(void)  /* (�����߂��ꂽ�\��������) 1 �������Ƃ��Ă��� */
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)  /* ��������͂ɖ߂� */
{
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}
