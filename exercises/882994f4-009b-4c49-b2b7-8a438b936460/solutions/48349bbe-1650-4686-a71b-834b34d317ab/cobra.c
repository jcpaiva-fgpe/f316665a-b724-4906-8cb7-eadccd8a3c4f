#include <stdio.h>

#define MAX 100

void mostra_lab(char lab[MAX][MAX],int d);

int main() {
  char lab[MAX][MAX], lab2[MAX][MAX], caminho[MAX];
  int dimensao,casos, i,j, inicialx,inicialy,x,y, nr_ovos=0, ovos;

  scanf("%d\n",&dimensao);
  scanf("%d\n",&casos);

  for(i=0;i<dimensao;i++)
	fgets(lab[i],MAX,stdin);
  
  for(i=0;i<dimensao;i++) 
    for(j=0;j<dimensao;j++) {
      if (lab[i][j]=='C') { inicialx=j; inicialy=i; }
      if (lab[i][j]=='O') { nr_ovos++; }
    }
  
  while(casos>0) {
    memcpy(lab2,lab,MAX*MAX); /* copia lab para lab2 */
    
    fgets(caminho,MAX,stdin);
    x=inicialx; 
    y=inicialy;
    ovos=nr_ovos;
    i=0; 
    while(caminho[i]) {
      lab2[y][x]='.';
      switch(caminho[i]) {
        case 'e': x--;
    	          break;
        case 'd': x++;
    	          break;
        case 'b': y++;
    	          break;
        case 'c': y--;
    	          break;
      }
      if (x<0 || x>=dimensao || y<0 || y>=dimensao || lab2[y][x]=='#') {
	ovos=1; 
        break; 
      } else {
	if (lab2[y][x]=='O') ovos--;
        lab2[y][x]='C';
      }

      /*      mostra_lab(lab2,dimensao); */
      i++;
    }
    if (ovos==0 ) printf("SIM\n");
    else {
      /*      mostra_lab(lab2,dimensao); printf("falhou com a cobra em: %d %d\n",x,y); */
      printf("NAO\n");

    }

    casos--;
  }
    

}


void mostra_lab(char lab[MAX][MAX],int d) {
  int i,j;

  for(i=0;i<d;i++) {
    for(j=0;j<d;j++)
      printf("%c",lab[i][j]);
    printf("\n");
  }
 printf("\n");  
}
