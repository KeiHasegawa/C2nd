/* month_name: n ”Ô–Ú‚ÌŒŽ‚Ì–¼‘O‚ð•Ô‚· */
char* month_name(int n)
{
  static char *name[] = {
    "Illegal month",
    "January", "February", "March",
    "April", "May", "June",
    "July", "August", "September",
    "October", "November", "December"
  };

  return (n < 1 || n > 12) ? name[0] : name[n];
}

#include <stdio.h>

int main(void)
{
  int i;

  for (i = 0; i <= 12 ; ++i)
    printf("%s\n",month_name(i));
  return 0;
}
