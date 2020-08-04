#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NMAX 9999
#define TMAX 99999


int main(){
  int t, c, n, max;

  do {
    while((c=getchar())=='1') t++;
    t = (t <= TMAX? t: TMAX);
    // re-escreve se nao valido
    while(t-- > 0) putchar('1');
    putchar(c);
  } while(c!='\n');

  scanf("%d",&n);
  if (n > NMAX) {
    fprintf(stderr,"erro\n");
    exit(1);
  }
  printf("%d\n",n);
  max = 0;
  while(n-- > 0) {
    scanf("%d",&c);
    if (max  < c) max = c;
    printf("%d\n",c);
  }
  fprintf(stderr,"echo max = %d\n", max);
  return(0);
}
