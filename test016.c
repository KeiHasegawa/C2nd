#include <stdio.h>
#define MAXLINE 1000    /* ���͍s�̍ő咷 */

int my_getline(char line[], int maxline);
void copy(char to[], char form[]);

/* �ł��������͍s���󎚂��� */
int main()
{
  int len;     /* ���݂̍s�̒��� */
  int max;     /* ���܂܂ŏo�Ă����ő咷 */
  char line[MAXLINE];    /* ���݂̓��͍s */
  char longest[MAXLINE]; /* �i�[����Ă���Œ��s */

  max = 0;
  while ((len = my_getline(line, MAXLINE)) > 0)
    if (len > max) {
      max = len;
      copy(longest,line);
    }
  if (max > 0)    /* �s�������� */
    printf("%s", longest);
  return 0;
}

/* my_getline: s �ɍs�����, ������Ԃ� */
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

/* copy: from �� to �ɃR�s�[; to �͏\���傫���Ɖ��� */
void copy(char to[], char from[])
{
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}
