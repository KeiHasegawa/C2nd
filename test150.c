#include <stdio.h>
#include <string.h>
#include "syscalls.h"
#include <fcntl.h>		/* �ǂݏ����̃t���O */
#include <sys/types.h>	/* typdef �Q */
#include <sys/stat.h> 	/* stat ���Ԃ��\���� */

#ifndef _MSC_VER
#include <dirent.h>
#else // _MSC_VER
typedef unsigned int uint32_t;

typedef unsigned int __uint32_t;

struct dirent
{
  uint32_t __d_version;
  ino_t d_ino;
  unsigned char d_type;
  unsigned char __d_unused1[3];
  __uint32_t __d_internal1;
  char d_name[255 + 1];
};

typedef int __int32_t;

typedef struct __DIR
{

  unsigned long __d_cookie;
  struct dirent *__d_dirent;
  char *__d_dirname;
  __int32_t __d_position;
  int __d_fd;
  uintptr_t __d_internal;
  void *__handle;
  void *__fh;
  unsigned __flags;
} DIR;

DIR* opendir(const char*);
struct dirent* readdir(DIR*);
void closedir(DIR*);
#endif // _MSC_VER
#include <assert.h>

void fsize(char *);

/* �t�@�C���̑傫�����󎚂��� */
int main(int argc, char* argv[])
{
  if (argc == 1)		/* �W���l: ���p�f�B���N�g�� */
    fsize(".");
  else
    while (--argc > 0)
      fsize(*++argv);
  return 0;
}

void dirwalk(char *, void (*fcn)(char *));

/* fsize: �t�@�C�� "name" �̃T�C�Y���󎚂��� */
void fsize(char *name)
{
  struct stat stbuf;
  if (stat(name, (struct stat*)&stbuf) == -1) {
    fprintf(stderr, "fsize: can't access %s\n", name);
    return;
  }
  if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
    dirwalk(name, fsize);

  printf("%d %s\n", (int)stbuf.st_size, name);
}

/* dirwalk: dir ���̂��ׂẴt�@�C���� fcn ��K�p���� */
void dirwalk(char *dir, void (*fcn)(char *))
{
  char name[FILENAME_MAX];
  struct dirent *dp;
  DIR *dfd;

  if ((dfd = opendir(dir)) == NULL) {
    fprintf(stderr, "dirwalk: can't open %s\n", dir);
    return;
  }
  while ((dp = readdir(dfd)) != NULL) {
    if (strcmp(dp->d_name, ".") == 0
	|| strcmp(dp->d_name, "..") == 0)
      continue;			/* skip self and parent */
    if (strlen(dir)+strlen(dp->d_name)+2 > sizeof(name))
      fprintf(stderr, "dirwalk: name %s/%s too long\n",
	      dir, dp->d_name);
    else {
      sprintf(name, "%s/%s", dir, dp->d_name);
      (*fcn)(name);
    }
  }
  closedir(dfd);
}
