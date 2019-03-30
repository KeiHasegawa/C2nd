#include <stdio.h>

void f(int a, int b)
{
  int z;
  z = ( a > b ) ? a : b; 	/* z = max(a,b) */
  printf("z = %d\n",z);
}

void g(float f, int n)
{
  printf("%f\n",( n > 0 ) ? f : n);
}

void h(int a[], int n)
{
  int i;

  for (i=0; i < n; i++)
    printf("%6d%c",a[i], (i%10==9 || i==n-1) ? '\n' : ' ');
}

void i(int n)
{
  printf("You have %d item%s.\n", n, n==1 ? "" : "s");
}

int main(void)
{
  f(10,20);
  g(3.14,2);
  g(3.14,-3);
  {
    int a[23], i;
    for (i = 0; i < 23; ++i) {
      a[i] = 10 - i + 3*i;
    }
    h(a,sizeof a/sizeof a[0]);
  }

  i(1);
  i(2);
  return 0;
}
