#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 9999
#define MAXL 99999
#define PROB 10
#define PROBT 50000

#define VERYLARGE


int main(){
  int n, c, i;

  srand((unsigned)time(NULL));

#ifdef VERYLARGE
/* for(i=0;i<MAXL-2;i++)  */
/*     printf("%d",1); */
/*   printf("00000"); */
/*   for(i=0;i<MAXL-1;i++)  */
/*     printf("%d",1); */
/*   printf("000000000"); */
/*   for(i=0;i<MAXL;i++)  */
/*     printf("%d",1); */
/*   printf("\n"); */
  printf("0");
  for(i=c=0;i<MAXL-1;i = 10000+i){
    for (n=0;n<=c;n++) printf("0");
    for(c=0;c<=i;c++) printf("1");
  }
#endif


#ifndef VERYLARGE
  for(i=0;i<MAXL;i++) 
    printf("%d",rand()%PROB? 1:0);
#endif

  putchar('\n');
 
  printf("%d\n",N);
  for(i=0;i<N;i++)
    //    printf("%d\n",rand()%PROBT+99900);
    printf("%d\n",rand()%PROB+1000*(i%101));
  // printf("%d\n",rand()%PROBT+9999);

  return 0;
}
