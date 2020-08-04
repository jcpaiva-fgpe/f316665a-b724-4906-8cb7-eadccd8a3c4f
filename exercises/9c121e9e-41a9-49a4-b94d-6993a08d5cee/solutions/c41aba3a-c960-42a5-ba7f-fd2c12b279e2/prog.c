#include <stdio.h>

int main()
{
  int n, j, r, q;
  scanf("%d %d",&n,&j);

  while(n != 0) {
    q = n / j;
    r = n % j;
    if (r >= q && (r/q >= 2 || r%q != 0) )
	printf("\n BAD DATA %d %d \n",n,j);
    printf("%d %d %d\n",q,q-r,r);
    scanf("%d %d",&n, &j);
  }

  return 0;
}
