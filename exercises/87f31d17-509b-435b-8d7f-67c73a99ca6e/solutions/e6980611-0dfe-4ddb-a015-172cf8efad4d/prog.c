#include <stdio.h>

int main() {

  int a, b, q, r, n;
  char x,y;

  scanf("%d",&n);

  while(n-- > 0) {
    scanf("%d %d %c %c", &a,&b,&x,&y);
    if (b == 0) {
      q = 0;
      r = a;
    } else {
      q = a/b;
      r = a%b;
    }
      
    if (x == 'Q') 
      printf("Q: %d R: %d\n",q,r);
    else
      printf("R: %d Q: %d\n",r,q);
  }

  return 0;
}
