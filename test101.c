#include <stdio.h>

void f(const char *a[])
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
  const char *name[] = { "Illegal month", "Jan", "Feb", "Mar" };
  char aname[][15] = { "Illegal month", "Jan", "Feb", "Mar" };

  f(name);
  g(aname);
  return 0;
}
