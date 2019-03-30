#include <string.h>

/* reverse: •¶š—ñ s ‚ğ‚»‚ÌˆÊ’u‚Å‹t‡‚É‚·‚é */
void reverse(char s[])
{
  int c, i, j;

  for (i = 0, j = strlen(s)-1; i < j; i++, j--)
    c = s[i], s[i] = s[j], s[j] = c;
}

/* itoa: n ‚ğ s ‚Ì’†‚Ì•¶š‚É•ÏŠ·‚·‚é */
void itoa(int n, char s[])
{
  int i, sign;

  if ((sign = n) < 0)  /* •„†‚ğ‹L˜^‚·‚é */
    n = -n;            /* •„†‚ğ³‚É‚·‚é */
  i = 0;
  do {     /* ”š‚ğ‹t‡‚É¶¬‚·‚é */
    s[i++] = n % 10 + '0';    /* Ÿ‚ÌŒ…‚ğ‚Æ‚Á‚Ä‚­‚é */
  } while ((n /= 10) > 0);    /* ‚»‚ê‚ğíœ‚·‚é */

  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

#include <stdio.h>

int main(void)
{
  char s[10];
  itoa(45678,s);
  printf("%s\n",s);
  itoa(-98765,s);
  printf("%s\n",s);
  itoa(+1234,s);
  printf("%s\n",s);
  return 0;
}

