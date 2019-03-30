#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };

int gettoken(void);
int tokentype;			/* �Ō�̃g�[�N���̌^ */
char token[MAXTOKEN]; 		/* �Ō�̃g�[�N�������� */
char out[1000];			/* �o�͕����� */

/* undcl: ���Ƃ΂ɂ��L�q��錾�ɕϊ����� */
int main()
{
  int type;
  char temp[MAXTOKEN];

  while (gettoken() != EOF) {
#ifndef _MSC_VER
    strcpy(out, token);
#else // _MSC_VER
    strcpy_s(out, sizeof out, token);
#endif // _MSC_VER
    while ((type = gettoken()) != '\n')
      if (type == PARENS || type == BRACKETS) {
#ifndef _MSC_VER
	strcat(out, token);
#else // _MSC_VER
	strcat_s(out, sizeof out, token);
#endif // _MSC_VER
      }
      else if (type == '*') {
#ifndef	_MSC_VER
	sprintf(temp, "(*%s)", out);
	strcpy(out, temp);
#else // _MSC_VER
	sprintf_s(temp, sizeof temp, "(*%s)", out);
	strcpy_s(out, sizeof out, temp);
#endif // _MSC_VER
      } else if (type == NAME){
#ifndef	_MSC_VER
	sprintf(temp, "%s %s", token, out);
	strcpy(out, temp);
#else // _MSC_VER
	sprintf_s(temp, sizeof temp, "%s %s", token, out);
	strcpy_s(out, sizeof out, temp);
#endif // _MSC_VER
      } else
	printf("invalid input at %s\n", token);
    printf("%s\n", out);
  }
  return 0;
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
#ifndef	_MSC_VER
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
