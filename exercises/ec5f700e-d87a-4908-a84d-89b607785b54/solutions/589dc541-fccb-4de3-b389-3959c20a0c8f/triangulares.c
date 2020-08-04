#include <stdio.h>

main()
{
  int i,n;

  scanf("%d",&n);

  for(i=1;n>0;i++) n-=i;
  if (n==0) printf("SIM\n");
  else printf("NAO\n");
}
