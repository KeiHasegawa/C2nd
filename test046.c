#include <string.h>

/* reverse: ������ s �����̈ʒu�ŋt���ɂ��� */
void reverse(char s[])
{
  int c, i, j;

  for (i = 0, j = strlen(s)-1; i < j; i++, j--)
    c = s[i], s[i] = s[j], s[j] = c;
}

/* itoa: n �� s �̒��̕����ɕϊ����� */
void itoa(int n, char s[])
{
  int i, sign;

  if ((sign = n) < 0)  /* �������L�^���� */
    n = -n;            /* �����𐳂ɂ��� */
  i = 0;
  do {     /* �������t���ɐ������� */
    s[i++] = n % 10 + '0';    /* ���̌����Ƃ��Ă��� */
  } while ((n /= 10) > 0);    /* ������폜���� */

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

