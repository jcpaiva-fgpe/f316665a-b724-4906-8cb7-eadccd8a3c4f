#include <stdio.h>


int main()
{
  int n, vezes;
  char c;
  scanf("%d\n",&n);
  while (n-- > 0) {
    scanf("%c%d\n",&c,&vezes);
    while(vezes-- > 0)
      putchar(c);
    putchar('\n');
  }

  return 0;
}
