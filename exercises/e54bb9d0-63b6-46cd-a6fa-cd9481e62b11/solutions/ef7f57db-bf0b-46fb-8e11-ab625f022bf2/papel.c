/*
  Solução do problema Pedra, Papel, Tesoura

  Pedro Vasconcelos, 2010
*/
#include <stdio.h>
#include <stdlib.h>

#define TAM 10

char jogada1[TAM+1];
char jogada2[TAM+1];


int ganha(int c) {
  switch (c) {
  case 'R': return 'P';
  case 'P': return 'T';
  case 'T': return 'R';
  }
}

int main() {
  int i, p1, p2;
  scanf("%s\n%s", jogada1, jogada2);

  p1 = 0;
  p2 = 0;
  
  for (i=0; i<TAM; i++) {
    if(jogada1[i] == ganha(jogada2[i]))
      p1 ++;
    else if (jogada2[i]==ganha (jogada1[i]))
      p2++;
  }

  printf("%d\n%d\n", p1, p2);
  exit(0);
}
