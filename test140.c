#include <stdio.h>

/* cat: �t�@�C���̘A��, ��1�� */
int main(int argc, char* argv[])
{
  FILE *fp;
  void filecopy(FILE *, FILE *);

  if (argc == 1)		/* �����Ȃ�; �W�����͂��R�s�[ */
    filecopy(stdin, stdout);
  else
    while (--argc > 0)
#ifndef _MSC_VER
      if ((fp = fopen(*++argv, "r")) == NULL){
#else // _MSC_VER
      if ((fopen_s(&fp, *++argv, "r"), fp) == NULL){
#endif // _MSC_VER
	printf("cat: can't open %s\n", *argv);
	return 1;
      } else {
	filecopy(fp, stdout);
	fclose(fp);
      }
  
  return 0;
}

/* filecopy: �t�@�C�� ifp ���t�@�C�� ofp �ɃR�s�[ */
void filecopy(FILE *ifp, FILE *ofp)
{
  int c;

  while ((c = getc(ifp)) != EOF)
    putc(c, ofp);
}
