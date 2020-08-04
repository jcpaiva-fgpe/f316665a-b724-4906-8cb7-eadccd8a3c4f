#include <stdio.h>
#include <stdlib.h>

#define MAX 51

int  n,m,numeroPretas;
int  iBranca, jBranca;
int iPreta[MAX], jPreta[MAX], sPreta[MAX];
int debug=0;

void mostra_estado() {
  int i, j, flag=0;
  int mat[MAX][MAX];

  if (debug==0) return;

  for(i=0;i<MAX;i++)
    for(j=0;j<MAX;j++) mat[i][j]='.';

  mat[iBranca][jBranca]='B';

  for(i=0;i<numeroPretas;i++) {
    int lin,col,dir;

    lin=iPreta[i];
    col=jPreta[i];
    dir=sPreta[i];

    if (mat[lin][col]!='.') { flag=1; mat[lin][col]='*';}
    else { if (dir==1) mat[lin][col]='>'; else mat[lin][col]='<'; }  
  }

  for(i=0;i<m+2;i++) fprintf(stdout,"-");
  fprintf(stdout,"\n");

  for(i=1;i<=n;i++) {
    printf("|");
    for(j=1;j<=m;j++) {
      fprintf(stdout,"%c",mat[i][j]);
    }
    fprintf(stdout,"|\n");
  }

  for(i=0;i<m+2;i++) fprintf(stdout,"-");

  fprintf(stdout,"\n\n");
  if (flag) exit(0);
}


int main(int argc,char *argv[]) {

    int  i, j;
    
  if (argc>1) debug=1;

  /* ler n e m */
  fscanf(stdin,"%d %d\n", &n, &m);

  /* inicializar linha da branca */
  iBranca = 1;

  /* ler coluna da branca */
  fscanf(stdin,"%d\n", &jBranca);

  /* ler numero de pretas */
  fscanf(stdin,"%d\n", &numeroPretas);
  
  for( i = 0 ; i < numeroPretas ; i++ ) {
      /* ler uma preta */
      fscanf(stdin,"%d %d %d\n", &iPreta[i], &jPreta[i], &sPreta[i]);
  }
  

  mostra_estado();
  for( i = 1 ; i < n ; i++ ) {
     /* actualizar a branca */
     iBranca++;
     /* avanco 1 posicao para cada bola */  
     for( j = 0 ; j < numeroPretas ; j++ ) {

       /* testa limites e inverte sentido se necessario */
       if (jPreta[j] == 1) sPreta[j]=1;
       if (jPreta[j] == m ) sPreta[j] = -1;

       /* avanca posicao */ 
       jPreta[j] = jPreta[j] + sPreta[j];
    
       /* verifica colisao */
       if( iPreta[j] == iBranca && jPreta[j] == jBranca ) {
           fprintf(stdout,"colide %d\n", iPreta[j]);
           mostra_estado();
           exit(0);
       }
     }
     mostra_estado();
  }

  fprintf(stdout,"passa\n");
  exit(0);   
}
