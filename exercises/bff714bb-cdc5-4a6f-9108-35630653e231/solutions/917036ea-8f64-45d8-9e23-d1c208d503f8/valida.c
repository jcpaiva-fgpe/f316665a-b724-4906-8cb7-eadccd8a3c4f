#include <stdio.h>
#include <stdlib.h>

int main()
{
  int e, c, i, moeda;

  scanf("%d%d",&e,&c);
  if(e < 0 ||e >1000 || c < 0 || c > 99) {
    fprintf(stderr,"erro");
    exit(1);
  }
  printf("%d %d\n",e,c);

  for(i=0;i<8;i++) {
    scanf("%d",&moeda);
    if (moeda >=0) 
      if(i==0) printf("%d",moeda);
      else printf(" %d",moeda);
    else {
      fprintf(stderr,"erro");
      exit(1);
    }
  }
  putchar('\n');

  return 0;
}
    
  
