#include <stdio.h>

/* cat: ファイルの連結, 第1版 */
int main(int argc, char* argv[])
{
  FILE *fp;
  void filecopy(FILE *, FILE *);

  if (argc == 1)		/* 引数なし; 標準入力をコピー */
    filecopy(stdin, stdout);
  else
    while (--argc > 0)
#ifndef _MSC_VER
      if ((fp = fopen(*++argv, "r")) == NULL){
#else // _MSC_VER
      if ((fopen_s(&fp, *++argv, "r"), fp) == NULL){
#endif // _MSC_VER
	printf("cat: can't open %s\n", *argv);
	return 1;
      } else {
	filecopy(fp, stdout);
	fclose(fp);
      }
  
  return 0;
}

/* filecopy: ファイル ifp をファイル ofp にコピー */
void filecopy(FILE *ifp, FILE *ofp)
{
  int c;

  while ((c = getc(ifp)) != EOF)
    putc(c, ofp);
}
