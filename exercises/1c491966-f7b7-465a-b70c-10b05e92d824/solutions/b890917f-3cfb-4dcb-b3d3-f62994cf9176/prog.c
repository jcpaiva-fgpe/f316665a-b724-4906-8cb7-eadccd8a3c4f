#include <stdio.h>

#define MMAX 50
#define NMAX 50

int contarGambozino(int g,int m, int n);
void marcaVisitado(int a, int b);
int gambozino(int g,int a, int b);

int Gamb[15][3] = {
  {0,1,0},{0,1,1},{1,1,0},
  {0,1,0},{1,1,0},{0,1,1},
  {0,0,1},{1,1,1},{0,1,0},
  {1,1,0},{0,1,1},{0,1,0},
  {0,1,0},{1,1,1},{1,0,0}};

int Reg[MMAX][NMAX];


int main(){
  int n, m, i, j, g, conta = 0;

  scanf("%d %d", &m, &n);
  for(i=0;i<m;i++)
    for(j=0;j<n;j++)
      scanf("%d",&Reg[i][j]);
  for(g=0;g<5;g++)
    conta += contarGambozino(g,m,n);
  printf("%d\n",conta);
  return 0;
}

int gambozino(int g,int a, int b) {
  int i, j;
  for(i=0;i<3;i++)
    for(j=0;j<3;j++)
      if (Gamb[g+i][j] != Reg[a+i][b+j]) 
	return 0;
  for(j=0;j<3;j++) {
    if (Gamb[g][j] == 1 && Reg[a-1][b+j]== 1) return 0;
    if (Gamb[g+2][j] == 1 && Reg[a+3][b+j]== 1) return 0;
  }
  for(i=0;i<3;i++) {
    if (Gamb[g+i][0] == 1 && Reg[a+i][b-1]== 1) return 0;
    if (Gamb[g+i][2] == 1 && Reg[a+i][b+3]== 1) return 0;
  }
  return 1;
}

int contarGambozino(int g,int m, int n){
  int i, j, conta;
  g=3*g;
  for(conta = 0, i=1; i < m-3; i++)
    for(j=1;j<n-3;j++) 
      if (gambozino(g,i,j)) {
	marcaVisitado(i,j);
        conta++;
      }
  return conta;
}

void marcaVisitado(int a, int b) {
  int i, j;
  for(i=0;i<3;i++)
    for(j=0;j<3;j++)
      Reg[a+i][b+j] = 0;
}
