#include <stdio.h>

/* �R�}���h�s�̈������G�R�[����; ��1�� */
int main(int argc, char *argv[])
{
  int i;

  for (i = 1; i < argc; i++)
    printf("%s%s", argv[i], (i  < argc - 1) ? " " : "");
  printf("\n");
  return 0;
}
