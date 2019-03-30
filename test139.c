#include <stdio.h>

#ifdef _MSC_VER
#define sscanf sscanf_s
#endif // _MSC_VER

/* my_getline: s に行を入れ, 長さを返す */
int my_getline(char s[], int lim)
{
  int c, i;
  for (i=0; i<lim-1 && (c=getchar())!= EOF && c!='\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

int main(void)
{
  char line[256];
  int day, month, year;
  char monthname[20];

  while (my_getline(line, sizeof(line)) > 0) {
#ifndef _MSC_VER
    if (sscanf(line, "%d %s %d", &day, monthname, &year) == 3)
#else // _MSC_VER
    if (sscanf(line, "%d %s %d", &day, monthname, sizeof monthname, &year) == 3)
#endif // _MSC_VER
      printf("valid: %s\n", line); /* 25 Dec 1988 の形 */
    else if (sscanf(line, "%d/%d/%d", &month, &day, &year) == 3)
      printf("valid: %s\n", line); /* mm/dd/yy の形 */
    else
      printf("invalid: %s\n", line); /* 誤った形 */
  }

  return 0;
}
