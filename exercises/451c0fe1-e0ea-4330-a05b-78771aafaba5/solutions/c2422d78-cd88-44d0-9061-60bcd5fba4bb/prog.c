#include <stdio.h>

#define MAXDIM 50

char Grelha[MAXDIM+2][MAXDIM+2];
int M, N, Intensidade, Energia, Tempo;
int Mov[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};   // Di Dj na tabela: N E S O

void inicializa_grelha();
void pos_inicial(int pos[]);

void inicializa_grelha() {
  int i, j;
  char aux[MAXDIM+1];
  
  // duas linhas e duas colunas adicionais vazias 
  for(j=0;j<=N+1;j++) {
    Grelha[0][j] = '-';
    Grelha[M+1][j] = '-';
  }
  
  for(i=1;i<=M;i++) {
    scanf("%s",aux);
    Grelha[i][0] = '-';
    Grelha[i][N+1] = '-';
    for(j=1; j<=N;j++)
      Grelha[i][j] = aux[j-1];
  }
}

void pos_inicial(int pos[]) {
  int i, j, conta, k;
  char c;

  for(i=1;i<=M;i++)
    for(j=1;j<=N;j++)
      if (Grelha[i][j] == 'T') {
	conta = 0;
	for(k = 0; k < 4 && conta < 2; k++) {
	  c = Grelha[i+Mov[k][0]][j+Mov[k][1]];
	  if (c == 'T') conta += 1;
	  else if (c == 'L') {
	    conta = 0; break;
	  }
	}
	if (conta == 1) {
	  pos[0] = i;
	  pos[1] = j;
	  return;
	}
      }
}


int avanca_posicao(int pos[]) {
  int k; 
  char c;

  Grelha[pos[0]][pos[1]] = 'X';   // bloqueia
  for(k = 0; k < 4; k++) {
    c = Grelha[pos[0]+Mov[k][0]][pos[1]+Mov[k][1]];
    if (c== 'T' || c == 'L')
      break;
  }
  pos[0] += Mov[k][0];
  pos[1] += Mov[k][1];
  Energia--;
  Tempo++;
  return c;
}

int temfoco(char c) {
  if (c=='N' || c == 'S' || c == 'E' || c == 'O')
    return 1;
  return 0;
}

#define ABS(X) ((X) > 0? (X): (-(X)))

int norma(int a,int b){
  return ABS(a)+ ABS(b);
}

int tempo_espera(char c, int k) {
  int kc, ka, ktarget = (k+2)%4;

  switch(c) {
  case 'N': 
    kc = 0;
    break;
  case 'E':
    kc = 1;
    break;
  case 'S':
    kc = 2;
    break;
  default:
    kc = 3;
  }

  ka = (kc + Tempo) % 4;
  if (ktarget - ka < 0) 
    return ktarget - ka + 4;
  return ktarget - ka;
}



int encontra_focos(int pos[],int focos[][3],int *nfocos) {
  int k, i, j, e;
  int nfrest = 0;
  *nfocos = 0;
  // determina focos
  for (k=0; k<4; k++) {
    if (Grelha[pos[0]+Mov[k][0]][pos[1]+Mov[k][1]] == 'F') {
      nfrest++;
      i=pos[0]+2*Mov[k][0];
      j=pos[1]+2*Mov[k][1];
      while(i>=1 && i <= M && j >=1 && j <= N) {
	if (Grelha[i][j]== '-') {
	i += Mov[k][0];
	j += Mov[k][1];
	} else {
	  if (temfoco(Grelha[i][j]) &&
	      (e = Intensidade-norma(i-pos[0],j-pos[1])) > 0) {
	    focos[*nfocos][0] = k;
	    focos[*nfocos][1] = norma(i-pos[0],j-pos[1]);
	    focos[*nfocos][2] = tempo_espera(Grelha[i][j],k);
	    *nfocos = *nfocos + 1;
	  }
	  break;
	}
      }
    }
  }
  return nfrest;
}


void recebe_energia(int pos[]) {
  int k;
  int focos[3][3], nfrest, nfocos=0, min, e;

  // determina focos
  nfrest = encontra_focos(pos,focos,&nfocos);
  if (nfrest == 0) return;   // sem frestas

  if (nfocos == 0) {
    if (Energia > 4)  {  // espera mas não recebe
      Energia -= 3;
      Tempo += 3;
    }
    return;
  }
  
  for (k=0, min = 5;k<nfocos;k++) 
    if (focos[k][2] < min)
      min = focos[k][2];

  if (min != 0 && Energia <= 4)
    return;
    
  for (k= e= 0;k<nfocos;k++) 
    if (focos[k][2] == min)
      e += (Intensidade - focos[k][1]);

  Energia += e-min;
  Tempo += min;

}

  
int main(){
  
  int pos[2];
  char simbolo;

  scanf("%d%d%d%d",&M,&N,&Intensidade,&Energia);
  
  inicializa_grelha();
  
  pos_inicial(pos);

  Tempo = 0;
  do {
    simbolo = avanca_posicao(pos);
    recebe_energia(pos);  // espera se necessario
  } while (simbolo != 'L' && Energia > 0);

  if (Grelha[pos[0]][pos[1]] == 'L') 
    printf("%d %d\n",Tempo,Energia);
  else  printf("%d\n",Tempo);

  return 0;
}

  
   
  
