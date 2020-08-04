#include <stdio.h>

#define QUAD_DIST(A,B,C,D) (((C)-(A))*((C)-(A))+((D)-(B))*((D)-(B)))




int main()
{
  int xc,yc,x,y,r,d,n;

  scanf("%d %d",&xc,&yc);
  scanf("%d",&r);
  scanf("%d",&n);
  while (n) {
    scanf("%d %d",&x,&y);
    d = QUAD_DIST(x,y,xc,yc);
    printf("(%d,%d): ",x,y);
    if (d == r*r) printf("na fronteira\n");
    else 
      if (d > r*r) printf("no exterior\n");
      else  printf("no interior\n");
    n--;
  }
  return 0;
}
