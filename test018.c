/* strlen: s ‚Ì’·‚³‚ð•Ô‚· */
int strlen(char s[])
{
  int i;

  i = 0;
  while (s[i] != '\0')
    ++i;
  return i;
}

#include <stdio.h>

int main(void)
{
  printf("strlen(\"hasegawa\") = %d\n",strlen("hasegawa"));
  return 0;
}
