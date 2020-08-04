#include <stdio.h>

// sem poupar memória

#define NMAX 20*20*20+20


int main()
{
  int a[NMAX], b[NMAX], n, fa, fb, ia, ib;

  scanf("%d",&n);

  for (fa = 0; fa < n; fa++)
    scanf("%d",&a[fa]);

  for (fb = 0; fb < n; fb++)
    scanf("%d",&b[fb]);

  n = n*n*n+n;
  
  ia = ib = 0;
  while(n && ia < fa && ib < fb) {
    //    printf("a -- %d   b -- %d\n",a[ia],b[ib]);
    if (b[ib] > a[ia]) {
      b[fb++] = b[ib]-1;
      if (a[ia] != 1) b[fb++] = a[ia]-1;
    } else if (b[ib] < a[ia]) {
      a[fa++] = a[ia]-1;
      if (b[ib] != 1) a[fa++] = b[ib]-1;
    } else {
      if (b[ib] != 1) {
	b[fb++] = b[ib]-1;
        a[fa++] = b[fb-1];
      }
    }
    n--;
    ia++;  ib++;
  }
  if (ia == fa) 
    if (ib == fb) printf("E\n");
    else printf("B\n");
  else if (ib == fb) printf("A\n");
  else printf("E\n");
  
  return 0;
}
