#include <stdio.h>

/* 入力される文字をカウント; 第1版 */
int main()
{
  long nc;

  nc = 0;
  while (getchar() != EOF)
    ++nc;
  printf("%ld\n",nc);
  return 0;
}
