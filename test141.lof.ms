#include <stdio.h>
#include <stdlib.h>

/* cat: ファイルの連結, 第2版 */
int main(int argc, char *argv[])
{
  FILE* fp;
  void filecopy(FILE *, FILE *);
  char *prog = argv[0];		/* プログラム名. エラー表示で使う */

  if (argc == 1)		/* 引数なし; 標準入力をコピー */
    filecopy(stdin, stdout);
  else
    while (--argc > 0)
#ifndef _MSC_VER
      if ((fp = fopen(*++argv, "r")) == NULL) {
#else // _MSC_VER
      if (fopen_s(&fp, *++argv, "r"), fp == NULL) {
#endif // _MSC_VER
	fprintf(stderr, "%s: can't open %s\n",
		prog, *argv);
	exit(1);
      } else {
	filecopy(fp, stdout);
	fclose(fp);
      }
  if (ferror(stdout)) {
    fprintf(stderr, "%s: error writing stdout\n", prog);
    exit(2);
  }
  exit(0);
}

/* filecopy: ファイル ifp をファイル ofp にコピー */
void filecopy(FILE *ifp, FILE *ofp)
{
  int c;

  while ((c = getc(ifp)) != EOF)
    putc(c, ofp);
}
#include <stdio.h>

int main()
{
  printf("hello, world\n");
  return 0;
}
#include <stdio.h>

/* fahr=0,20,...,300 に対して, 摂氏-華氏対応表
   を印字する */
int main()
{
  int fahr, celsius;
  int lower, upper, step;

  lower = 0;         /* 温度表の下限 */
  upper = 300;       /* 上限 */
  step = 20;         /* きざみ */

  fahr = lower;
  while (fahr <= upper) {
    celsius = 5 * (fahr-32) / 9;
    printf("%d\t%d\n", fahr, celsius);
    fahr = fahr + step;
  }
  return 0;
}
#include <stdio.h>

/* fahr=0,20,...,300 に対して, 摂氏-華氏対応表
   を印字する */
int main()
{
  int fahr, celsius;
  int lower, upper, step;

  lower = 0;         /* 温度表の下限 */
  upper = 300;       /* 上限 */
  step = 20;         /* きざみ */

  fahr = lower;
  while (fahr <= upper) {
    celsius = 5 * (fahr-32) / 9;
    printf("%3d %6d\n", fahr, celsius);
    fahr = fahr + step;
  }
  return 0;
}
D:\home\khasegawa\lang\42_C2nd\test141.exe: can't open not_exist
