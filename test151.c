typedef long Align;		/* long �̋��E�ɐ��������� */

union header {
  struct {
    union header *ptr;	/* �󂫃��X�g�̏�Ȃ玟�̃u���b�N */
    unsigned size;		/* ���̃u���b�N�̑傫�� */
  } s;
  Align x;			/* �u���b�N�̐��������� */
};

typedef union header Header;

#ifndef NULL
#define NULL 0
#endif

static Header base;		/* �J�n���̋󂫃��X�g */
static Header *freep = NULL;	/* �󂫃��X�g�̐擪 */

/* mymalloc: �ėp�̋L�������ăv���O���� */
void *mymalloc(unsigned nbytes)
{
  Header *p, *prevp;
  Header *morecore(unsigned);
  unsigned nunits;

  nunits = (nbytes+sizeof(Header)-1)/sizeof(Header) + 1;
  if ((prevp = freep) == NULL) { /* �󂫃��X�g�͂܂��Ȃ� */
    base.s.ptr = freep = prevp = &base;
    base.s.size = 0;
  }
  for (p = prevp->s.ptr; ; prevp = p, p = p-> s.ptr){
    if (p->s.size >= nunits) {	/* �\���傫�� */
      if (p->s.size == nunits)	/* ���m�� */
	prevp->s.ptr = p->s.ptr;
      else {
	p->s.size -= nunits;
	p += p->s.size;
	p->s.size = nunits;
      }
      freep = prevp;
      return (void *)(p+1);
    }
    if (p == freep)		/* �󂫃��X�g�������O��ɂȂ� */
      if ((p = morecore(nunits)) == NULL)
	return NULL;		/* �c��Ȃ� */
  }
}

#define NALLOC 1024		/* �v������ŏ��̒P�ʐ� */

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
char *sbrk(int);
extern int printf(const char*, ...);
extern int rand(void);
#ifdef __cplusplus
}
#endif // __cplusplus

/* morecore: �V�X�e���ɂ����ƃ�������v������ */
/* static ���ȏ��ł� static �t���Ă��邪�G���[�Ȃ̂ŃR�����g�A�E�g */
Header *morecore(unsigned nu)
{
  char *cp;
  Header *up;
  void myfree(void *);

  if (nu < NALLOC)
    nu = NALLOC;
  cp = sbrk(nu * sizeof(Header));
  if (cp == (char *)-1)		/* �X�y�[�X���S�R�Ȃ� */
    return NULL;
  up = (Header *) cp;
  up->s.size = nu;
  myfree((void *)(up+1));
  return freep;
}

/* myfree: �u���b�N ap ���󂫃��X�g�ɓ���� */
void myfree(void *ap)
{
  Header *bp, *p;

  bp = (Header *)ap - 1;	/* �u���b�N�E�w�b�_���w�� */
  for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
    if (p >= p->s.ptr && (bp > p || bp < p->s.ptr))
      break;			/* �̈�̎n�߂��邢�͏I��̉���u���b�N */

  if (bp + bp->s.size == p->s.ptr) { /* ��� nbr �֌��� */
    bp->s.size += p->s.ptr->s.size;
    bp->s.ptr = p->s.ptr->s.ptr;
  } else
    bp->s.ptr = p->s.ptr;
  if (p + p->s.size == bp) {	/* ���� nbr �֌��� */
    p->s.size += bp->s.size;
    p->s.ptr = bp->s.ptr;
  } else
    p->s.ptr = bp;
  freep = p;
}

void test000(void)
{
  void *p[100];
  int i;

  printf("100 mymalloc call begin\n");
  for (i = 0; i < 100; ++i) {
    p[i] = mymalloc(rand()%0x100);
    if (!p[i]) {
      printf("mymalloc return 0\n");
      printf("i = %d\n", i);
      return;
    }
  }
  printf("100 mymalloc call end\n");

  printf("60 myfree call begin\n");
  for (i = 0; i < 60; ++i)
    myfree(p[i]);
  printf("60 free call end\n");

  printf("40 myfree call begin\n");
  for (i = 100; i > 60 ; --i)
    myfree(p[i-1]);
  printf("40 myfree call end\n");
}

int main(void)
{
  test000();
  return 0;
}
