#include <stdio.h>

main()
{
  int i,r,n,j,linhas;
  int v1[51],v2[51];

  scanf("%d",&n);
  
  r = n%2;
  linhas = n/2 + r;
  v1[0]=1;
  v2[0]=2;
  printf("%2d",v1[0]);
  for(i=0;i<linhas-2;i++) printf("  ");
  printf("%2d\n",v2[0]);
  for(j=1;j<linhas;j++)
    {
      if (r==1 && j<(linhas/2+1)) v1[j]=v1[j-1]+4;
      if (r==1 && j==(linhas/2+1)) v1[j]=v1[j-1]-2;
      if (r==1 && j>(linhas/2+1))  v1[j]=v1[j-1]-4;
      if (r==1 && j<(linhas/2)) v2[j]=v2[j-1]+4;
      if (r==1 && j==(linhas/2)) v2[j]=v2[j-1]+3;
      if (r==1 && j==(linhas/2+1)) v2[j]=v2[j-1]-1;
      if (r==1 && j>(linhas/2+1))  v2[j]=v2[j-1]-4;

      if (r==0 && j<(linhas/2)) v1[j]=v1[j-1]+4;
      if (r==0 && j==(linhas/2)) v1[j]=v1[j-1]+2;
      if (r==0 && j>(linhas/2))  v1[j]=v1[j-1]-4;
      if (r==0 && j<(linhas/2)) v2[j]=v2[j-1]+4;
      if (r==0 && j==(linhas/2)) v2[j]=v2[j-1]+2;
      if (r==0 && j>(linhas/2))  v2[j]=v2[j-1]-4;

      if (v1[j]>n) v1[j]=0;
      if (v2[j]>n) v2[j]=0;

      if (j<linhas/2)
	{
	  for(i=0;i<j;i++) printf("  ");      
	  if (v1[j]>0) printf("%2d",v1[j]);
	  else printf("  ");
	  for(i=0;i<linhas-2*(j+1);i++) printf("  "); 
	  if (v1[j]>0) printf("%2d",v2[j]);
	  else printf("  ");     
	  for(i=0;i<j;i++) printf("  ");
          printf("\n");            
    	}
      else
	{
	  for(i=0;i<linhas-j-1;i++) printf("  ");      
	  if (v2[j]>0) printf("%2d",v2[j]);
	  else printf("  ");
	  for(i=0;i<2*j-linhas;i++) printf("  ");      
	  if (v2[j]>0 && v2[j]!=v1[j]) printf("%2d",v1[j]);
	  else if (v2[j]!=v1[j]) printf("  ");
	  for(i=0;i<linhas-j-1;i++) printf("  ");
          printf("\n");            
	}
    }
}
