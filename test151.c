typedef long Align;		/* long の境界に整合させる */

union header {
  struct {
    union header *ptr;	/* 空きリストの上なら次のブロック */
    unsigned size;		/* このブロックの大きさ */
  } s;
  Align x;			/* ブロックの整合を強制 */
};

typedef union header Header;

#ifndef NULL
#define NULL 0
#endif

static Header base;		/* 開始時の空きリスト */
static Header *freep = NULL;	/* 空きリストの先頭 */

/* mymalloc: 汎用の記憶割当てプログラム */
void *mymalloc(unsigned nbytes)
{
  Header *p, *prevp;
  Header *morecore(unsigned);
  unsigned nunits;

  nunits = (nbytes+sizeof(Header)-1)/sizeof(Header) + 1;
  if ((prevp = freep) == NULL) { /* 空きリストはまだない */
    base.s.ptr = freep = prevp = &base;
    base.s.size = 0;
  }
  for (p = prevp->s.ptr; ; prevp = p, p = p-> s.ptr){
    if (p->s.size >= nunits) {	/* 十分大きい */
      if (p->s.size == nunits)	/* 正確に */
	prevp->s.ptr = p->s.ptr;
      else {
	p->s.size -= nunits;
	p += p->s.size;
	p->s.size = nunits;
      }
      freep = prevp;
      return (void *)(p+1);
    }
    if (p == freep)		/* 空きリストをリング状につなぐ */
      if ((p = morecore(nunits)) == NULL)
	return NULL;		/* 残りなし */
  }
}

#define NALLOC 1024		/* 要求する最小の単位数 */

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
char *sbrk(int);
extern int printf(const char*, ...);
extern int rand(void);
#ifdef __cplusplus
}
#endif // __cplusplus

/* morecore: システムにもっとメモリを要求する */
/* static 教科書では static 付いているがエラーなのでコメントアウト */
Header *morecore(unsigned nu)
{
  char *cp;
  Header *up;
  void myfree(void *);

  if (nu < NALLOC)
    nu = NALLOC;
  cp = sbrk(nu * sizeof(Header));
  if (cp == (char *)-1)		/* スペースが全然ない */
    return NULL;
  up = (Header *) cp;
  up->s.size = nu;
  myfree((void *)(up+1));
  return freep;
}

/* myfree: ブロック ap を空きリストに入れる */
void myfree(void *ap)
{
  Header *bp, *p;

  bp = (Header *)ap - 1;	/* ブロック・ヘッダを指す */
  for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
    if (p >= p->s.ptr && (bp > p || bp < p->s.ptr))
      break;			/* 領域の始めあるいは終りの解放ブロック */

  if (bp + bp->s.size == p->s.ptr) { /* 上の nbr へ結合 */
    bp->s.size += p->s.ptr->s.size;
    bp->s.ptr = p->s.ptr->s.ptr;
  } else
    bp->s.ptr = p->s.ptr;
  if (p + p->s.size == bp) {	/* 下の nbr へ結合 */
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
