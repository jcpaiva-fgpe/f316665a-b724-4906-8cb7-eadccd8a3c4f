#include <stdio.h>

#define MAXSET 100
#define MAXLUG 100000
#define FIM -1
#define INTERVALO  1
#define PONTO 0



void output(void);
int intervalo(int, int);
int ponto(int);
void shift_up(int);
void shift_down_insere(int,int,int,int);

int Set[MAXSET][3], NSet, Nlugares;



main()
{
  int tipo, a, b;
  NSet = Nlugares = 0;
  scanf("%d",&tipo);
  do {
    if(tipo == INTERVALO) {
      scanf("%d %d",&a,&b);
      Nlugares = intervalo(a,b);
    } else {
      scanf("%d",&a);
      Nlugares = ponto(a);
    }
    scanf("%d",&tipo);
  } while (Nlugares != 0 && tipo != FIM);
  output();
}

void output()
{ 
  int i;
  printf("%d\n",Nlugares);
  if (Nlugares) {
    i = 0;
    while(i < NSet) {
      if (Set[i][0]==INTERVALO) {
	printf("[%d,%d]\n",Set[i][1],Set[i][2]);
	i++;
      } else {
	printf("{%d",Set[i][1]);
	i++;
	while(i < NSet  && Set[i][0]==PONTO) {
	  printf(",%d",Set[i][1]);
	  i++;
	}
	printf("}\n");
      }
    }
  }
}


int intervalo(int a, int b)
{ 
  int i, nlug = Nlugares+(b-a+1);
  if (nlug > MAXLUG) return 0;

  for(i=0; i<NSet; i++) {
    if (Set[i][0] == PONTO) {
      if (a <= Set[i][1]) {
	if (Set[i][1] <= b) return 0;
	if (Set[i][1] == b+1) {
	  Set[i][0] = INTERVALO;
	  Set[i][1] = a; Set[i][2] = b+1;
	} else shift_down_insere(i,INTERVALO,a,b);
	return nlug;
      }
      if (a==Set[i][1]+1) {
	Set[i][0]=INTERVALO;
	if (i+1 < NSet) {
	  if (b >= Set[i+1][1]) return 0;
	  if (b == Set[i+1][1]-1) {
	    Set[i][2] = Set[i+1][2];
	    shift_up(i+1);
	    return nlug;
	  }
	}
	Set[i][2] = b;
	return nlug;
      }
    } else {  /* [ai,bi]*/
      if (b < Set[i][1]) {
	if (b == Set[i][1]-1)
	  Set[i][1] = a;
	else shift_down_insere(i,INTERVALO,a,b);
        return nlug;
      }
      if (b == Set[i][1] || a <= Set[i][2]) return 0;
      if (a == Set[i][2]+1) {
	if (i+1 < NSet) {
	  if (b >= Set[i+1][1]) return 0;
	  if (b == Set[i+1][1]-1) {
	    Set[i][2]=Set[i+1][2];
	    shift_up(i+1);
	    return nlug;
	  } 
	}
	Set[i][2] = b;
	return nlug;
      }
    }
  }
  Set[i][0] = INTERVALO;
  Set[i][1] = a;   Set[i][2] = b;
  NSet++;
  return nlug;
}


int ponto(int a)
{ 
  int i, nlug =  Nlugares+1;
  if (nlug > MAXLUG) return 0; 
  for(i=0; i<NSet; i++) {
    if (a < Set[i][1]) {
      if (a == Set[i][1]-1){
	Set[i][1] = a;
	Set[i][0] = INTERVALO;
      } else shift_down_insere(i,PONTO,a,a);
      return nlug;
    } else {
      if (a == Set[i][1]) return 0;
      if (a == Set[i][2]+1) {
	  Set[i][0] = INTERVALO;
	  if (i+1 < NSet) {
	    if (a == Set[i+1][1]-1) {
	      Set[i][2] = Set[i+1][2];
	      shift_up(i+1);
	      return nlug;
	    }
	  }
	  Set[i][2] = a;
	  return nlug;
      }
      if (a <= Set[i][2]) return 0;
    }
  }
  Set[i][0] = PONTO;
  Set[i][1] = a;   Set[i][2] = a;
  NSet++;
  return nlug;
}

	      
      
void shift_down_insere(int i,int tipo, int a,int b)
{
  int j=NSet;
  while(j != i) {
    Set[j][0]= Set[j-1][0];
    Set[j][1]= Set[j-1][1];
    Set[j][2]= Set[j-1][2];
    j--;
  }
  Set[j][0]=tipo;
  Set[j][1]=a;
  Set[j][2]=b;
  NSet++;
}


void shift_up(int livre)
{ 
  while(livre+1 < NSet) {
    Set[livre][0] = Set[livre+1][0];
    Set[livre][1] = Set[livre+1][1];
    Set[livre][2] = Set[livre+1][2];
    livre++;
  }
  NSet--;
}
