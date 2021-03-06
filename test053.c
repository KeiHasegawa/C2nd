/* Atoi: Atof を使って文字列 s を整数に変換する */
int Atoi(const char s[])
{
  double Atof(const char s[]);

  return (int) Atof(s);
}

#include <ctype.h>

/* Atof: 文字列 s を double に変換する */
double Atof(const char s[])
{
  double val, power;
  int i, sign;

  for (i=0; isspace(s[i]); i++)    /* 空白を飛ばす */
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  for (val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');
  if ( s[i] == '.')
    i++;
  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val +(s[i] - '0');
    power *= 10.0;
  }
  return sign * val / power;
}

#include <stdio.h>

int main()
{
  printf("%d\n",Atoi("1234"));
  printf("%d\n",Atoi("-5678"));
  return 0;
}
