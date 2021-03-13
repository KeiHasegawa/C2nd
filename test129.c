#include <stdio.h>
#include <stdlib.h>

/* strcmp: s<t なら <0, s==t なら 0, s>t なら >0 を返す */
int mystrcmp(const char* s, const char *t)
{
  int i;

  for (i = 0; s[i] == t[i]; i++)
    if (s[i] == '\0')
      return 0;
  return s[i] - t[i];
}

int mynumcmp(const char *s1, const char *s2)
{
  double v1, v2;

  v1 = atof(s1);
  v2 = atof(s2);
  if (v1 < v2)
    return -1;
  else if (v1 > v2)
    return 1;
  else
    return 0;
}

typedef int (*PFI)(const char *, const char *);

int main(void)
{
  PFI strcmp, numcmp;

  strcmp = &mystrcmp, numcmp = &mynumcmp;

  printf("%d\n",strcmp("hasegawa","kei"));
  printf("%d\n",numcmp("134","-77.3"));
  return 0;
}
