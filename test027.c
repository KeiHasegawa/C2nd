/* atoi: s ‚ð®”‚É•ÏŠ·‚·‚é */
int atoi(char s[])
{
  int i, n;

  n = 0;
  for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
    n = 10 * n + (s[i] - '0');
  return n;
}

#include <stdio.h>

int main(void)
{
  printf("atoi(\"12345\") = %d\n",atoi("12345"));
  return 0;
}
