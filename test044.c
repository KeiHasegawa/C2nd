#include <string.h>

/* reverse: •¶š—ñ s ‚ğ‚»‚ÌˆÊ’u‚Å‹t‡‚É‚·‚é */
void reverse(char s[])
{
  int c, i, j;

  for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

#include <stdio.h>

int main(void)
{
  char a[] = "kei hasegawa";
  printf("reverse(\"%s\") = ",&a[0]);
  reverse(a);
  printf("%s\n",a);
  return 0;
}
