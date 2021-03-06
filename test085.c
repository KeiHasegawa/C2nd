/* strlen: 文字 s の長さを返す */
int my_strlen(char *s)
{
  char* p = s;

  while (*p != '\0')
    p++;
  return p - s;
}

#include <stdio.h>

int main(void)
{
  char a[] = "kei hasegawa";

  printf("my_strlen(%s) = %d\n", a, my_strlen(a));
  return 0;
}
