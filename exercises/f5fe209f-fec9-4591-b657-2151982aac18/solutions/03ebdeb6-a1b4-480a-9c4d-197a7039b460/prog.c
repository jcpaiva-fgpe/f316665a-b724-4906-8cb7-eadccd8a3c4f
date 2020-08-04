#include <stdio.h>

int main()
{
  char c;
  int n = 0;
  
  while ((c=getchar()) != 'O' && c != 'o' && c != '!');
  if (c != '!') {
    do {
      n++;
      getchar();
      c = getchar();
    } while (c == 'o' || c == 'O');
  }
  printf("%d\n",n);
  return 0;
}
