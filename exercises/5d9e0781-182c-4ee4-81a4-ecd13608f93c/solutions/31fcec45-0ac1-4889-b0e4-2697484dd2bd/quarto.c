/*
  Solução de problema Quarto.
  Pedro Vasconcelos, 2010
 */
#include <stdio.h>
#include <stdlib.h>

#define PECA     1
#define COR      2
#define ALTURA   4
#define FORMA    8
#define CONSISTE 16

int board[4][4];  

int main() {
  getboard();
  if(verifica()) printf("QUARTO\n"); else printf("NADA\n");
  exit(0);
}


int verifica(void) {
  int i, j, q, p;

  for (i=0; i<4; i++) {
    /* linhas */
    q = 0;
    p = PECA|COR|ALTURA|FORMA|CONSISTE;
    for (j=0; j<4; j++) {
      q |= board[i][j];
      p &= board[i][j];
    }
    if (testa(p,q)) return 1;

    /* colunas */
    q = 0;
    p = PECA|COR|ALTURA|FORMA|CONSISTE;
    for (j=0; j<4; j++) {
      q |= board[j][i];
      p &= board[j][i];
    }
    if (testa(p,q)) return 1;
  }

  /* diagonais */
  q = 0;
  p = PECA|COR|ALTURA|FORMA|CONSISTE;
  for (i=0; i<4; i++) {
      q |= board[i][i];
      p &= board[i][i];    
  }
  if (testa(p,q)) return 1;

  q = 0;
  p = PECA|COR|ALTURA|FORMA|CONSISTE;
  for (i=0; i<4; i++) {
      q |= board[3-i][i];
      p &= board[3-i][i];    
  }
  return  testa(p,q);
}


int testa(int conj, int disj)  {
  return ((conj&PECA) && 
	  (conj&(~PECA) || (~disj)&(COR|ALTURA|FORMA|CONSISTE)));
}



/* rotinas de leitura  */

void one(int c) {
  int x = getchar();
  if (x==c) return;
  fprintf(stderr, "esperava %c, obtive %c\n", c,x);
  exit(-1);
}

int oneof(char t, char f) {
  int c = getchar();
  if (c==t) return 1;
  if (c==f) return 0;

  fprintf(stderr, "esperava %c ou %c, obtive %c\n", t,f,c);
  exit(-1);
}

int getpiece(void) {
  /* preta ou branca, baixa ou alta, redonda ou quadrada, oca ou sólida */
  return ( PECA |
	  (oneof('P','B') << 1) |
	  (oneof('a','A') << 2) |
	  (oneof('R','Q') << 3) |
	  (oneof('O','S') << 4));
}

int getboard(void) {
  int i, j, c;
  for (i=0; i<4; i++) {
    for (j=0; j<4; j++) {
      c = getchar();
      if (c=='-') {
	one('-'); one('-'); one('-');
	board[i][j] = 0;
      }
      else {
	ungetc(c, stdin);
	board[i][j] = getpiece();
      }
    }
    one('\n');
  }
}


