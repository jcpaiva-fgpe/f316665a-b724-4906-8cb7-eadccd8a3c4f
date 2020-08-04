#include <stdio.h>

#define MAX 100
//#define DEBUG


void ler_matriz(int m,int n);
int pos_final();
void vira_direita(int pos[]);
void vira_esquerda(int pos[]);
void avancar_um();
int recolhe_baloes();
void procura_porta();
char vizinho_parede(int pos[]);

int Sentido[2], Pos[2];
char Planta[MAX][MAX];


void ler_matriz(int m,int n) {
  int i, j;
  for (i=m-1; i >= 0; i--) {
    for (j=0; j<n; j++)
      Planta[i][j] = getchar();
    getchar();
  }
}


int pos_final() {
  return (Planta[Pos[0]][Pos[1]] == 'S' || Planta[Pos[0]][Pos[1]] == 'Y');
  // 'Y' significa porta bloqueada
}

void vira_direita(int pos[]) {
  if (pos[0] == 0) {
    pos[0] = -pos[1];
    pos[1] = 0;
  }  else {
    pos[1] = pos[0];
    pos[0] = 0;
  }
}

void vira_esquerda(int pos[]) {
  if (pos[0] == 0) {
    pos[0] = pos[1];
    pos[1] = 0;
  }  else {
    pos[1] = -pos[0];
    pos[0] = 0;
  }
}


void entra_sala() {
  Planta[Pos[0]][Pos[1]] = 'Y';  // bloqueia porta

  // posicao entrada
  Pos[0] = Pos[0]+Sentido[0];
  Pos[1] = Pos[1]+Sentido[1];
  
  // adjusta sentido do movimento (vira direita porque pode)
  vira_direita(Sentido);
}

#ifdef DEBUG
void escrMat(int m,int n) {
  int i, j;
  for(i=m-1; i >=0; i--) {
    for(j=0;j<n;j++)
      printf("%c", Planta[i][j]);
    putchar('\n');
  }
}
#endif


int main() 
{
  int m, n, baloes, pos0, pos1, sentido0, sentido1;

  scanf("%d %d",&m,&n);
  getchar();

  ler_matriz(m,n);

  Pos[0] = 0; Pos[1] = 2;  // entrada
  Sentido[0] = 1; Sentido[1] = 0; 
  baloes = 0;

  do {

    entra_sala();
#ifdef DEBUG
    printf("\nantes de recolha\n");
    escrMat(m,n); 
#endif

    // guarda estado
    pos0 = Pos[0]; pos1 = Pos[1];
    sentido0 = Sentido[0]; 
    sentido1 = Sentido[1];

    baloes += recolhe_baloes();

#ifdef DEBUG
    printf("\ndepois de recolha\n");
    escrMat(m,n);
#endif

    // repor estado
    Pos[0] = pos0; Pos[1] = pos1;
    Sentido[0] = sentido0; 
    Sentido[1] = sentido1; 

    procura_porta();

  } while (!pos_final());

  printf("%d\n",baloes);
  if (Planta[Pos[0]][Pos[1]] == 'S')
    printf("Levantou voo\n");
  else 
    printf("Veio para ficar\n");

  return 0;
}

int recolhe_baloes() {
  int pos0, pos1, baloes = 0;

  pos0 = Pos[0];
  pos1 = Pos[1];

  do {
    avancar_um();
    if (Planta[Pos[0]][Pos[1]] == 'B')  {
      Planta[Pos[0]][Pos[1]] = ' ';
      baloes++;
    }
  } while (Pos[0] != pos0 || Pos[1] != pos1);

  return baloes;
}



void procura_porta() {
  int posViz[2];
  char cv;

  // na posicao livre acima da porta bloqueada e pronto para avancar

  do {
    avancar_um();
  } while ((cv=vizinho_parede(posViz)) == 'X');

  Sentido[0] = posViz[0]-Pos[0];
  Sentido[1] = posViz[1]-Pos[1];
  Pos[0] = posViz[0];
  Pos[1] = posViz[1];
}


void avancar_um(){
  int pos0, pos1;
  char c;
  
  pos0 = Pos[0]+Sentido[0];
  pos1 = Pos[1]+Sentido[1];

  c = Planta[pos0][pos1];
  if (c == ' ' || c == 'B') {
    Pos[0] = pos0;
    Pos[1] = pos1;
  } else {
    vira_esquerda(Sentido); // mudar sentido
    Pos[0] = Pos[0]+Sentido[0];
    Pos[1] = Pos[1]+Sentido[1];
  }
}


char vizinho_parede(int posViz[]) {
  int sentido[2];
  sentido[0] = Sentido[0];
  sentido[1] = Sentido[1];
  vira_direita(sentido);
  posViz[0] = Pos[0]+ sentido[0];
  posViz[1] = Pos[1]+ sentido[1];

  return Planta[posViz[0]][posViz[1]];
}
