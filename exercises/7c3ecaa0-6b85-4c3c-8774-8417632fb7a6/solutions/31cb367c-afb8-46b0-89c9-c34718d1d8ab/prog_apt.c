// by apt

#include<stdio.h>

#define DIM 51

char Seq[DIM*DIM+2*DIM+2];
int Matriz[DIM][DIM];

int main() {
  int n, i, j, k, check, erroslinhas, erroscolunas, ierro, jerro;
  

  // ler dados
  scanf("%d %s",&n,Seq);

  for(i=0,k=0; i<n; i++)
    for(j=0; j<n; j++) {
      // Matriz[i][j] = (int) Seq[k]-'0';
      if (Seq[k] == '0') Matriz[i][j] = 0;
      else Matriz[i][j] = 1;
      k++;
    }
  
  for(j=0; j<n; j++) {
    if (Seq[k] == '0') Matriz[n][j] = 0;
      else Matriz[n][j] = 1;
      k++;
  }
  for(i=0; i<n; i++) {
    if (Seq[k] == '0') Matriz[i][n] = 0;
      else Matriz[i][n] = 1;
      k++;
  }
  if(Seq[k] == '0') Matriz[n][n] = 0;
  else Matriz[n][n] = 1;

  erroslinhas = 0;
  for(i=0; i<=n; i++) {
    check = 0;
    for(j=0; j<=n; j++)
      check += Matriz[i][j];
    if (check%2) {
      ierro = i;
      erroslinhas++;
    }
  }

  if (erroslinhas >= 2) 
    printf("ERROS\n");
  else {
    erroscolunas = 0;
    for(i=0; i<=n; i++) {
      check = 0;
      for(j=0; j<=n; j++)
	check += Matriz[j][i];
      if (check%2) {
	jerro = i;
	erroscolunas++;
      }
    }
    if (erroscolunas >= 2)
      printf("ERROS\n");
    else if (erroslinhas + erroscolunas == 2) {
      if (jerro == n) 
	printf("ERRO EM %d\n",(n+1)*n+ierro+1);
      else printf("ERRO EM %d\n",ierro*n+jerro+1);
    }
    else if (erroslinhas + erroscolunas == 0)
      printf("OK\n");
    else printf("ERROS\n");
  }
  return 0;
}
    
