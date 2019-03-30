/* strcmp: s<t �Ȃ� <0, s==t �Ȃ� 0, s>t �Ȃ� >0 ��Ԃ� */
int strcmp(char* s, char *t)
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
    char* a = "hasegawa";
    char b[] = "hase";
    printf("strcmp(%s,%s) = %d\n",*&a,b,strcmp(a,b));
  }

  {
    char* a = "hasegawa";
    char b[] = "  hasegawa";
    printf("strcmp(%s,%s) = %d\n",*&a,&b[2],strcmp(a,b+2));
  }

  {
    char* a = "hasegaaw";
    char* b = "hasegawa";
    printf("strcmp(%s,%s) = %d\n",*&a,&b[0],strcmp(a,b+0));
  }
  return 0;
}
