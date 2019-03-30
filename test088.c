/* strcpy: t を s にコピーする ; ポインタ版1 */
void strcpy(char *s, char *t)
{
  while ((*s = *t) != '\0') {
    s++;
    t++;
  }
}

#include <stdio.h>

int main(void)
{
  char a[100];

  char b[] = "kei hasegawa";
  strcpy(&a[10],&b[0]);
  printf("%s\n",&a[10]);
  return 0;
}
