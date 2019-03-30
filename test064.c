/* qsort: v[left]...v[right] ���㏸���Ƀ\�[�g���� */
void qsort(int v[], int left, int right)
{
  int i, last;
  void swap(int v[], int i, int j);

  if (left >= right)    /* �z�� 2 ��菭�Ȃ��v�f�� */
    return;             /* �܂ނƂ��͉������Ȃ� */
  swap(v, left, (left + right)/2);  /* �����v�f�� */
  last = left;                      /* v[0] �Ɉړ� */
  for (i = left+1; i <= right; i++)    /* ���� */
    if (v[i] < v[left])
      swap(v, ++last, i);
  swap(v, left, last);              /* �����v�f���� */
  qsort(v, left, last-1);
  qsort(v, last+1, right);
}

/* swap: v[i] �� v[j] ���������� */
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
