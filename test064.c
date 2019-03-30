/* qsort: v[left]...v[right] を上昇順にソートする */
void qsort(int v[], int left, int right)
{
  int i, last;
  void swap(int v[], int i, int j);

  if (left >= right)    /* 配列が 2 より少ない要素を */
    return;             /* 含むときは何もしない */
  swap(v, left, (left + right)/2);  /* 分割要素を */
  last = left;                      /* v[0] に移動 */
  for (i = left+1; i <= right; i++)    /* 分割 */
    if (v[i] < v[left])
      swap(v, ++last, i);
  swap(v, left, last);              /* 分割要素を回復 */
  qsort(v, left, last-1);
  qsort(v, last+1, right);
}

/* swap: v[i] と v[j] を交換する */
void swap(int v[], int i, int j)
{
  int temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

#include <stdio.h>

int main(void)
{
  int i;
  int a[] = { -3, -5, 7, 1, 3, -10, 20, 25, 37, 0, 0, 3, 2, 5 };

  qsort(a,0,sizeof a/sizeof a[0]-1);

  for (i = 0; i < sizeof a/sizeof a[0]; ++i)
    printf("%d ",a[i]);
  printf("\n");
  return 0;
}
