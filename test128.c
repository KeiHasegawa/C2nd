#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

typedef struct tnode *Treeptr;

typedef struct tnode {	/* 木のノード */
  char *word;			/* テキストへのポインタ */
  int count;			/* 出現回数 */
  Treeptr left;		/* 左の子供 */
  Treeptr right;		/* 右の子供 */
} Treenode;

#define MAXWORD 100
Treeptr addtree(Treeptr, char *);
void treeprint(Treeptr);
int getword(char *, int);

/* 単語の頻度カウント */
int main()
{
  Treeptr root;
  char word[MAXWORD];

  root = NULL;
  while (getword(word, MAXWORD) != EOF)
#ifndef _MSC_VER
    if (isalpha(word[0]))
#else // _MSC_VER
    if (0 <= word[0] && word[0] <= 255 && isalpha(word[0]))
#endif // _MSC_VER
      root = addtree(root, word);
  treeprint(root);
  return 0;
}

Treeptr talloc(void);

#ifdef _MSC_VER
#define strdup _strdup
#endif // _MSC_VER

/* addtree: p の位置あるいはその下に w のノードを加える */
Treeptr addtree(Treeptr p, char *w)
{
  int cond;

  if (p == NULL){	/* 新しい単語がきた */
    p = talloc();	/* 新しいノードを作る */
    p->word = strdup(w);
    p->count = 1;
    p->left = p->right = NULL;
  } else if ((cond = strcmp(w, p->word)) == 0)
    p->count++;			/* 繰り返された単語 */
  else if (cond < 0)		/* より小さければ左の部分木へ */
    p->left = addtree(p->left, w);
  else				/* 大きければ右の部分木へ */
    p->right = addtree(p->right, w);
  return p;
}

/* treeprint: 木 p を順序立てて印字 */
void treeprint(Treeptr p)
{
  if (p != NULL) {
    treeprint(p->left);
    printf("%4d %s\n", p->count, p->word);
    treeprint(p->right);
  }
}

/* talloc: tnode を作る */
Treeptr talloc(void)
{
  return (Treeptr) malloc(sizeof(Treenode));
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
    while (c = getch(), 0 <= c && c <= 255 && isspace(c))
#endif // _MSC_VER
    ;
  if (c != EOF)
    *w++ = c;
#ifndef _MSC_VER
  if (!isalpha(c)) {
#else // _MSC_VER
  if (!(0 <= c && c <= 255 && isalpha(c))) {
#endif // _MSC_VER
    *w = '\0';
    return c;
  }
  for ( ; --lim > 0; w++ )
#ifndef _MSC_VER
    if (!isalnum(*w = getch())) {
#else // _MSC_VER
    if (*w = getch(), !(0 <= *w && *w <= 255 && isalnum(*w))) {
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
