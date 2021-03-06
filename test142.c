#include <stdio.h>

/* fgets: iop から最大 n 文字を得る */
char *fgets(char *s, int n, FILE * iop)
{
  register int c;
  register char *cs;

  cs = s;
  while (--n > 0 && (c=getc(iop)) != EOF)
    if ((*cs++ = c) == '\n')
      break;
  *cs = '\0';
  return (c == EOF && cs == s) ? NULL : s;
}

/* fputs: ファイル iop に文字列 s を出す */
int fputs(const char *s, FILE *iop)
{
  int c;

  while (c = *s++)
    putc(c, iop);
  return ferror(iop) ? EOF : 0;
}

int main(void)
{
  char line[256];
  while (fgets(line, sizeof line, stdin))
    fputs(line, stdout);

  return 0;
}
