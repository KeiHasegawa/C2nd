#define NULL		0
#define EOF		(-1)
#define BUFSIZ	10
#define MY_OPEN_MAX	20	/* 一時に開けるファイルの最大数 */

typedef struct _iobuf {
  int cnt;			/* 残っている文字数 */
  char *ptr;			/* 次の文字の位置 */
  char *base;			/* バッファの位置 */
  int flag;			/* ファイルのアクセスモード */
  int fd;			/* ファイル記述子 */
} FILE;

#define _iob _my_iob
#define fopen my_fopen
#define fflush my_fflush

extern FILE _iob[MY_OPEN_MAX];

#define stdin		(&_iob[0])
#define stdout	(&_iob[1])
#define stderr	(&_iob[2])

enum _flags {
  _READ	= 01,	/* 読出し用のファイルのオープン */
  _WRITE	= 02,	/* 書込み用のファイルのオープン */
  _UNBUF	= 04,	/* バッファされていないファイル */
  _EOF		= 010,	/* このファイルで EOF に達した */
  _ERR		= 020,	/* このファイルでエラー発生 */
};

int _fillbuf(FILE *);
int _flushbuf(int, FILE *);

#define feof(p)	(((p)->flag & _EOF) != 0)
#define ferror(p)	(((p)->flag & _ERR) != 0)
#define fileno(p)	(((p)->fd)

#define getc(p)	(--(p)->cnt >= 0 \
			? (unsigned char) *(p)->ptr++ : _fillbuf(p))
#define putc(x,p)	(--(p)->cnt >= 0 \
			? *(p)->ptr++ = (x) : _flushbuf((x),p))
#define getchar()	getc(stdin)
#define putchar(x)	putc((x), stdout)

#ifdef _MSC_VER
#include <io.h>
#include <sys/stat.h>
#define read _read
#define write _write
#define lseek _lseek
#endif // _MSC_VER
#include <fcntl.h>
#define PERMS 0666		/* 所有者, グループ, 他人に対して RW */

#ifdef __cplusplus
extern "C" {
#endif
#ifndef _MSC_VER
extern long long lseek(int, long long, int);
#endif // _MSC_VER
extern void* malloc(unsigned int);
extern int read(int, void*, unsigned int);
extern int write(int, const void*, unsigned int);
extern void exit(int);
extern int atoi(const char*);
#ifdef __cplusplus
}
#endif

/* fopen: ファイルを開いて, ファイルポインタを返す */
FILE* fopen(char *name, char *mode)
{
  int fd;
  FILE *fp;

  if (*mode != 'r' && *mode != 'w' && *mode != 'a')
    return NULL;

  for (fp = _iob; fp < _iob + MY_OPEN_MAX; fp++)
    if ((fp->flag & ( _READ | _WRITE)) == 0)
      break;			/* found free slot */
  if (fp >= _iob + MY_OPEN_MAX)
    return NULL;

  if (*mode == 'w')
#ifndef _MSC_VER
    fd = creat(name, PERMS);
#else // _MSC_VER
  _sopen_s(&fd, name, _O_CREAT, _SH_DENYNO, _S_IREAD|_S_IWRITE);
#endif // _MSC_VER
  else if (*mode == 'a') {
#ifndef _MSC_VER
    if ((fd = open(name, O_WRONLY, 0)) == -1) {
      fd = creat(name, PERMS);
      lseek(fd, 0L, 2);
    }
#else // _MSC_VER
    if (_sopen_s(&fd, name, _O_WRONLY, _SH_DENYNO, 0), fd == -1) {
      _sopen_s(&fd, name, _O_CREAT, _SH_DENYNO, _S_IREAD|_S_IWRITE);
      lseek(fd, 0L, 2);
    }
#endif // _MSC_VER
  }
  else
#ifndef _MSC_VER
    fd = open(name, O_RDONLY, 0);
#else // _MSC_VER
    _sopen_s(&fd, name, _O_RDONLY, _SH_DENYNO, 0);
#endif // _MSC_VER
  if (fd == -1)			/* 名前がアクセス不能 */
    return NULL;
  fp->fd = fd;
  fp->cnt = 0;
  fp->base = NULL;
  fp->flag = (*mode == 'r') ? _READ : _WRITE;
  return fp;
}

/* _fillbuf: 入力バッファを割り当てて, 詰める */
int _fillbuf(FILE *fp)
{
  int bufsize;

  if ((fp->flag&(_READ|_EOF|_ERR)) != _READ)
    return EOF;
  bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
  if (fp->base == NULL)	/* バッファがまだない */
    if ((fp->base = (char *) malloc(bufsize)) == NULL)
      return EOF;		/* バッファがとれない */
  fp->ptr = fp->base;
  fp->cnt = read(fp->fd, fp->ptr, bufsize);
  if (--fp->cnt < 0) {
    if (fp->cnt == -1)
      fp->flag |= _EOF;
    else
      fp->flag |= _ERR;
    fp->cnt = 0;
    return EOF;
  }
  return (unsigned char) *fp->ptr++;
}

int _flushbuf(int c, FILE *fp)
{
  if ((fp->flag&(_WRITE|_EOF|_ERR)) != _WRITE)
    return EOF;
  if (fp->flag & _UNBUF){
    char t = c;
    if (write(fp->fd, &t, 1) != 1)
      return EOF;
    else
      return c;
  }

  if (fp->base == NULL) {	/* バッファがまだない */
    if ((fp->base = (char *) malloc(BUFSIZ)) == NULL)
      return EOF;		/* バッファがとれない */
    fp->ptr = fp->base;
    fp->cnt = BUFSIZ;
  }

  if (fp->cnt < 0) {
    if (write(fp->fd, fp->base, BUFSIZ) != BUFSIZ)
      return EOF;
    fp->cnt = BUFSIZ;
    fp->ptr = fp->base;
  }

  --fp->cnt;
  return *fp->ptr++ = c;
}

int fflush(FILE* fp)
{
  int bufsize;

  if (fp == NULL){
    for ( fp = &_iob[0] ; fp != &_iob[MY_OPEN_MAX] ; ++fp )
      if (fflush(fp) < 0)
	return EOF;
  }

  if ((fp->flag&(_WRITE|_EOF|_ERR)) != _WRITE)
    return 0;
  if (fp->base == NULL)
    return 0;
  if (fp->cnt < 0)
    return 0;

  bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;

  if (write(fp->fd, fp->base, bufsize - fp->cnt) != fp->cnt)
    return EOF;
  else
    return 0;
}

FILE _iob[MY_OPEN_MAX] = {	/* stdin, stdout, stderr: */
  { 0, (char *) 0, (char *) 0, _READ, 0 },
  { 0, (char *) 0, (char *) 0, _WRITE, 1 },
  { 0, (char *) 0, (char *) 0, _WRITE | _UNBUF, 2 }
};

void test000(char *fn)
{
  FILE* fp;
  int c;

  if ((fp = fopen(fn,"r")) == NULL)
    exit(2);

  while ((c = getc(fp)) != EOF)
    putchar(c);

  fflush(stdout);
}

void test001(void)
{
  int c;

  while ((c = getchar()) != EOF)
    putchar(c);

  fflush(stdout);
}

void test002(void)
{
  const char *p = "stderr output test\n";

  while (*p)
    putc(*p++,stderr);
}

int main(int argc, char *argv[])
{
  switch (atoi(argv[1])) {
  case 0: test000(argv[2]); break;
  case 1: test001(); break;
  case 2: test002(); break;
  }
  return 0;
}
