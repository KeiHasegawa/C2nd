#include <stdio.h>
#include <stdarg.h>

/* minprintf: �ςȈ������X�g�����ŏ��� printf */
void minprintf(const char *fmt, ...)
{
  va_list ap;	/* �e���Ȃ����������X�Ɏw�� */
  const char *p, *sval;
  int ival;
  double dval;

  va_start(ap, fmt);	/* ap ���ŏ��̖��Ȃ��������w���悤�ɂ��� */
  for (p = fmt; *p; p++) {
    if (*p != '%') {
      putchar(*p);
      continue;
    }
    switch (*++p) {
    case 'd':
      ival = va_arg(ap, int);
      printf("%d", ival);
      break;
    case 'f':
      dval = va_arg(ap, double);
      printf("%f", dval);
      break;
    case 's':
      for (sval = va_arg(ap, char *); *sval; sval++)
	putchar(*sval);
      break;
    default:
      putchar(*p);
      break;
    }
  }
  va_end(ap);	/* �I������Ƃ��N���[���A�b�v */
}

int main(void)
{
  minprintf("%d\n",1234);
  minprintf("%f\n",567.89);
  minprintf("%s\n","hasegawa");
  minprintf("%f %d\t%s\n",901.23,456,"kei");
  return 0;
}
