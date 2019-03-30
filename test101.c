#include <stdio.h>

void f(char *a[])
{
  int i;

  for (i = 0; i < 3; ++i)
    printf("%s\n",a[i]);
}

void g(char (*a)[15])
{
  int i;

  for (i = 0; i < 3; ++i)
    printf("%s\n",a[i]);
}

int main(void)
{
  char *name[] = { "Illegal month", "Jan", "Feb", "Mar" };
  char aname[][15] = { "Illegal month", "Jan", "Feb", "Mar" };

  f(name);
  g(aname);
  return 0;
}
