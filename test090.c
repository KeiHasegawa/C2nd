/* strcpy: t を s にコピーする ; ポインタ版2 */
void strcpy(char *s, char *t)
{
  while (*s++ = *t++)
    ;
}

#include <stdio.h>

int main(void)
{
  char a[100];

  char b[] = "kei hasegawa";
  strcpy(a,&b[0]);
  printf("%s\n",a);
  return 0;
}
