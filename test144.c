#include "syscalls.h"

#ifdef _MSC_VER
#define read _read
#define write _write
#endif // _MSC_VER

int main()	/* ���͂��o�͂ɃR�s�[���� */
{
  char buf[BUFSIZ];
  int n;

  while ((n = read(0, buf, BUFSIZ)) > 0)
    write(1, buf, n);
  return 0;
}
