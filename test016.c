#include <stdio.h>
#define MAXLINE 1000    /* 入力行の最大長 */

int my_getline(char line[], int maxline);
void copy(char to[], char form[]);

/* 最も長い入力行を印字する */
int main()
{
  int len;     /* 現在の行の長さ */
  int max;     /* いままで出てきた最大長 */
  char line[MAXLINE];    /* 現在の入力行 */
  char longest[MAXLINE]; /* 格納されている最長行 */

  max = 0;
  while ((len = my_getline(line, MAXLINE)) > 0)
    if (len > max) {
      max = len;
      copy(longest,line);
    }
  if (max > 0)    /* 行があった */
    printf("%s", longest);
  return 0;
}

/* my_getline: s に行を入れ, 長さを返す */
int my_getline(char s[], int lim)
{
  int c, i;
  for (i=0; i<lim-1 && (c=getchar())!= EOF && c!='\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

/* copy: from を to にコピー; to は十分大きいと仮定 */
void copy(char to[], char from[])
{
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}
