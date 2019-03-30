/* shellsort: v[0]...v[n-1] ‚ð¸‡‚Éƒ\[ƒg */
void shellsort(int v[], int n)
{
  int gap, i, j, temp;

  for (gap = n/2; gap > 0; gap /= 2)
    for (i = gap; i < n; i++)
      for (j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap) {
	temp = v[j];
	v[j] = v[j+gap];
	v[j+gap] = temp;
      }
}

#include <stdio.h>

int main(void)
{
  int a[] = { -3, 0, 2, 10, 11, 3, 7, 6, 20, 13 };
  int i;

  shellsort(&a[0],sizeof a/sizeof a[0]);
  for (i = 0; i < sizeof a/sizeof a[0]; i++)
    printf("%d ",a[i]);
  printf("\n");
  return 0;
}
