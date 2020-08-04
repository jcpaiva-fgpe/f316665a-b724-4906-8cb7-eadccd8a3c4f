#include <stdio.h>

#define MAXCADEIRAS 3
#define DUR 1
#define HORA 0

#define MAXIMO(A,B) ((A) > (B)? (A): (B))

// hora fecho almoco
#define FECHOA 180
// hora abre tarde
#define ABRET 360
// hora fecho tarde
#define FECHOT 600

int main()
{
  int n, i, thora, tmin, dur, nfila = 0, time;
  int barbeirolivre = 0, perde = 0, fila[MAXCADEIRAS][2];

  scanf("%d",&n);

  while(n > 0) {
    n--;
    scanf("%d %d %d",&thora,&tmin,&dur);
    time = (thora-9)*60+tmin;
    if ( (time >=0 && time <= FECHOA) || (time >= ABRET && time <= FECHOT)) { 
      while (barbeirolivre <= time && nfila) {
	barbeirolivre = MAXIMO(barbeirolivre,fila[0][HORA])+fila[0][DUR];
	for (i=1; i<nfila; i++) {
	  fila[i-1][HORA] = fila[i][HORA];
	  fila[i-1][DUR] = fila[i][DUR];
	}
	nfila--;
      }
      if (barbeirolivre <= time) 
	barbeirolivre = time+dur;
      else if (nfila < MAXCADEIRAS) {
	fila[nfila][HORA]=time;
	fila[nfila][DUR]=dur;
	nfila++;
      } else perde++;
    } else perde++;
  } 
  printf("Perdeu = %d\n",perde);
  return 0;
}

