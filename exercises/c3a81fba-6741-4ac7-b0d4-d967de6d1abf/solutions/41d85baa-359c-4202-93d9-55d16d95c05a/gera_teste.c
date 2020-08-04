#include <stdio.h>
#define MAXN 99
#define MAXM 99

int main() {
  int i,j, n, m;
  
  printf("%d %d\n",MAXN,MAXM);
  n = MAXN;
  m = MAXM;

  for(i=0;i<m;i++){
    for(j=0;j<i;j++)
      if (j==0) printf("%d",0);
      else printf(" %d",0);
    if (j==0) printf("%d",0);
    else printf(" %d",i);
    for(++j;j<n;j++)
      if (j==0) printf("%d",0);
      else printf(" %d",0);
    printf("\n");
  }

  return 0;
}
