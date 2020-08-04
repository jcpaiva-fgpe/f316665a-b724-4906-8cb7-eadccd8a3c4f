#include <stdio.h>


int main()
{
  int t, r, n, max=0;

  scanf("%d %d",&t,&r);
  while (t != -1 || r != -1) {
    n = 0;
    while (t == 1 && r == 1) {
        n++;
	scanf("%d %d",&t,&r);
    }
    if (n > max) max = n;
    if (r!= -1) {
      do scanf("%d",&r); while (r == 0);
      scanf("%d %d",&t,&r);
    }
  }
  printf("%d\n",max);
  return 0;

}
