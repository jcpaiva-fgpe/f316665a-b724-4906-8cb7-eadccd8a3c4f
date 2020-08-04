#include<stdio.h>

int main(){
  int i, max =0, ndig=0, nrep, cmax= 0, cdig=-1, d;

  scanf("%d\n", &nrep);
  for (i=0;i< nrep;i++) {
    scanf("%d",&d);
    if (d == cdig) 
      ndig++;
    else {
      if (ndig > max) {
	max = ndig;
	cmax = cdig;
      }
      ndig = 1;
      cdig = d;
    }
  } 
  if (ndig > max) {
    max = ndig;
    cmax = cdig;
  }
  printf("%d %d\n",cmax,max);

  return 0;
}
