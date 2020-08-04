#include <stdio.h>
int jogo[3][3];
int conta[3]={0};

#define FALHA "jogo incorrecto\n"

int ABS(int n) {
  if (n<0) return -n;
  return n;
}

int main() {
  int i,j,somah, somav;
  int vencedor[10], vencedores=0;

  for(i=0;i<3;i++) {
    for(j=0;j<3;j++) {
      scanf("%d",&jogo[i][j]);
      conta[jogo[i][j]]++;
      if (jogo[i][j]==2) jogo[i][j]=-1;
    }
  }

  if (conta[1]-conta[2]<0 || conta[1]-conta[2]>1) {
    printf(FALHA);
    return 0;
  }

  if (ABS(jogo[0][0]+jogo[1][1]+jogo[2][2])==3) {
    vencedor[vencedores]=jogo[1][1];
    vencedores++;
  }
  if (ABS(jogo[0][2]+jogo[1][1]+jogo[2][0])==3) {
    vencedor[vencedores]=jogo[1][1];
    vencedores++;
  }

  for(i=0;i<3;i++) {
    somah=0; somav=0;
    for(j=0;j<3;j++) {    
      somah+=jogo[i][j];
      somav+=jogo[j][i];
    }
    if (ABS(somah)==3) {
      vencedor[vencedores]=jogo[i][0];
      vencedores++;
    }
    if (ABS(somav)==3) {
      vencedor[vencedores]=jogo[0][i];
      vencedores++;
    }
  }

  if (vencedores>0) { 
    if (vencedores>2 || (vencedores==2 && vencedor[0]!=vencedor[1])) {
      printf(FALHA);
      return 0;
    }
    if (vencedor[0]==1 && conta[1]==conta[2]+1) { printf("venceu jogador 1\n"); return 0;}
    if (vencedor[0]==-1 && conta[1]==conta[2])  { printf("venceu jogador 2\n"); return 0;}
  }

  if (vencedores==0 && conta[0]==0) {
     printf("empate\n");
  }


  printf(FALHA);

return 0;
}
