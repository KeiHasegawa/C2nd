#include <stdio.h>
#include "calc.h"
#define MAXVAL 100 /* val �X�^�b�N�̍ő�̐[�� */

int sp = 0;            /* �X�^�b�N�E�|�C���^ */
double val[MAXVAL];    /* �l�̃X�^�b�N */

/* push: f ���X�^�b�N�Ƀv�b�V������ */
void push(double f)
{
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, can't push %g\n",f);
}

/* pop: �X�^�b�N�����ԏ�̒l���|�b�v���ĕԂ� */
double pop(void)
{
  if (sp > 0)
    return val[--sp];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

