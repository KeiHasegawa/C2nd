#define paste(front, back) front ## back

#include <stdio.h>

int main(void)
{
  const char *keihasegawa = "Kei Hasegawa";
  printf("%s\n",paste(kei,hasegawa));
  return 0;
}
