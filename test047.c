#include <string.h>

/* trim: �㑤�̋�, �^�u, ���s��������菜�� */
int trim(char s[])
{
  int n;
  for (n = strlen(s)-1; n >= 0; n--)
    if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
      break;
  s[n+1] = '\0';
  return n;
}

#include <stdio.h>

int main(void)
{
  {
    char a[] = "asdf\t \n  \t\n\t";
    printf("trim(%s) = ",a);
    printf("%d\n",trim(&a[0]));
    printf("%s$\n",a);
  }
  {
    char a[] = " ";
    printf("trim(%s) = ",a);
    printf("%d\n",trim(&a[0]));
    printf("%s$\n",a);
  }
  return 0;
}
