#include <stdio.h>
#include <stdlib.h>

int main() {
  int n=0, k,m;
  scanf("%d%d",&k,&m);
  while(k!=0 || m!=0) {
    if (k < 0 || k > 100 || m < 0 || m> 1000) {
      fprintf(stderr,"Erro\n");
      exit(1);
    }
    n++;
    printf("%d %d\n",k,m);
    scanf("%d%d",&k,&m);
  }
  
  if (n<2 || n> 1000) {
    fprintf(stderr,"Erro\n");
    exit(1);
  }
  printf("%d %d\n",k,m);
  return 0;
}
