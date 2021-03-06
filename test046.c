#include <string.h>

/* reverse: 文字列 s をその位置で逆順にする */
void reverse(char s[])
{
  int c, i, j;

  for (i = 0, j = strlen(s)-1; i < j; i++, j--)
    c = s[i], s[i] = s[j], s[j] = c;
}

/* itoa: n を s の中の文字に変換する */
void itoa(int n, char s[])
{
  int i, sign;

  if ((sign = n) < 0)  /* 符号を記録する */
    n = -n;            /* 符号を正にする */
  i = 0;
  do {     /* 数字を逆順に生成する */
    s[i++] = n % 10 + '0';    /* 次の桁をとってくる */
  } while ((n /= 10) > 0);    /* それを削除する */

  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

#include <stdio.h>

int main(void)
{
  char s[10];
  itoa(45678,s);
  printf("%s\n",s);
  itoa(-98765,s);
  printf("%s\n",s);
  itoa(+1234,s);
  printf("%s\n",s);
  return 0;
}

