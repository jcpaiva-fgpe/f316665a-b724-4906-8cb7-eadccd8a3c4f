#include <stdio.h>

int main()
{
  int e, c, i, nmoedas, paga, preco=0, moeda[8], val[]={200,100,50,20,10,5,2,1};

  scanf("%d%d",&e,&c);
  preco = e*100+c;

  for(i=paga=0;i<8;i++) {
    scanf("%d",&moeda[i]);
    paga += moeda[i]*val[i];
  }

  if (paga >= preco) {
    preco = paga-preco;
    for(i=0;i<8;i++) {
      moeda[i] = preco/val[i];
      preco -= val[i]*moeda[i];
    }
  }

  printf("%d",moeda[0]);
  for(i=1;i<8;i++) printf(" %d",moeda[i]);
  putchar('\n');

  return 0;
}
    
  
