#include <stdio.h>

int x = 1;
char squote = '\'';
long day = 1000L * 60L * 60L * 24L;    /* ƒ~ƒŠ•b/“ú */

int main(void)
{
  printf("x = %d\n",x);
  printf("squote = '%c'\n",squote);
  printf("day = %ld\n",day);
  return 0;
}
