/* strlen: s ‚Ì’·‚³‚ð•Ô‚· */
#ifdef __cplusplus
int strlen(const char s[])
#else
int strlen(char s[])
#endif
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
