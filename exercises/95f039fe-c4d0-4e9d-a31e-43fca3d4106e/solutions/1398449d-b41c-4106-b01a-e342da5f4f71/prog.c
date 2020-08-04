// by apt
#include <stdio.h>



int main()
{
  
  int q, c, n, dist, preco, imelhor, distmelhor, i;

  int customelhor, custo;

  scanf("%d%d",&q,&c);
  scanf("%d",&n);

  scanf("%d%d",&distmelhor,&preco);
  imelhor = 0;
  customelhor = 1.0*q*preco/(q-2.0*c*distmelhor/100000);
  

  for(i=1;i<n;i++) {
    scanf("%d%d",&dist,&preco);
    custo = 1.0*q*preco/(q-2.0*c*dist/100000);
    if (custo < customelhor || (custo == customelhor && dist < distmelhor) ) {
      imelhor = i;
      customelhor = custo;
      distmelhor = dist;
    } 
  }
  printf("%d\n",imelhor+1);
  return 0;
}






