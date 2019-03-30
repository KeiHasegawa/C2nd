union u_tag {
  int ival;
  float fval;
  char* sval;
};

enum type { INT, FLOAT, STRING };

#include <stdio.h>

void f(enum type utype, union u_tag u)
{
  if (utype == INT)
    printf("%d\n", u.ival);
  else if (utype == FLOAT)
    printf("%f\n", u.fval);
  else if (utype == STRING)
    printf("%s\n", u.sval);
  else
    printf("bad type %d in utype\n", utype);
}

int main(void)
{
  union u_tag u;
  enum type t;

  t = INT;
  u.ival = 12345678;
  f(t,u);

  t = FLOAT;
  u.fval = 3.14159;
  f(t,u);

  t = STRING;
  u.sval = "hasegawa";
  f(t,u);

  return 0;
}
