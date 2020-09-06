#define BUFSIZE 100

char buf[BUFSIZE];    /* ungetch 用のバッファ */
int bufp = 0;         /* buf 中の次の空き位置 */

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
