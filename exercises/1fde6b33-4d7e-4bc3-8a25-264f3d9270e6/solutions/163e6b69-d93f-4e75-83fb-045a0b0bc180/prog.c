#include <stdio.h>

//#define INICIO 9
//#define FIM 19

#define MIN(A,B) ((A) < (B)? A:B)
#define MAX(A,B) ((A) > (B)? A:B)

int main()
{ int dur, a,b,c,d;
  int res0, res1;

  scanf("%d",&dur);
  scanf("%d %d",&a,&b);
  scanf("%d %d",&c,&d);

  b -= dur;     d -= dur;
  // if (b < a || d < c) printf("Impossivel\n");
  //  else {
  res0 = MAX(c,a);
  res1 = MIN(b,d);
  if (res0 > res1) printf("Impossivel\n");
  else 
    if (res0 == res1) printf("%d\n",res0);
    else  printf("%d %d\n",res0,res1);
  return 0;
}
