#include <stdio.h>
#include <ctype.h>
#undef tolower

int main()	/* “ü—Í‚ğ¬•¶š‚É•ÏŠ·‚·‚é */
{
  int c;

  while ((c = getchar()) != EOF)
    putchar(tolower(c));
  return 0;
}
