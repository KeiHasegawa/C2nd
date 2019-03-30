#include <stdio.h>
#define MAXLINE 1000    /* 入力行の最大長 */

int my_getline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";    /* 探すべきパターン */

/* パターンにマッチするすべての行を探す */
int main()
{
  char line[MAXLINE];
  int found = 0;

  while (my_getline(line,MAXLINE) > 0)
    if (strindex(line, pattern) >= 0) {
      printf("%s", line);
      found++;
    }
  printf("found = %d\n",found);
  return 0;
}

/* my_getline: s に行を入れ, 長さを返す */
int my_getline(char s[], int lim)
{
  int c, i;

  i = 0;
  while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
    s[i++] = c;
  if (c == '\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
}

/* strindex: s における t のインデックスを返す, どこにもなければ -1 */
int strindex(char s[], char t[])
{
  int i, j, k;

  for (i = 0; s[i] != '\0'; i++) {
    for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
      ;
    if (k > 0 && t[k] == '\0')
      return i;
  }
  return -1;
}
