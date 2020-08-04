#include <stdio.h>

#define MAXNOS 101

int Ramos[MAXNOS][3], Valor[MAXNOS];

int main()
{
  int n, f, r, i, aux, v;
 
  scanf("%d %d",&n,&f);

  for (r = 1; r < n; r++) 
    scanf("%d %d %d",&Ramos[r][0],&Ramos[r][1],&Ramos[r][2]);
  for (i = 0; i < f; i++) {
    scanf("%d %d",&aux,&v);
    Valor[aux] = v;
  }

  while (--r != 0) {
    v = Valor[Ramos[r][1]]*Ramos[r][2];
    aux = Ramos[r][0];
    while (r>1 && Ramos[r-1][0] == aux) {
      r--;
      v = v + Valor[Ramos[r][1]]*Ramos[r][2];
    }
    Valor[aux] = v/10;
    //    printf("intermedio -- %d --- %d\n",aux,v/10);
  }

  printf("%d\n",Valor[1]);

  return 0;
}
