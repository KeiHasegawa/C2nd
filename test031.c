unsigned long int next = 1;

/* rand: 0...32767 �͈̔͂̋[��������Ԃ� */
int rand(void)
{
  next = next * 1103515245 + 12345;
  return (unsigned int)(next/65536) % 32768;
}

/* srand: rand() �p�̎��ݒ� */
void srand(unsigned int seed)
{
  next = seed;
}

#include <stdio.h>

int main(void)
{
  srand(29);
  printf("%d\n",rand());
  printf("%d\n",rand());
  printf("%d\n",rand());
  printf("%d\n",rand());
  printf("%d\n",rand());
  return 0;
}
