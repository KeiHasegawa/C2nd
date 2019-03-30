#include <stdio.h>

/* コマンド行の引数をエコーする; 第3版 */
int main(int argc, char *argv[])
{
  while (--argc > 0)
    printf((argc > 1) ? "%s " : "%s", *++argv);
  printf("\n");
  return 0;
}
