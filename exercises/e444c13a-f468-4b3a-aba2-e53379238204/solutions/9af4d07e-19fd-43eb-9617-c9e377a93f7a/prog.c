#include<stdio.h>


int main() 
{
  int conta[201] = {0}, eqs[201][3];
  int n, tf[3]={0}, i, j, seq;

  scanf("%d",&n);
  scanf("%d",&seq);
  while (seq != -1) {
    eqs[tf[conta[seq]]][conta[seq]] = seq;
    tf[conta[seq]]++;
    conta[seq]++;
    scanf("%d",&seq);
  }

  for (i=3; i > 0; i--) 
    for (j=0; j<tf[i-1]; j++) 
      if (conta[eqs[j][i-1]] == i) printf("%d\n",eqs[j][i-1]);
  printf("No. abandonos (equipa toda): %d\n",n-tf[0]);
   
  return 0;
}

