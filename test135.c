#include <stdio.h>
#include <ctype.h>
#undef tolower

int main()	/* 入力を小文字に変換する */
{
  int c;

  while ((c = getchar()) != EOF)
    putchar(tolower(c));
  return 0;
}
