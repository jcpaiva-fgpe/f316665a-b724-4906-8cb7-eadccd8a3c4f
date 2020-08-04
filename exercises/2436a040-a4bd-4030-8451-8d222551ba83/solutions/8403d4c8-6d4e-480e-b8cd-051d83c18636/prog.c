#include <stdio.h>


#define N 10

int Jogo[2][N+2][N+2];   // em alternativa, usar duas matrizes
char Tipos[5] ="PEHCS";


#define SUBMARINO 6
#define CRUZADOR  5
#define HIDROAVIAO  4
#define ENCOURACADO  3
#define PORTAAVIAO  2
#define TIRO -1

void ler_jogada(int jogada[]);
int jogada_valida(int jogada[],int jogador);
void processar_jogada(int jogador,int jogada[],int total[]);

void marcar_frota(int total[]);
int encouracados(int jogador);
int portaAvioes(int jogador);
int cruzadores(int jogador);
int submarinos(int jogador);
int hidroAvioes(int jogador);

void marcar_frota(int total[]) 
{ 
  int jogador;
  for(jogador = 0; jogador < 2; jogador++) {
    total[jogador] = 0;
    total[jogador] += 4*encouracados(jogador);
    total[jogador] += 5*portaAvioes(jogador); // depois de encouracados (implementacao)
    total[jogador] += 2*cruzadores(jogador);
    total[jogador] += submarinos(jogador);
    total[jogador] += 3*hidroAvioes(jogador); // ultimos a marcar (implementacao)
  }
}

int hidroAvioes(int jogador) {
  int i, j, n=0;
  // assume que é o último a marcar
  for(i=1; i <= N; i++)
    for(j=1; j <= N; j++)
      if (Jogo[jogador][i][j] == 1) {
	Jogo[jogador][i][j] = HIDROAVIAO;
	n++;
      }
  return n/3;
}
	
int encouracados(int jogador){
  int i,j, c, n= 0;
  // primeiros a marcar
  // horizontal
  for(i=1; i<= N; i++)
    for(j=1; j<= N-3; j++)
      if (Jogo[jogador][i][j] == 1 && Jogo[jogador][i][j+1] == 1 &&
	  Jogo[jogador][i][j+2] == 1 && Jogo[jogador][i][j+3] == 1) {
	for(c=0; c<4; c++)
	  Jogo[jogador][i][j+c] = ENCOURACADO;
	n++;
      }
  // vertical
  for(i=1; i<= N-3; i++)
    for(j=1; j<= N; j++)
      if (Jogo[jogador][i][j] == 1 && Jogo[jogador][i+1][j] == 1 &&
	  Jogo[jogador][i+2][j] == 1 &&	Jogo[jogador][i+3][j] == 1) {
	for(c=0; c<4; c++)
	  Jogo[jogador][i+c][j] = ENCOURACADO;
	n++;
      }

  return n;
}

int portaAvioes(int jogador){
  // assume aqui que encouracados foram marcados primeiro
  int i, j, c, l, n= 0;

  // horizontal
  for(i=1; i<= N; i++)
    for(j=1; j<= N-2; j++)
      if (Jogo[jogador][i][j] == 1 && Jogo[jogador][i][j+1] == 1 &&
	  Jogo[jogador][i][j+2] == 1) {
	for(c=0; c<3; c++)
	  Jogo[jogador][i][j+c] = PORTAAVIAO;
	if (Jogo[jogador][i-1][j] == 1) {
	  Jogo[jogador][i-1][j] = PORTAAVIAO;
	  Jogo[jogador][i+1][j] = PORTAAVIAO;
	} else if(Jogo[jogador][i-1][j+2] == 1) {
	  Jogo[jogador][i-1][j+2] = PORTAAVIAO;
	  Jogo[jogador][i+1][j+2] = PORTAAVIAO;
	} else if (Jogo[jogador][i-1][j+1] == 1) {
	  Jogo[jogador][i-1][j+1] = PORTAAVIAO;
	  Jogo[jogador][i-2][j+1] = PORTAAVIAO;
	} else { // Jogo[jogador][i+1][j+1] == 1) {
	  Jogo[jogador][i+1][j+1] = PORTAAVIAO;
	  Jogo[jogador][i+2][j+1] = PORTAAVIAO;
	}
	n++;
      }
  return n;
}

