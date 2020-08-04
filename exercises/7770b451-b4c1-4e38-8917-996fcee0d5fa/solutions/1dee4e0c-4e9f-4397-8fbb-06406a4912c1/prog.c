#include <stdio.h>

#define MAXFILA 50

int Fila[MAXFILA], NFila;

#define LUGAR(L) ((L) >= 0 && (L)<NFila)

void sentar(int delta,int id,int ng,int lugar);
int move_sentar(int delta,int n,int ng,int id, int lugar);
void sentar_extremidade(int delta,int id, int ng);
void prefere(int delta,int id,int ng, int lugar);
int talvez_sentar(int delta,int ng, int *lug_ca);


void sentar(int delta,int id,int ng,int lugar)
{ // para esquerda  delta = -1 ; direita é 1
  while (ng) {
    Fila[lugar+delta*(ng-1)]=id;
    ng--;
  }
}


int talvez_sentar(int delta,int ng, int *lug_ca)
{ int n=0, faltam, inicio, k;
  if (delta == -1) inicio = 0;
  else inicio = NFila-1;

  faltam = ng; k=0, n=0;
  do {
    while (Fila[inicio-k*delta] != 0) {n++;k++;}
    faltam--; k++;
  } while (faltam);
  *lug_ca = inicio-(k-1)*delta;
  return n;
}


int move_sentar(int n, int delta,int id,int ng, int lugar)
{ 
  int vazio = lugar;
  do {
    while (Fila[lugar] == 0) lugar += delta;
    Fila[vazio] = Fila[lugar];
    vazio += delta; 
    lugar += delta;    
    n--;
  } while (n!= 0);
  if (delta == 1) sentar(delta,id,ng,NFila-ng);
  else sentar(delta,id,ng,ng-1);
}

void sentar_extremidade(int delta,int id, int ng)
{
  int n_ca, n_la,lug_ca,lug_la;
  n_ca = talvez_sentar(delta,ng,&lug_ca);
  n_la = talvez_sentar(-delta,ng,&lug_la);

  if (n_ca <= n_la) 
     if (n_ca == 0) sentar(delta,id,ng,lug_ca);
     else move_sentar(n_ca,delta,id,ng,lug_ca);
  else 
     if (n_la == 0) sentar(-delta,id,ng,lug_la);
     else  move_sentar(n_la,-delta,id,ng,lug_la);
}

void prefere(int delta,int id,int ng, int lugar)
{
  int i, k;

  for (i=0; i < ng && LUGAR(lugar+delta*i) && Fila[lugar+delta*i] == 0; i++);
  if (i == ng) sentar(delta,id,ng,lugar);
  else {
   for (k=1; k<=ng-i && LUGAR(lugar-delta*k) && Fila[lugar-delta*k]==0; k++);
    if (k > ng-i) sentar(delta,id,ng,lugar-delta*(ng-i));
    else sentar_extremidade(delta,id,ng);
    // sem ser eficiente!!!
  }
}

int main()
{
  int ng, lug, lado, quer,nlivres,id,i;
  
  scanf("%d",&NFila);

  for (i=0; i < NFila; i++) Fila[i] = 0;

  scanf("%d %d %d",&lado,&ng,&lug);
  nlivres = NFila; id = 1;

  while (ng != 0 || lug != 0 || lado != 0) {
    if (ng <= nlivres) {
      if (ng == 1) {
	if (lado == 0) Fila[lug-1] = id; // livre sempre
        else Fila[NFila-lug] = id; // livre sempre
      } else {
   	if (lado == 0) prefere(-1,id,ng,lug-1);
        else prefere(1,id,ng,NFila-lug);
      }
      nlivres -= ng;
    }
    id++;
    scanf("%d %d %d",&lado,&ng,&lug);
  }
  
  // output
  for (i=0; i<NFila; i++)
    if (Fila[i]) printf("%d\n",Fila[i]);
    else printf("-\n");
  
  return 0;
}
