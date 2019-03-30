#include <ctype.h>

/* atof: •¶Žš—ñ s ‚ð double ‚É•ÏŠ·‚·‚é */
double atof(char s[])
{
  double val, power;
  int i, sign;

  for (i=0; isspace(s[i]); i++)    /* ‹ó”’‚ð”ò‚Î‚· */
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  for (val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');
  if ( s[i] == '.')
    i++;
  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val +(s[i] - '0');
    power *= 10.0;
  }
  return sign * val / power;
}

#include <stdio.h>

int main(void)
{
  {
    char a[] = "123.456";
    printf("%lf\n",atof(a));
  }
  {
    char a[] = "-789.012";
    printf("%lf\n",atof(a));
  }
  return 0;
}
