#include <stdio.h>
#include <string.h>

/* my_getline: 1 行読んで, 長さを返す */
int my_getline(char *line, int max)
{
  if (fgets(line, max, stdin) == NULL)
    return 0;
  else
    return strlen(line);
}

int main(void)
{
  char line[256];

  while (my_getline(line, sizeof line) != 0)
    printf("%s", line);
  return 0;
}
