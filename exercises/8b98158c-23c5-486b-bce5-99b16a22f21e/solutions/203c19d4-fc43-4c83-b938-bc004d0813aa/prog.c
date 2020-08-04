#include <stdio.h>


int main()
{
   int pontos[4][6], ord[4], i, j, k, pior, aux;

   for(i=0;i<4;i++) 
     for(j=0;j<6;j++) 
       scanf("%d", &pontos[i][j]);
   
   for(j=0;j<5;j++) {
     for(i=0;i<4;i++) {
       pior = j;
       for(k=j+1;k<6;k++) 
         if (pontos[i][k] < pontos[i][pior]) pior = k;
       if (j != pior) {
	  aux = pontos[i][j];
	  pontos[i][j] = pontos[i][pior];
	  pontos[i][pior] = aux;
       }
     }
   }
   
   for(i=0;i<4;i++) ord[i] = i;

   for(i=0;i<3;i++) {
     pior = i;  // melhor
     for(k=i+1;k<4;k++) {
       for(j=0;j<6 && pontos[ord[k]][j] == pontos[ord[pior]][j] ;j++) ;
       if (j < 6 && pontos[ord[k]][j] > pontos[ord[pior]][j]) 
         pior = k;
     }
     if (pior != i) {
       aux = ord[i];
       ord[i] = ord[pior];
       ord[pior] = aux;
     }
   }

   printf("%d",ord[0]+1);
   for(i=1;i<4;i++) printf(" %d", ord[i]+1);
   putchar('\n');
   return 0;
}
