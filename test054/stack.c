#include <stdio.h>
#include "calc.h"
#define MAXVAL 100 /* val スタックの最大の深さ */

int sp = 0;            /* スタック・ポインタ */
double val[MAXVAL];    /* 値のスタック */

/* push: f をスタックにプッシュする */
void push(double f)
{
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, can't push %g\n",f);
}

/* pop: スタックから一番上の値をポップして返す */
double pop(void)
{
  if (sp > 0)
    return val[--sp];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

