#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXWORD 100

struct key {
  const char *word;
  int count;
} keytab[] = {
  "auto", 0,
  "break", 0,
  "case", 0,
  "char", 0,
  "const", 0,
  "continue", 0,
  "default", 0,
  "do", 0,
  "double", 0,
  "else", 0,
  "enum", 0,
  "extern", 0,
  "float", 0,
  "for", 0,
  "goto", 0,
  "if", 0,
  "int", 0,
  "long", 0,
  "register", 0,
  "return", 0,
  "short", 0,
  "signed", 0,
  "sizeof", 0,
  "static", 0,
  "struct", 0,
  "switch", 0,
  "typedef", 0,
  "union", 0,
  "unsigned", 0,
  "void", 0,
  "volatile", 0,
  "while", 0
};

#define NKEYS (sizeof keytab / sizeof keytab[0])

int getword(char *, int);
struct key *binsearch(char *, struct key *, int);

/* C のキーワードを数える： ポインタ版 */
int main()
{
  char word[MAXWORD];
  struct key* p;

  while (getword(word, MAXWORD) != EOF)
#ifndef _MSC_VER
    if (isalpha(word[0]))
#else // _MSC_VER
    if (0 <= word[0] && word[0] <= 255 && isalpha(word[0]))
#endif // _MSC_VER
      if ((p=binsearch(word, keytab, NKEYS)) != NULL)
	p->count++;
  for (p = keytab; p < keytab + NKEYS; p++)
    if (p->count > 0)
      printf("%4d %s\n", p->count, p->word);
  return 0;
}

/* binsearch: tab[0]...tab[n-1] の中の語を探す */
struct key *binsearch(char *word, struct key *tab, int n)
{
  int cond;
  struct key* low = &tab[0];
  struct key* high = &tab[n];
  struct key *mid;

  while (low < high) {
    mid = low + (high-low) / 2;
    if ((cond = strcmp(word, mid->word)) < 0)
      high = mid;
    else if (cond > 0)
      low = mid + 1;
    else
      return mid;
  }
  return NULL;
}

/* getword: 入力から次の語または文字を求める */
int getword(char *word, int lim)
{
  int c, getch(void);
  void ungetch(int);
  char *w = word;
#ifndef _MSC_VER
  while (isspace(c = getch()))
#else // _MSC_VER
  while (c = getch(), 0<= c && c <= 255 && isspace(c))
#endif // _MSC_VER
    ;
  if (c != EOF)
    *w++ = c;
#ifndef _MSC_VER
  if (!isalpha(c)) {
#else // _MSC_VER
  if (0 <= c && c <= 255 && !isalpha(c)) {
#endif // _MSC_VER
    *w = '\0';
    return c;
  }
  for ( ; --lim > 0; w++ )
#ifndef _MSC_VER
    if (!isalnum(*w = getch())) {
#else // _MSC_VER
    if (*w = getch(), 0<= *w && *w <= 255 && !isalnum(*w)) {
#endif // _MSC_VER
      ungetch(*w);
      break;
    }
  *w = '\0';
  return word[0];
}

#define BUFSIZE 100

char buf[BUFSIZE];    /* ungetch 用のバッファ */
int bufp = 0;         /* buf 中の次の空き位置 */

int getch(void)  /* (押し戻された可能性もある) 1 文字をとってくる */
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)  /* 文字を入力に戻す */
{
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}
