#include <stdio.h>

void squeeze(char s[], int c)
{
  int i, j;

  for (i = j = 0; s[i] != '\0'; i++)
    if (s[i] != c)
      s[j++] = s[i];
  s[j] = '\0';
}

int main(void)
{
  char a[] = "hasegawa";
  printf("squeeze(%s,'%c') = ",&a[0],'a');
  squeeze(a,'a');
  printf("%s\n",a);
  return 0;
}
