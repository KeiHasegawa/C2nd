#include <stdio.h>

/* �R�}���h�s�̈������G�R�[����; ��3�� */
int main(int argc, char *argv[])
{
  while (--argc > 0)
    printf((argc > 1) ? "%s " : "%s", *++argv);
  printf("\n");
  return 0;
}
