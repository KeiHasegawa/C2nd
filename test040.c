/* binsearch: v[0] <= v[1] <= ... <= v[n-1] ‚Ì’†‚Å x ‚ğ’T‚¹ */
int binsearch(int x, int v[], int n)
{
  int low, high, mid;

  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low+high) / 2;
    if (x < v[mid])
      high = mid - 1;
    else if (x > v[mid])
      low = mid + 1;
    else
      return mid;
  }
  return -1;
}

#include <stdio.h>

int main(void)
{
  int i, a[100], pos;

  for (i = 0; i < sizeof a/sizeof a[0]; i++ )
    a[i] = i;

  pos = binsearch(60,&a[0],sizeof a/sizeof a[0]);
  printf("pos = %d\n",pos);
  a[pos] = 0;
  pos = binsearch(60,&a[0],sizeof a/sizeof a[0]);
  printf("pos = %d\n",pos);
  return 0;
}
