#include <stdio.h>

/* �R�}���h�s�̈������G�R�[����; ��2�� */
int main(int argc, char *argv[])
{
  while (--argc > 0)
    printf("%s%s", *++argv, (argc > 1) ? " " : "");
  printf("\n");
  return 0;
}
