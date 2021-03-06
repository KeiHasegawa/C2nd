#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "syscalls.h"
#define PERMS 0666		/* 所有者, グループ, 他人に対して RW */

void error(const char *,...);

#ifdef _MSC_VER
#include <sys/stat.h>
#define read _read
#define write _write
#endif // _MSC_VER

/* cp: f1 を f2 にコピー */
int main(int argc, char *argv[])
{
  int f1, f2, n;
  char buf[BUFSIZ];

  if (argc != 3)
    error("Usage: cp from to");
#ifndef _MSC_VER
  if ((f1 = open(argv[1], O_RDONLY, 0)) == -1)
#else // _MSC_VER
  if (_sopen_s(&f1, argv[1], _O_RDONLY, _SH_DENYRW, 0), f1 == -1)
#endif // _MSC_VER
    error("cp: can't open %s", argv[1]);
#ifndef _MSC_VER
  if ((f2 = creat(argv[2], PERMS)) == -1)
#else // _MSC_VER
  if (_sopen_s(&f2, argv[2], _O_CREAT|_O_WRONLY, _SH_DENYRW, _S_IREAD|_S_IWRITE), f2 == -1)
#endif // _MSC_VER
    error("cp: can't create %s, mode %03o",
	  argv[2], PERMS);
  while ((n = read(f1, buf, BUFSIZ)) > 0)
    if (write(f2, buf, n) != n)
      error("cp: write error on file %s", argv[2]);
  return 0;
}

#include <stdarg.h>

/* error: エラー・メッセージを印字して死ぬ */
void error(const char *fmt, ...)
{
  va_list args;

  va_start(args, fmt);
  fprintf(stderr, "error: ");
  vfprintf(stderr, fmt, args);
  fprintf(stderr, "\n");
  va_end(args);
  exit(1);
}