int submarinos(int jogador) 
{ 
  int i,j, ok, l, c, n= 0;

  for(i=1; i<= N; i++)
    for(j=1; j<= N; j++)
      if (Jogo[jogador][i][j] == 1) {
	ok = 0;
	for(l=0; l<3; l++)
	  for(c=0; c<3; c++)
	    ok += Jogo[jogador][i-1+l][j-1+c];
	if (ok == 1) {
	  Jogo[jogador][i][j] = SUBMARINO;
	  n++;
	}
      }
  return n;
}

int cruzadores(int jogador) 
{ 
  int i,j, ok, l, c, n= 0;
  // assume que marcou ja porta-avioes e encouracados
  // adjacencia horizontal (vertical) sera cruzador!!
  // horizontal
  for(i=1; i<= N; i++)
    for(j=1; j< N; j++)
      if (Jogo[jogador][i][j] == 1 && Jogo[jogador][i][j+1] == 1) {
	Jogo[jogador][i][j] = CRUZADOR;
	Jogo[jogador][i][j+1] = CRUZADOR;
	n++;
      }
  
  // vertical
  for(i=1; i< N; i++)
    for(j=1; j<= N; j++)
      if (Jogo[jogador][i][j] == 1 && Jogo[jogador][i+1][j] == 1) {
	Jogo[jogador][i][j] = CRUZADOR;
	Jogo[jogador][i+1][j] = CRUZADOR;
	n++;
      }

  return n;
}

void ler_jogada(int jogada[])
{
  int i;
  for(i=0;i<6;i++)
    scanf("%d",&jogada[i]);
}

int jogada_valida(int jogada[],int jogador)
{
  int i, adversario = (jogador+1)%2;
  for (i=0; i< 6; i += 2)
    if (Jogo[adversario][jogada[i]][jogada[i+1]] == TIRO)
      return 0;
  return 1;
}



void processar_jogada(int jogador,int jogada[],int total[]) {
  int ctipos[5]={0}, agua=0, i, l, c, adversario = (jogador+1)%2;
  for(i=0;i<6; i+=2) {
    l = jogada[i];
    c = jogada[i+1];
    if(Jogo[adversario][l][c] == 0) agua++;
    else ctipos[Jogo[adversario][l][c]-2]++;
    Jogo[adversario][l][c] = TIRO;
  }
  if (agua == 3)
    printf("Jogador %d: Agua\n",jogador+1);
  else {
    printf("Jogador %d:",jogador+1);
    for(i=0;i<5;i++)
      if(ctipos[i] != 0)
	printf(" %c%d",Tipos[i],ctipos[i]);
    printf("\n");
    total[jogador] -= (3-agua);
    if(total[jogador]==0) 
      printf("Venceu o jogador %d\n",jogador+1);
  }
}
  
int main() {
  int i, j, jogador, m, jogada[6], total[2];

  // bordo livre (por conveniencia)
  for (j=0; j < N; j++) {
    Jogo[0][0][j] = Jogo[1][0][j] = 0;
    Jogo[0][N-1][j] = Jogo[1][N-1][j] = 0;
    Jogo[0][j][0] = Jogo[1][j][0] = 0;
    Jogo[0][j][N-1] = Jogo[1][j][N-1] = 0;
  };

  // leitura dos jogos
  for(i=1; i <= N;i++) 
    for(jogador=0; jogador < 2; jogador++)
      for(j=1; j<= N; j++)
	scanf("%d",&Jogo[jogador][i][j]);

  // identificar frota 
  marcar_frota(total);

  // processar jogadas

  jogador = 0;
  scanf("%d",&m);
  while (m-- > 0) {
    ler_jogada(jogada);
    if (jogada_valida(jogada,jogador)) {
      processar_jogada(jogador,jogada,total);
      jogador = (jogador+1)%2;
    }
    else printf("Jogador %d: Invalida\n",jogador+1);
  }
  return 0;
}



