#include <stdio.h>

int main(void)
{
  enum escapes { BELL = '\a', BACKSPACE = '\b', TAB = '\t',
		 NEWLINE = '\n', VTAB = '\v', RETURN = '\r' };

  printf("%d %c\n",BELL,BELL);
  printf("%d %c\n",BACKSPACE,BACKSPACE);
  printf("%d %c\n",TAB,TAB);
  printf("%d %c\n",NEWLINE,NEWLINE);
  printf("%d %c\n",VTAB,VTAB);
  printf("%d %c\n",RETURN,RETURN);
  return 0;
}
