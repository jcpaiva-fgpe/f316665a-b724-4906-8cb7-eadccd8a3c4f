#include <stdio.h>


int main() {
  int tent, dif, max = 0, curr = 0, n, conta = 0;

  while ((tent = getchar()) != '\n') {
    if (tent == '1') curr++;
    else {
      if (curr > max) max = curr;
      curr = 0;
    }
  }
  if (curr > max) max = curr;

  scanf("%d",&n);
  conta = 0;
  while(n-- > 0) {
    scanf("%d",&dif);
    if (max > dif) conta++;
  }

  printf("%d\n",conta);
  
  return 0;
}





