#include <stdio.h>

/* “ü—Í‚³‚ê‚é•¶Žš‚ðƒJƒEƒ“ƒg; ‘æ2”Å */
int main()
{
  double nc;

  for ( nc = 0; getchar() != EOF; ++nc)
    ;
  printf("%.0f\n",nc);
  return 0;
}
