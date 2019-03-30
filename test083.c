#define ALLOCSIZE 10000		/* �g�p�\�ȏꏊ�̑傫�� */
static char allocbuf[ALLOCSIZE];     /* alloc �̂��߂̋L���ꏊ */
static char *allocp = allocbuf;	/* ���̋󂫈ʒu */

char *alloc(int n)		/* n �����ւ̃|�C���^��Ԃ� */
{
  if (allocbuf + ALLOCSIZE - allocp >= n) { /* ���肫�� */
    allocp += n;
    return allocp - n;    /* �Â� p */
  } else    /* �\���ȋ󂫂��Ȃ��Ƃ� */
    return 0;
}

void afree(char *p)    /* p �ɂ���Ďw�����̈��������� */
{
  if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
    allocp = p;
}

#include <stdio.h>

void f(int n)
{
  char* p = alloc(n);
  if (p == &allocbuf[0])
    printf("ok\n");
  else
    printf("error\n");

  if (p)
    afree(p);
}

void g(void)
{
  int i;
  char* p[ALLOCSIZE/10];

  for (i = 0; i < ALLOCSIZE/10; i++)
    p[i] = alloc(ALLOCSIZE/10);

  for (i = ALLOCSIZE/10; i > 0; --i)
    afree(p[i-1]);

  f(ALLOCSIZE);
  f(ALLOCSIZE-1);
  f(ALLOCSIZE-5);
  f(ALLOCSIZE);
}

int main(void)
{
  f(ALLOCSIZE);
  f(ALLOCSIZE-1);
  f(ALLOCSIZE-5);
  f(ALLOCSIZE);

  g();

  return 0;
}
