#include <stdio.h>
#include <string.h>

#define MAXLINES 5000		/* �\�[�g���ׂ��ő�̍s�� */
char *lineptr[MAXLINES];	/* �e�L�X�g�s�ւ̃|�C���^ */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void Qsort(void *lineptr[], int left, int right,
	   int (*comp)(void *, void *));
int numcmp(const char *, const char *);

/* ���͍s���\�[�g���� */
int main(int argc, char *argv[])
{
  int nlines;			/* �ǂݍ��܂ꂽ���͍s�̐� */
  int numeric = 0;

  if (argc > 1 && strcmp(argv[1], "-n") == 0)
    numeric = 1;
  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    Qsort((void **)lineptr, 0, nlines-1,
	  (int (*)(void *,void *))(numeric ? numcmp : strcmp));
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("input too big to sort\n");
    return 1;
  }
}

/* Qsort: v[left]...v[right] �������Ƀ\�[�g���� */
void Qsort(void *v[], int left, int right,
	   int (*comp)(void *, void *))
{
  int i, last;
  void swap(void *v[], int, int);

  if (left >= right)		/* �z��̗v�f�����肷���� */
    return;			/* �����, �������Ȃ� */
  swap(v, left, (left + right)/2);
  last = left;
  for (i = left+1; i <= right; i++)
    if ((*comp)(v[i], v[left]) < 0)
      swap(v, ++last, i);
  swap(v, left, last);
  Qsort(v, left, last-1, comp);
  Qsort(v, last+1, right, comp);
}

#include <stdlib.h>

/* numcmp: s1 �� s2 �𐔒l�I�ɔ�r���� */
int numcmp(const char *s1, const char *s2)
{
  double v1, v2;

  v1 = atof(s1);
  v2 = atof(s2);
  if (v1 < v2)
    return -1;
  else if (v1 > v2)
    return 1;
  else
    return 0;
}

void swap(void *v[], int i, int j)
{
  void *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

#define MAXLEN 1000		/* �C�ӂ̓��͍s�̍ő咷 */
int my_getline(char *, int);
char *alloc(int);

/* readlines: ���͍s��ǂݍ��� */
int readlines(char *lineptr[], int maxlines)
{
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  while ((len = my_getline(line,MAXLEN)) > 0)
    if (nlines >= maxlines || (p = alloc(len)) == NULL)
      return -1;
    else {
      line[len-1] = '\0';	/* ���s������ */
#ifndef _MSC_VER
      strcpy(p, line);
#else // _MSC_VER
      strcpy_s(p, len, line);
#endif // _MSC_VER
      lineptr[nlines++] = p;
    }
  return nlines;
}

/* writelines: �o�͍s�������o�� */
void writelines(char *lineptr[], int nlines)
{
  int i;

  for (i = 0; i < nlines; i++)
    printf("%s\n", lineptr[i]);
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

#define ALLOCSIZE 10000		/* �g�p�\�ȏꏊ�̑傫�� */
static char allocbuf[ALLOCSIZE];     /* alloc �̂��߂̋L���ꏊ */
static char *allocp = allocbuf;	/* ���̋󂫈ʒu */

char *alloc(int n)		/* n �����ւ̃|�C���^��Ԃ� */
{
  if (allocbuf + ALLOCSIZE - allocp >= n) { /* ���肫�� */
    allocp += n;
    return allocp - n;    /* �Â� p */
  } else    /* �\���ȋ󂫂��Ȃ��Ƃ� */
    return 0;
}
