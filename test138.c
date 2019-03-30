#include <stdio.h>

#ifdef _MSC_VER
#define scanf scanf_s
#endif // _MSC_VER

int main()		/* 原始的な電卓プログラム */
{
  double sum, v;

  sum = 0;
  while (scanf("%lf", &v) == 1)
    printf("\t%.2f\n", sum += v);
  return 0;
}
