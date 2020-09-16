#define BUFSIZE 100

char buf[BUFSIZE];    /* ungetch �p�̃o�b�t�@ */
int bufp = 0;         /* buf ���̎��̋󂫈ʒu */

#if 0  // change 2020.09.16 09:54
#ifdef __cplusplus
extern "C" {
#ifdef _MSC_VER
inline int printf(const char* const, ...);
#else // _MSC_VER
extern int printf(const char*, ...);
#endif // _MSC_VER
extern int getchar();
}
#else // __cplusplus
#ifdef _MSC_VER
extern int printf(const char* const, ...);
#else // _MSC_VER
extern int printf(const char*, ...);
#endif // _MSC_VER
extern int getchar();
#endif // __cplusplus
#else  // change 2020.09.16 09:54
#include <stdio.h>
#endif  // change 2020.09.16 09:54

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
