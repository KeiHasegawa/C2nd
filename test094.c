#include <stdio.h>
#include <string.h>

#define MAXLINES 5000		/* �\�[�g���ׂ��ő�̍s�� */

char* lineptr[MAXLINES];	/* �e�L�X�g�s�ւ̃|�C���^ */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void Qsort(char *lineptr[], int left, int right);

/* ���͍s���\�[�g���� */
int main()
{
  int nlines;    /* �ǂݍ��܂ꂽ���͍s�̐� */

  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    Qsort(lineptr, 0, nlines-1);
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("error: input too big to sort\n");
    return 1;
  }
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

/* Qsort: v[left]...v[right] ���㏸���Ƀ\�[�g���� */
void Qsort(char *v[], int left, int right)
{
  int i, last;
  void swap(char *v[], int i, int j);

  if (left >= right)    /* �z�� 2 ��菭�Ȃ��v�f�� */
    return;             /* �܂ނƂ��͉������Ȃ� */
  swap(v, left, (left + right)/2);  /* �����v�f�� */
  last = left;                      /* v[0] �Ɉړ� */
  for (i = left+1; i <= right; i++)    /* ���� */
    if (strcmp(v[i],v[left]) < 0)
      swap(v, ++last, i);
  swap(v, left, last);              /* �����v�f���� */
  Qsort(v, left, last-1);
  Qsort(v, last+1, right);
}

/* swap: v[i] �� v[j] ���������� */
void swap(char *v[], int i, int j)
{
  char* temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}
