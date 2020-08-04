#include <stdio.h>


int main()
{ 
  int i, n, a, b, an, bn;
  scanf("%d",&n);
  scanf("%d %d",&a,&b);

  for (i=1; i< n; i++) {
    scanf("%d %d",&an,&bn);
    if (an > b || bn < a) {
      printf("impossivel\n");
      return 0;
    }
    if (bn == a) b = a;
    else if (b == an) a = b;
    else {
      a = (an > a? an:a);
      b = (bn <b? bn:b);
    }
  }
  if ((a+b)%2 == 1) 
    printf("%d e meia\n", (a+b)/2);
  else printf("%d\n", (a+b)/2);
  return 0;
}
