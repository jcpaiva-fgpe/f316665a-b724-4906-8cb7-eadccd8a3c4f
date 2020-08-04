#include <stdio.h>

#define MAXSEQ 900000
// valor nao dado

int main() {
  char seq[MAXSEQ];
  int t, dif, i, n, conta = 0;

  scanf("%s",seq);

  scanf("%d",&n);
  conta = 0;
  while(n-- > 0) {
    scanf("%d",&dif);
    for(i=0;seq[i]!='\0';i++) {
      t = 0;
      while(seq[i] == '1') {
	t++;
	i++;
      }
      if (t > dif) {
	conta++;
	break;
      }
    }
  }

  printf("%d\n",conta);
  
  return 0;
}





