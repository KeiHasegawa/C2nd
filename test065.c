#include <stdio.h>

#define forever for (;;)   /* �������[�v */

int main(void)
{
  int i = 0;
  forever {
    if ( ++i == 10 )
      break;
  }
  printf("i = %d\n",i);
  return 0;
}
