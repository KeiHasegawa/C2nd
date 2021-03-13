/* Atoi: Atof ���g���ĕ����� s �𐮐��ɕϊ����� */
int Atoi(const char s[])
{
  double Atof(const char s[]);

  return (int) Atof(s);
}

#include <ctype.h>

/* Atof: ������ s �� double �ɕϊ����� */
double Atof(const char s[])
{
  double val, power;
  int i, sign;

  for (i=0; isspace(s[i]); i++)    /* �󔒂��΂� */
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
