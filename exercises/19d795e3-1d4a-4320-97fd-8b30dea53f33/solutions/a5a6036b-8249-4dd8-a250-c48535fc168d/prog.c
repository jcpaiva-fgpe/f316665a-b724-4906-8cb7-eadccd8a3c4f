#include <stdio.h>

int main() {

  int a, b, n;
  char x,y;

  scanf("%d",&n);

  while(n-- > 0) {
    scanf("%d %d %c %c", &a,&b,&x,&y);
    if (x == 'Q') 
      printf("Q: %d R: %d\n",a/b,a%b);
    else
      printf("R: %d Q: %d\n",a%b,a/b);
  }

  return 0;
}
