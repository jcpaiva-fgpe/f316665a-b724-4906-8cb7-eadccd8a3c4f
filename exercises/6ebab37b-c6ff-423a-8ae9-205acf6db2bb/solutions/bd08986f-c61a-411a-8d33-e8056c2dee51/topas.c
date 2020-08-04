#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define MAX 100

int Equipas[MAX+1][2]={{0,0}};
int N,P,T,C;

void maximo() {
  int i, max=1;

  for(i=2;i<=N;i++) {
    if (Equipas[i][0]>Equipas[max][0]) max=i;
    if (Equipas[i][0]==Equipas[max][0] && Equipas[i][1]<Equipas[max][1]) max=i;
    if (i!=max && Equipas[i][0]>0 && Equipas[i][0]==Equipas[max][0] && Equipas[i][1]==Equipas[max][1]) {printf("Erro no Exemplo\n"); exit(0);}
  }

  if (Equipas[max][0]>0) { 
    printf("%d %d %d\n", max, Equipas[max][0], Equipas[max][1]);
    Equipas[max][0]=0;
    Equipas[max][1]=99999999;
  }
}


int  main() {
  int i,equi, prob, tempo;

 scanf("%d %d %d %d\n",&N, &P, &T, &C);
 
 for (i=0;i<C;i++) {
   scanf("%d %d %d",&equi, &prob, &tempo);
   Equipas[equi][0]++;
   Equipas[equi][1]+=tempo;
 }


 maximo();
 maximo();
 maximo();

 return 0;
}
