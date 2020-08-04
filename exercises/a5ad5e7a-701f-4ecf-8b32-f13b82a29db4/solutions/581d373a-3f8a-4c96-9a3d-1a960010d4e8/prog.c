#include <stdio.h>


int main()
{
  int preco, imposto;
  scanf("%d",&preco);
  imposto = preco*2325/10000;
  printf("%d (talvez estimativa por defeito)\n",preco+imposto);
  return 0;
}
