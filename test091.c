/* strcmp: s<t ‚È‚ç <0, s==t ‚È‚ç 0, s>t ‚È‚ç >0 ‚ð•Ô‚· */
int strcmp(char* s, char *t)
{
  int i;

  for (i = 0; s[i] == t[i]; i++)
    if (s[i] == '\0')
      return 0;
  return s[i] - t[i];
}

#include <stdio.h>

int main(void)
{
  {
    char a[] = "hasegawa";
    char b[] = "hasegawa kei";
    printf("strcmp(%s,%s) = %d\n",a,b,strcmp(a,b));
  }

  {
    char a[] = "hasegawa";
    char b[] = "hasegawa";
    printf("strcmp(%s,%s) = %d\n",a,b,strcmp(a,b));
  }

  {
    char a[] = "hasegawA";
    char b[] = "hasegawa";
    printf("strcmp(%s,%s) = %d\n",a,b,strcmp(a,b));
  }

  return 0;
}
