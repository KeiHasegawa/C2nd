#include <stdio.h>
#include <string.h>

#define MAXLINES 5000		/* ソートすべき最大の行数 */
char *lineptr[MAXLINES];	/* テキスト行へのポインタ */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void Qsort(void *lineptr[], int left, int right,
	   int (*comp)(void *, void *));
int numcmp(const char *, const char *);

/* 入力行をソートする */
int main(int argc, char *argv[])
{
  int nlines;			/* 読み込まれた入力行の数 */
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

/* Qsort: v[left]...v[right] を昇順にソートする */
void Qsort(void *v[], int left, int right,
	   int (*comp)(void *, void *))
{
  int i, last;
  void swap(void *v[], int, int);

  if (left >= right)		/* 配列の要素が二よりすくな */
    return;			/* ければ, 何もしない */
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

/* numcmp: s1 と s2 を数値的に比較する */
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

#define MAXLEN 1000		/* 任意の入力行の最大長 */
int my_getline(char *, int);
char *alloc(int);

/* readlines: 入力行を読み込む */
int readlines(char *lineptr[], int maxlines)
{
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  while ((len = my_getline(line,MAXLEN)) > 0)
    if (nlines >= maxlines || (p = alloc(len)) == NULL)
      return -1;
    else {
      line[len-1] = '\0';	/* 改行を消す */
#ifndef _MSC_VER
      strcpy(p, line);
#else // _MSC_VER
      strcpy_s(p, len, line);
#endif // _MSC_VER
      lineptr[nlines++] = p;
    }
  return nlines;
}

/* writelines: 出力行を書き出す */
void writelines(char *lineptr[], int nlines)
{
  int i;

  for (i = 0; i < nlines; i++)
    printf("%s\n", lineptr[i]);
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

#define ALLOCSIZE 10000		/* 使用可能な場所の大きさ */
static char allocbuf[ALLOCSIZE];     /* alloc のための記憶場所 */
static char *allocp = allocbuf;	/* 次の空き位置 */

char *alloc(int n)		/* n 文字へのポインタを返す */
{
  if (allocbuf + ALLOCSIZE - allocp >= n) { /* 入りきる */
    allocp += n;
    return allocp - n;    /* 古い p */
  } else    /* 十分な空きがないとき */
    return 0;
}
