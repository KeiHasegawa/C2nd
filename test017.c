#include <stdio.h>

#define MAXLINE 1000    /* 入力行の最大長 */

int max;               /* いままで出てきた最大長 */
char line[MAXLINE];    /* 現在の入力行 */
char longest[MAXLINE]; /* 格納されている最長行 */

int my_getline(void);
void copy(void);

/* 最長行を印字する;特別版 */
int main()
{
  int len;
  extern int max;
  extern char longest[];

  max = 0;
  while ((len = my_getline()) > 0)
    if (len > max) {
      max = len;
      copy();
    }
  if (max > 0)    /* 行があった */
    printf("%s", longest);
  return 0;
}

/* my_getline: 特別版 */
int my_getline(void)
{
  int c, i;
  for (i = 0; i < MAXLINE-1
	&& (c=getchar()) != EOF && c != '\n'; ++i)
    line[i] = c;
  if (c == '\n') {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';
  return i;
}

/* copy: 特別版 */
void copy(void)
{
  int i;
  extern char line[], longest[];

  i = 0;
  while ((longest[i] = line[i]) != '\0')
    ++i;
}
