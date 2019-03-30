#include <stdio.h>

/* printd: n ‚ğ 10 i”‚Åˆóš */
void printd(int n)
{
  if (n < 0) {
    putchar('-');
    n = -n;
  }
  if (n / 10)
    printd(n / 10);
  putchar(n % 10 + '0');
}

int main(void)
{
  printd(12345678);
  printf("\n");
  printd(-9876543);
  printf("\n");
  return 0;
}
