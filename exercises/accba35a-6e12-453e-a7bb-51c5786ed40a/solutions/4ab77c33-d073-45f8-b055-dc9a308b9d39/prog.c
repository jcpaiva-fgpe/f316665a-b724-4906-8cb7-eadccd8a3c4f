#include <stdio.h>


int main()
{
  int a, b, c, k;
 
  scanf("%d",&k);
  while (k-- > 0) {
    scanf("%d %d %d",&a,&b,&c);

    if (a>0 && b > 0 && c > 0) {
      if (a == b && b == c) printf("Sim, equilatero.\n");
      else if (a < b+c && b < a+c && c < a+b) printf("Sim.\n");
      else printf("Claro que nao!\n");
    } else printf("Claro que nao!\n");
  }

  return 0;
}
