#include <stdio.h>
#define MAXN 100

int main() {
  int n, m, i, s, p, pontos[MAXN]={0}, max;
  
  scanf("%d%d",&n,&m);

  while(m-- > 0) {
    for(i=s=0;i<n;i++) {
      scanf("%d",&p);
      s += p;
    }

    pontos[s%n]++;
  }
  
  printf("%d\n",pontos[0]);
  max = pontos[0];
  for(i=1;i<n;i++) {
    if (max < pontos[i]) max = pontos[i];
      printf("%d\n",pontos[i]);
  }
  putchar('\n');
  for (i=0; i<n; i++)
    if(pontos[i] == max)
      printf("%d\n",i);
  return 0;
}
