#include <stdio.h>
#include <stdlib.h>

/* cat: �t�@�C���̘A��, ��2�� */
int main(int argc, char *argv[])
{
  FILE* fp;
  void filecopy(FILE *, FILE *);
  char *prog = argv[0];		/* �v���O������. �G���[�\���Ŏg�� */

  if (argc == 1)		/* �����Ȃ�; �W�����͂��R�s�[ */
    filecopy(stdin, stdout);
  else
    while (--argc > 0)
#ifndef _MSC_VER
      if ((fp = fopen(*++argv, "r")) == NULL) {
#else // _MSC_VER
      if (fopen_s(&fp, *++argv, "r"), fp == NULL) {
#endif // _MSC_VER
	fprintf(stderr, "%s: can't open %s\n",
		prog, *argv);
	exit(1);
      } else {
	filecopy(fp, stdout);
	fclose(fp);
      }
  if (ferror(stdout)) {
    fprintf(stderr, "%s: error writing stdout\n", prog);
    exit(2);
  }
  exit(0);
}

/* filecopy: �t�@�C�� ifp ���t�@�C�� ofp �ɃR�s�[ */
void filecopy(FILE *ifp, FILE *ofp)
{
  int c;

  while ((c = getc(ifp)) != EOF)
    putc(c, ofp);
}
