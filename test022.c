#include <stdio.h>

int main(void)
{
#define MAXLINE 1000
  char esc = '\\';
  int i = 0;
  int limit = MAXLINE+1;
  float eps = 1.0e-5;
  printf("esc = %c i = %d limit = %d eps = %E\n",
	 esc, i, limit, eps);
  return 0;
}
