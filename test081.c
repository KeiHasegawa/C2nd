/* strlen: •¶Žš—ñ s ‚Ì’·‚³‚ð•Ô‚· */
int strlen(const char *s)
{
  int n;

  for (n = 0; *s != '\0'; s++)
    n++;
  return n;
}

#include <stdio.h>

int main(void)
{
  char array[] = "kei hasegawa";
  const char *ptr = "dragon book";

  printf("%d\n", strlen("hello, world"));
  printf("%d\n", strlen(array));
  printf("%d\n", strlen(ptr));

  return 0;
}
