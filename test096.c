#include <stdio.h>

static char daytab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

/* day_of_year: Œ‚Æ“ú‚©‚ç”N“à‚Ì’ÊZ“ú‚ğ‹‚ß‚é */
int day_of_year(int year, int month, int day)
{
  int i, leap;

  leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
  for (i = 1; i < month; i++)
    day += daytab[leap][i];
  return day;
}
 
/* month_day: ”N‚Ì’ÊZ“ú‚©‚çŒ‚Æ“ú‚ğ‹‚ß‚é */
void month_day(int year, int yearday, int *pmonth, int *pda)
{
  int i, leap;
  leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
  for (i = 1 ; yearday > daytab[leap][i]; i++)
    yearday -= daytab[leap][i];
  *pmonth = i;
  *pda = yearday;
}

void f(int y)
{
  int m, d;

  month_day(y, 60, &m, &d);
  printf("60th day of %d is %d/%d\n",y,m,d);
  printf("%dth day of %d is %d/%d\n",day_of_year(y,m,d),y,m,d);
}

int main(void)
{
  f(1988);
  f(1989);
  f(2100);
  return 0;
}
