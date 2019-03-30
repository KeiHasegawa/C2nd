#include <stdio.h>

/* fahr=0,20,...,300 ‚É‘Î‚µ‚Ä, Û-‰Ø‘Î‰•\
   ‚ğˆóš‚·‚é */
int main()
{
  int fahr, celsius;
  int lower, upper, step;

  lower = 0;         /* ‰·“x•\‚Ì‰ºŒÀ */
  upper = 300;       /* ãŒÀ */
  step = 20;         /* ‚«‚´‚İ */

  fahr = lower;
  while (fahr <= upper) {
    celsius = 5 * (fahr-32) / 9;
    printf("%d\t%d\n", fahr, celsius);
    fahr = fahr + step;
  }
  return 0;
}
