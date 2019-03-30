#include <stdio.h>

struct nlist {		/* �e�[�u���̍��� */
  struct nlist *next;		/* �`�F�C���̒��̎��̍��� */
  char *name;			/* ��`���ꂽ���O */
  char *defn;			/* �u���e�L�X�g */
};

#define HASHSIZE 101

static struct nlist *hashtab[HASHSIZE];	/* �|�C���^�̃e�[�u�� */

/* hash: ������ s �ɑ΂��n�b�V���̒l�����߂� */
unsigned hash(char *s)
{
  unsigned hashval;

  for (hashval = 0; *s != '\0'; s++)
    hashval = *s + 31 * hashval;
  return hashval % HASHSIZE;
}

#include <string.h>

/* lookup: hashtab �̒��� s ��T�� */
struct nlist *lookup(char *s)
{
  struct nlist *np;

  for (np = hashtab[hash(s)]; np != NULL; np = np->next)
    if (strcmp(s, np->name) == 0)
      return np;		/* �������� */
  return NULL;		/* ������Ȃ� */
}

struct nlist* lookup(char *);

#include <stdlib.h>

#ifdef _MSC_VER
#define strdup _strdup
#endif // _MSC_VER

/* install: hashtab �̒��� (name, defn) ��u�� */
struct nlist *install(char *name, char *defn)
{
  struct nlist* np;
  unsigned hashval;

  if ((np = lookup(name)) == NULL) { /* ������Ȃ����� */
    np = (struct nlist *) malloc(sizeof(*np));
    if (np == NULL || (np->name = strdup(name)) == NULL)
      return NULL;
    hashval = hash(name);
    np->next = hashtab[hashval];
    hashtab[hashval] = np;
  } else			/* ���łɂ��� */
    free((void *) np->defn);	/* �ȑO�� defn ��������� */
  if ((np->defn = strdup(defn)) == NULL)
    return NULL;
  return np;
}

int main(void)
{
  {
    int i;
    char buf[2][10];

    for (i = 0; i < 2 * HASHSIZE; i++){
#ifndef _MSC_VER
      sprintf(buf[0],"%d",i);
      sprintf(buf[1],"%x",i);
#else // _MSC_VER
      sprintf_s(buf[0], sizeof buf[0], "%d", i);
      sprintf_s(buf[1], sizeof buf[1], "%x", i);
#endif // _MSC_VER
      install(buf[0],buf[1]);
    }
  }

  {
    int i;
    char buf[2][10];
    struct nlist *np;

    for (i = 0; i < 2 * HASHSIZE; i++){
#ifndef _MSC_VER
      sprintf(buf[0],"%d",i);
      sprintf(buf[1],"%x",i);
#else // _MSC_VER
      sprintf_s(buf[0], sizeof buf[0], "%d", i);
      sprintf_s(buf[1], sizeof buf[1], "%x", i);
#endif // _MSC_VER
      if ( np = lookup(buf[0]) ){
	if ( strcmp(np->defn,buf[1]) )
	  printf("error %x\n",i);
	else
	  printf("ok %x\n",i);
      }
      else
	printf("error %d\n",i);
    }
  }

  return 0;
}
