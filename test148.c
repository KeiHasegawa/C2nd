#include <fcntl.h>
#include <stdio.h>
#include "syscalls.h"

#ifdef _MSC_VER
#define lseek _lseek
#define read _read
#endif // _MSC_VER

/* get: 位置 ps から n バイト読む */
int get(int fd, long pos, char* buf, int n)
{
  if (lseek(fd, pos, 0) >= 0)	/* pos へ移る */
    return read(fd, buf, n);
  else
    return -1;
}

#include <stdlib.h>

int main(int argc, char *argv[])
{
  char buf[256];
  int fd, n;

  if (argc != 2){
    fprintf(stderr, "Usage : %s file\n", argv[0]);
    exit(1);
  }

#ifndef _MSC_VER
  if ((fd = open(argv[1], O_RDONLY, 0)) == -1){
#else // _MSC_VER
  if (_sopen_s(&fd, argv[1], _O_RDONLY, _SH_DENYRW, 0), fd == -1){
#endif // _MSC_VER  
    fprintf(stderr, "error: can't open %s\n", argv[1]);
    exit(2);
  }

  n = get(fd, 200, buf, 30);
  printf("n = %d\n", n);
  buf[n] = '\0';
  printf("%s\n", buf);

  return 0;
}
