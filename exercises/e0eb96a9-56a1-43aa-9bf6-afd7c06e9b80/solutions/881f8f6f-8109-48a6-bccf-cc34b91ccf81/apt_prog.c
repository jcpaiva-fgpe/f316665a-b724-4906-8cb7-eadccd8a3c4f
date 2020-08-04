// apt

#include <stdio.h>

#define MAXCHARS 40+1

int converte(char seq[]);

int main(){
  char seq[MAXCHARS];
  int maxseq=0, nova, nvals=0;

  scanf("%s",seq);
  nova = converte(seq);
  while(nova != 0) {
    if (nova != -1) { 
      nvals++;
      if(nova > maxseq) 
	maxseq = nova;
    }
    printf("%d %d\n",maxseq,nvals);
    scanf("%s",seq);
    nova = converte(seq);
  }
  return 0;
}

int converte(char seq[]){
  int i=0, j, v, valor=0;

  for(i=0; seq[i] != '\0'; i += 5) {
    v = 0;
    for(j=0; j<= 4 && seq[i+j] == '.'; j++)
      v++;

    if(v != 0) {
      for(; j<= 4 && seq[i+j] == '-'; j++);
      if (j != 5) return -1;
    } else {
      // v == 0
      for(; j<= 4 && seq[i+j] == '-'; j++);
      if (j != 5) {
	for(; j<= 4 && seq[i+j] == '.'; j++)
	  v++;
	if (j < 5) return -1;
	v = 10-v;
      }
    }
    valor = valor*10+v;
  }
  
  return valor;
}
	
