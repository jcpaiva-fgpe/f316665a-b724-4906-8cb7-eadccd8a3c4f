#include <stdio.h>


int main()
{
  int n,m;

  scanf("%d%d\n",&n,&m);
  
  if(m%n) 
    printf("Nao sou multiplo de %d\n",n);
  else
    printf("Sou multiplo de %d\n",n);

  return 0;
}
