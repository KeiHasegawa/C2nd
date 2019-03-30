#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };

void dcl(void);
void dirdcl(void);

int gettoken(void);
int tokentype;			/* �Ō�̃g�[�N���̌^ */
char token[MAXTOKEN]; 		/* �Ō�̃g�[�N�������� */
char name[MAXTOKEN];	       	/* ���ʎq */
char datatype[MAXTOKEN];		/* �f�[�^�^=char, int �Ȃ� */
char out[1000];			/* �o�͕����� */

int main()    /* �錾�����Ƃ΂ɂ��L�q�ɕϊ����� */
{
  while (gettoken() != EOF) {	/* �s�̍ŏ��̃g�[�N���� */
#ifndef _MSC_VER
    strcpy(datatype, token);		/* �f�[�^�^�ł��� */
#else // _MSC_VER
    strcpy_s(datatype, sizeof datatype, token);
#endif // _MSC_VER
    out[0] = '\0';
    dcl();			/* �c��̍s����� */
    if (tokentype != '\n')
      printf("syntax error\n");
    printf("%s: %s %s\n", name, out, datatype);
  }
  return 0;
}

/* dcl: �錾�q����͂��� */
void dcl(void)
{
  int ns;

  for (ns = 0; gettoken() == '*'; )    /* '*' �𐔂��� */
    ns++;
  dirdcl();
  while (ns-- > 0)
#ifndef _MSC_VER
    strcat(out, " pointer to");
#else // _MSC_VER
    strcat_s(out, sizeof out, " pointer to");
#endif // _MSC_VER
}

/* dirdcl: ���ڂ̐錾�q����͂��� */
void dirdcl(void)
{
  int type;

  if (tokentype == '(' ){	/* (dcl) */
    dcl();
    if (tokentype != ')')
      printf("error: missing )\n");
  } else if (tokentype == NAME)	/* variable name */
#ifndef _MSC_VER
    strcpy(name, token);
#else // _MSC_VER
    strcpy_s(name, sizeof name, token);
#endif // _MSC_VER
  else
    printf("error: expected name or (dcl)\n");
  while ((type=gettoken()) == PARENS || type == BRACKETS)
    if (type == PARENS)
#ifndef _MSC_VER
      strcat(out, " function returning");
#else // _MSC_VER
      strcat_s(out, sizeof out, " function returning");
#endif // _MSC_VER
    else {
#ifndef _MSC_VER
      strcat(out, " array");
      strcat(out, token);
      strcat(out, " of");
#else // _MSC_VER
      strcat_s(out, sizeof out, " array");
      strcat_s(out, sizeof out, token);
      strcat_s(out, sizeof out, " of");
#endif // _MSC_VER
    }
}

int gettoken(void)		/* ���̃g�[�N����Ԃ� */
{
  int c, getch(void);
  void ungetch(int);
  char *p = token;

  while ((c = getch()) == ' ' || c == '\t')
    ;
  if (c == '(') {
    if ((c = getch()) == ')') {
#ifndef _MSC_VER
      strcpy(token,"()");
#else // _MSC_VER
      strcpy_s(token, sizeof token, "()");
#endif // _MSC_VER
      return tokentype = PARENS;
    } else {
      ungetch(c);
      return tokentype = '(';
    }
  } else if (c == '[') {
    for (*p++ = c; (*p++ = getch()) != ']'; )
      ;
    *p = '\0';
    return tokentype = BRACKETS;
  } else if (isalpha(c)) {
    for (*p++ = c; isalnum(c = getch()); )
      *p++ = c;
    *p = '\0';
    ungetch(c);
    return tokentype = NAME;
  } else
    return tokentype = c;
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
