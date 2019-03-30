#include <stdio.h>

/* “ü—Í‚ğo—Í‚É•¡Ê; ‘æ1”Å */
int main()
{
  int c;

  c = getchar();
  while (c != EOF) {
    putchar(c);
    c = getchar();
  }
  return 0;
}
