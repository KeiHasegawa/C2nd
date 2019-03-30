#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

typedef struct tnode *Treeptr;

typedef struct tnode {	/* �؂̃m�[�h */
  char *word;			/* �e�L�X�g�ւ̃|�C���^ */
  int count;			/* �o���� */
  Treeptr left;		/* ���̎q�� */
  Treeptr right;		/* �E�̎q�� */
} Treenode;

#define MAXWORD 100
Treeptr addtree(Treeptr, char *);
void treeprint(Treeptr);
int getword(char *, int);

/* �P��̕p�x�J�E���g */
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

/* addtree: p �̈ʒu���邢�͂��̉��� w �̃m�[�h�������� */
Treeptr addtree(Treeptr p, char *w)
{
  int cond;

  if (p == NULL){	/* �V�����P�ꂪ���� */
    p = talloc();	/* �V�����m�[�h����� */
    p->word = strdup(w);
    p->count = 1;
    p->left = p->right = NULL;
  } else if ((cond = strcmp(w, p->word)) == 0)
    p->count++;			/* �J��Ԃ��ꂽ�P�� */
  else if (cond < 0)		/* ��菬������΍��̕����؂� */
    p->left = addtree(p->left, w);
  else				/* �傫����ΉE�̕����؂� */
    p->right = addtree(p->right, w);
  return p;
}

/* treeprint: �� p ���������ĂĈ� */
void treeprint(Treeptr p)
{
  if (p != NULL) {
    treeprint(p->left);
    printf("%4d %s\n", p->count, p->word);
    treeprint(p->right);
  }
}

/* talloc: tnode ����� */
Treeptr talloc(void)
{
  return (Treeptr) malloc(sizeof(Treenode));
}

/* getword: ���͂��玟�̌�܂��͕��������߂� */
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

char buf[BUFSIZE];    /* ungetch �p�̃o�b�t�@ */
int bufp = 0;         /* buf ���̎��̋󂫈ʒu */

int getch(void)  /* (�����߂��ꂽ�\��������) 1 �������Ƃ��Ă��� */
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)  /* ��������͂ɖ߂� */
{
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}
