/* strcmp: s<t �Ȃ� <0, s==t �Ȃ� 0, s>t �Ȃ� >0 ��Ԃ� */
int strcmp(const char* s, const char *t)
{
  for ( ; *s == *t ; s++, t++ )
    if (*s == '\0')
      return 0;
  return *s - *t;
}

#include <stdio.h>

int main(void)
{
  {
    const char* a = "hasegawa";
    char b[] = "hase";
    printf("strcmp(%s,%s) = %d\n",*&a,b,strcmp(a,b));
  }

  {
    const char* a = "hasegawa";
    char b[] = "  hasegawa";
    printf("strcmp(%s,%s) = %d\n",*&a,&b[2],strcmp(a,b+2));
  }

  {
    const char* a = "hasegaaw";
    const char* b = "hasegawa";
    printf("strcmp(%s,%s) = %d\n",*&a,&b[0],strcmp(a,b+0));
  }
  return 0;
}
