#include <stdio.h>

/* 入力される文字をカウント; 第2版 */
int main()
{
  double nc;

  for ( nc = 0; getchar() != EOF; ++nc)
    ;
  printf("%.0f\n",nc);
  return 0;
}
