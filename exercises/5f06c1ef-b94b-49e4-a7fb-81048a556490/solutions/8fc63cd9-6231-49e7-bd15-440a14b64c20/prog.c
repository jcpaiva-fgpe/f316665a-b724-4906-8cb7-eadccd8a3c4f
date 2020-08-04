// by apt
#include <stdio.h>

#define N 9

#define OK(I) ((I)>=0 && I<N)

// comment the following line for input/output tests
//#define ECHO
// debugging


int DirOrt[8]={1,0,0,1,-1,0,0,-1};

int Canvas[N][N], NotVisited[N][N];


void ler_tabuleiro()
{
  int i,j;
  for (i=N-1; i>=0; i--)
    for (j=0; j<N; j++) 
      scanf("%d",&Canvas[i][j]);
}


int existeCaminho__(int i,int j) 
{ int ii, jj, found=0, d;
  if (NotVisited[i][j]==2) return 1;
  NotVisited[i][j]=0;

  for (d=0; d<8 && !found; d = d+2) {
    ii = i+DirOrt[d]; jj = j+DirOrt[d+1];
    if (OK(ii) && OK(jj) && NotVisited[ii][jj])
      found = existeCaminho__(ii,jj);
  }
  return found;
}


int existeCaminho(int pi,int pj,int npi,int npj) {

  int i,j;
  for (i=N-1; i>=0; i--)
    for (j=0; j<N; j++)
      if (Canvas[i][j]) NotVisited[i][j] = 0;
      else NotVisited[i][j] = 1;

  NotVisited[npi][npj] = 2;  // onde quer chegar

  // para (pi,pj) e (npi,npj) distintos
  
  return existeCaminho__(pi,pj);
}


int alinha(int di,int dj,int npi, int npj, int *total)
{
  int i = npi, j = npj, t=0;
  while(OK(i+di) && OK(j+dj) && Canvas[i+di][j+dj]==Canvas[npi][npj]) {
    i += di; j += dj;
  }
  while(OK(i) && OK(j) && Canvas[i][j]==Canvas[npi][npj]) {
     i -= di; j -= dj;
     t++;
  }
  if (t>=5) {
    *total += t;
#ifdef ECHO 
     printf("alinhamento (%d,%d) com %d pecas\n",di,dj,t);
#endif
    return 1;
  } 
#ifdef ECHO 
     printf("sem alinhamento (%d,%d)\n",di,dj);
#endif
  return 0;
}


int alinhamentos(int npi,int npj)
{ 
  int n=0,i, total=0, dir[8]={0,1,1,0,1,1,-1,1};
  for (i=0; i<8; i = i+2) 
    n += alinha(dir[i],dir[i+1],npi,npj,&total);
  if (n >= 2) return total-(n-1);
  return total;
}


int quantasSaem(int pi,int pj,int npi, int npj)
{
  // posicao seleccionada nao tinha peca; nao deve ocorrer nos testes
  if (!Canvas[pi][pj]) {
#ifdef ECHO 
     printf("(%d,%d) sem peca\n",pi,pj);
#endif
     return 0;
  }

  // posicao ocupada; nao pode mover
  if (Canvas[npi][npj]) {
#ifdef ECHO 
     printf("(%d,%d) com peca\n",npi,npj);
#endif
     return 0;
  }

  // posicao livre
  if (!existeCaminho(pi,pj,npi,npj)) {
#ifdef ECHO 
     printf("sem caminho\n");
#endif
     return 0;
  }
  Canvas[npi][npj] = Canvas[pi][pj];
  Canvas[pi][pj] = 0;
  return alinhamentos(npi,npj);
}


int main()
{
  int pi,pj,npi,npj;
  ler_tabuleiro();

  scanf("%d %d",&pi,&pj);
  scanf("%d %d",&npi,&npj);
  pi--; pj--;
  npi--; npj--;   
  printf("%d\n",quantasSaem(pi,pj,npi,npj));
  return 0;
}

