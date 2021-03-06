#include <ctype.h>

/* atoi: s を整数に変換する; 第2版 */
int atoi(const char s[])
{
  int i, n, sign;

  for (i = 0; isspace(s[i]); i++)  /* 空白を飛ばす */
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')  /* 符号を飛ばす */
    i++;
  for (n = 0; isdigit(s[i]); i++)
    n = 10 * n + (s[i] - '0');
  return sign * n;
}

#include <stdio.h>

int main(void)
{
  printf("atoi(\"1234\") = %d\n",atoi("1234"));
  printf("atoi(\"+5678\") = %d\n",atoi("+5678"));
  printf("atoi(\"-9012\") = %d\n",atoi("-9012"));
  return 0;
}
