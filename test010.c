#include <stdio.h>

/* ���͂̍s�����J�E���g */
int main()
{
  int c, nl;

  nl = 0;
  while ((c = getchar()) != EOF)
    if ( c == '\n' )
      ++nl;
  printf("%d\n",nl);
  return 0;
}
