#define BUFSIZE 100

char buf[BUFSIZE];    /* ungetch �p�̃o�b�t�@ */
int bufp = 0;         /* buf ���̎��̋󂫈ʒu */

#ifdef __cplusplus
extern "C" {
#ifdef _MSC_VER
extern int printf(const char* const, ...);
#else // _MSC_VER
extern int printf(const char*, ...);
#endif // _MSC_VER
extern int getchar();
}
#else // __cplusplus
#ifdef _MSCVER
extern int printf(const char* const, ...);
#else // _MSC_VER
extern int printf(const char*, ...);
#endif // _MSC_VER
extern int getchar();
#endif // __cplusplus

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
