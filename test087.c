/* strcpy: t �� s �ɃR�s�[���� ; �z��Y���� */
void strcpy(char *s, const char *t)
{
  int i;

  i = 0;
  while ((s[i] = t[i]) != '\0')
    i++;
}

#include <stdio.h>

int main(void)
{
  char a[100];

  const char* b = "kei hasegawa";
  strcpy(a,b);
  printf("%s\n",a);
  return 0;
}
