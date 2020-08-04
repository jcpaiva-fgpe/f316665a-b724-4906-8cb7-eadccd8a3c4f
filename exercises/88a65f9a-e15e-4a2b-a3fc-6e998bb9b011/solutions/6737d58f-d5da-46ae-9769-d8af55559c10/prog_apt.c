#include <stdio.h>


int corrige(int preco){
  int aux = preco%100;
  if (aux != 0 && aux != 50) {
    if (aux < 50) aux = 50;
    else aux = 100;
    preco = preco/100*100+aux;
  }
  return preco;
}


int main()
{ int preco, dias, grupo, aux;

  scanf("%d%d%d",&preco,&dias,&grupo);

  preco = preco*75/100;
  preco = corrige(preco);

  if (dias >= 5) {
    if (dias >= 8) 
      preco = preco * 35/100;
      else  preco = preco * 60/100;
    preco = corrige(preco);
  }
  
  if(grupo >= 4) {
    preco = preco*50/100;
    preco = corrige(preco);
  }

  printf("%d\n",preco);
  return 0;
}


