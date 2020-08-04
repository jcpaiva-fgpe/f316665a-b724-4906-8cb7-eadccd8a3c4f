
# include <stdlib.h>
# include <stdio.h>

int main() {

int tecla, anterior, repete;
 
char letra[10][5] = {
  {'?', '+', '?', '?', '?'},
  {'?', '_', '?', '?', '?'},
  {'?', 'A', 'B', 'C', '?'},
  { '?', 'D', 'E', 'F', '?'},
  { '?', 'G', 'H', 'I', '?'},
  { '?', 'J', 'K', 'L', '?'},
  { '?', 'M', 'N', 'O', '?'},
  {'?', 'P', 'Q', 'R', 'S'},
  { '?', 'T', 'U', 'V', '?'},
  {'?', 'W', 'X', 'Y', 'Z'}    

  };


  scanf("%d",&anterior);
  repete=1;
  while(scanf("%d",&tecla) && tecla != 99) {
    if(tecla == anterior)
      repete++;
    else {
      if(anterior!=77)
	printf("%c",letra[anterior][repete]);
      anterior=tecla;
      repete=1;
    }
  }
  if(anterior!=77)
    printf("%c",letra[anterior][repete]);
  printf("\n");

  return (0);
  
}
