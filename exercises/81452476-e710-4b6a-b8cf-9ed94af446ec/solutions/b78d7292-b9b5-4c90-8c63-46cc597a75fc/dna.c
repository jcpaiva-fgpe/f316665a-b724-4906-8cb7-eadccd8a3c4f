#include<stdio.h>
#include<stdlib.h>

/* para gerar casos de teste */
void gera(int max)
{
  int i, k;

  srandom(234556);  /* para o que é server :) */
 
  for(i=0;i<max;i++) {
    k=random()%3;
    if (k==0) printf("a\n");
    if (k==1) printf("c\n");
    if (k==2) printf("t\n");
  }

  printf("#\n");
  exit(0);
}


#define ABS(X)  ((X)>= 0? (X):(-(X)))

int main(int v1, char **v2) {
  char c,velho;

  // if (v1>1) gera(atoi(v2[1])); 
  

  c = getchar();
  putchar(c); putchar('\n');
  getchar(); velho = c;
  while((c=getchar())!='#') {
    if (velho==c) {
      printf("%c\n",c);
    } else if (ABS(velho-c)=='c'-'a') {
      printf("t\n");
    } else if (ABS(velho-c)=='t'-'c') {
      printf("a\n");
    } else printf("c\n");
    velho = c;
    getchar();
  }
  return 0;
}

