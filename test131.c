#include <stdio.h>

#define NSYM 10

enum { INT, FLOAT, STRING };

struct {
  char *name;
  int flags;
  int utype;
  union {
    int ival;
    float fval;
    char *sval;
  } u;
} symtab[NSYM];

void f(void)
{
  int i;

  for (i = 0; i < NSYM; i++)
    if (symtab[i].name){
      printf("%s\n",symtab[i].name);
      printf("%d\n",symtab[i].flags);
      switch (symtab[i].utype){
      case INT:
	printf("%d\n", symtab[i].u.ival);
	break;
      case FLOAT:
	printf("%f\n", symtab[i].u.fval);
	break;
      case STRING:
	printf("%c ", *symtab[i].u.sval);
	printf("%c ", symtab[i].u.sval[0]);
	printf("%s\n", symtab[i].u.sval);
	break;
      }
    }
}

int main(void)
{
  symtab[3].name = "i";
  symtab[3].flags = 123;
  symtab[3].utype = INT;
  symtab[3].u.ival = 4567;

  symtab[7].name = "f";
  symtab[7].flags = 456;
  symtab[7].utype = FLOAT;
  symtab[7].u.fval = 98.76;

  symtab[4].name = "pc";
  symtab[4].flags = 789;
  symtab[4].utype = STRING;
  symtab[4].u.sval = "program";

  f();

  return 0;
}
