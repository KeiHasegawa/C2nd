#include <stdio.h>

void f(void)
{
  const char *pmessage;
  pmessage = "now is the time";
  printf("%s\n",pmessage);
}

void g(void)
{
  char amessage[] = "now is the time";
  const char *pmessage = "now is the time";

  printf("%s %s\n", &amessage[0], pmessage);

  amessage[0] = 'N';
  ++pmessage;

  printf("%s %s\n", amessage, pmessage);
}

int main(void)
{
  const char* p = "I am a string";

  printf("%s\n",p);
  printf("hello, world\n");
  f();

  return 0;
}
