/* strcat: t �� s �̏I��ɘA������; s �͏\���傫���Ȃ���΂Ȃ�Ȃ� */
void strcat(char s[], char t[])
{
  int i, j;

  i = j = 0;
  while (s[i] != '\0')    /* s �̏I����T�� */
    i++;
  while ((s[i++] = t[j++]) != '\0')    /* t ���R�s�[���� */
    ;
}

#include <stdio.h>

int main(void)
{
  char a[13];
  char b[] = "hasegawa";
  a[0] = 'k';
  a[1] = 'e';
  a[2] = 'i';
  a[3] = ' ';
  a[4] = '\0';
  strcat(a,b);
  printf("%s\n",a);
  return 0;
}
