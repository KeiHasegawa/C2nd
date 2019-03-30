#include <stdio.h>

int f(int a[], int n, int b[], int m)
{
  int i, j;
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      if (a[i] == b[j])
	goto found;
  return 0;
 found:
  return 1;
}

int main(void)
{
  int i;

  {
    int a[] = { 0, 1, 23, 27 };
    int b[] = { -1, -5, 0, 1 };
    if ( f(a,sizeof a/sizeof a[0],b,sizeof b/sizeof b[0]) )
      printf("same element found(ok)\n") ;
    else
      printf("error");
  }

  {
    int a[] = { 0, 1, 23, 27 };
    int b[] = { 3, 5, 3, 9, 7 };
    if ( !f(a,sizeof a/sizeof a[0],b,sizeof b/sizeof b[0]) )
      printf("same element not found(ok)\n") ;
    else
      printf("error");
  }

  return 0;
}
