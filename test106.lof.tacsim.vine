5:int my_getline(char *line, int max);
8:int main(int argc, char *argv[])
12:  int c, except = 0, number = 0, found = 0;
24:	printf("find: illegal option %c\n",c);
30:    printf("Usage: find -x -n pattern\n");
36:	  printf("%ld:", lineno);
37:	printf("%s", line);
41:  printf("found = %d\n", found);
46:int my_getline(char s[], int lim)
48:  int c, i;
found = 10
1:#include <stdio.h>
2:#include <string.h>
3:#define MAXLINE 1000
4:
5:int my_getline(char *line, int max);
6:
7:/* find: 最初の引数にあるパターンとマッチする行を表示する */
8:int main(int argc, char *argv[])
9:{
10:  char line[MAXLINE];
13:
16:      switch (c) {
17:      case 'x':
19:	break;
20:      case 'n':
22:	break;
23:      default:
24:	printf("find: illegal option %c\n",c);
27:	break;
28:      }
30:    printf("Usage: find -x -n pattern\n");
31:  else
32:    while (my_getline(line, MAXLINE) > 0) {
33:      lineno++;
35:	if (number)
36:	  printf("%ld:", lineno);
37:	printf("%s", line);
38:	found++;
39:      }
40:    }
42:  return 0;
43:}
44:
45:/* my_getline: s に行を入れ, 長さを返す */
46:int my_getline(char s[], int lim)
47:{
48:  int c, i;
53:    ++i;
54:  }
56:  return i;
57:}
found = 41
