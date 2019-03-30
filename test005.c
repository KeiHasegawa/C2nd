#include <stdio.h>

#define LOWER 0     /* 表の下限 */
#define UPPER 300   /* 上限 */
#define STEP 20     /* ステップ・サイズ */

/* 摂氏-華氏対応表を印字する */
int main()
{
  int fahr;

  for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
    printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
  return 0;
}
