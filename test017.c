#include <stdio.h>

#define MAXLINE 1000    /* ���͍s�̍ő咷 */

int max;               /* ���܂܂ŏo�Ă����ő咷 */
char line[MAXLINE];    /* ���݂̓��͍s */
char longest[MAXLINE]; /* �i�[����Ă���Œ��s */

int my_getline(void);
void copy(void);

/* �Œ��s���󎚂���;���ʔ� */
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
  if (max > 0)    /* �s�������� */
    printf("%s", longest);
  return 0;
}

/* my_getline: ���ʔ� */
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

/* copy: ���ʔ� */
void copy(void)
{
  int i;
  extern char line[], longest[];

  i = 0;
  while ((longest[i] = line[i]) != '\0')
    ++i;
}
