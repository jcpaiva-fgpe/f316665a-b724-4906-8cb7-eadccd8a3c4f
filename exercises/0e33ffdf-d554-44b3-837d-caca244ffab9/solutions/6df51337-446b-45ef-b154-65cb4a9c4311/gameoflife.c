/*
                TOPAS'2007
---------------------------------------------
      Jogo da Vida (Pedro Ribeiro)
---------------------------------------------
Solucao modelo nao optimizada de nenhum modo,
para garantir que solucao similar de alunos
consegue passar.

Simplesmente manter duas matrizes em memoria
e em cada passo simular, passando por todos
os pontos e vendo o novo estado de cada celula.
---------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_DIM 105
#define N_GRID  2

#define LIVE '#'
#define DEAD '.'

char g[N_GRID][MAX_DIM][MAX_DIM];
int rows, cols, cycles;
int current, next;

void read_data() {
  int i;
  scanf("%d %d %d",&rows,&cols,&cycles);
  for (i=0; i<rows; i++)
    scanf("%s",g[0][i]);
}

void show_grid(int which) {
  int i,j;
  for (i=0;i<rows;i++) {
    for (j=0;j<cols;j++)
      putchar(g[which][i][j]);
    putchar('\n');
  }	
}

int valid(int y, int x) {
  if (y<0 || y>=rows || x<0 || x>=cols) return 0;
  return 1;
}


int count(int y, int x) {
  int i, j, aux = 0;
  for (i=y-1; i<=y+1; i++)
    for (j=x-1; j<=x+1; j++) 
      if (!(i==y && j==x) && valid(i,j) && g[current][i][j]==LIVE)
	aux++;
  return aux;
}

void simulate() {
  int i,j,aux;

  current = 0;

  while (cycles > 0) {
    next = 1 - current;
    for (i=0;i<rows;i++)
      for (j=0;j<cols;j++) {
	aux = count(i,j);
	if (aux == 3 || (aux==2 && g[current][i][j]==LIVE))
	  g[next][i][j] = LIVE;
	else
	  g[next][i][j] = DEAD;
      }
    current = next;
    cycles--;
  }
}

int main() {

  read_data();
  simulate();
  show_grid(current);

  return 0;
}
