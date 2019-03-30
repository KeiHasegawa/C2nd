#include <stdio.h>

/* “ü—Í‚³‚ê‚é•¶Žš‚ðƒJƒEƒ“ƒg; ‘æ1”Å */
int main()
{
  long nc;

  nc = 0;
  while (getchar() != EOF)
    ++nc;
  printf("%ld\n",nc);
  return 0;
}
