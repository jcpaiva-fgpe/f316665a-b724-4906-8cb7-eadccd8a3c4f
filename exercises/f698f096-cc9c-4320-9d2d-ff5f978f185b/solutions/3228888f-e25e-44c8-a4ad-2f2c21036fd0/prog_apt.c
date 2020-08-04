/*
  apt - 4 Maio 2016
*/
  

#include <stdio.h>

int main() {
  int k, m, prev, curr;

  scanf("%d%d",&k,&m);
  prev = k*1000+m;
  scanf("%d%d",&k,&m);
  do {
    curr = k*1000+m;
    if (curr == prev) 
      printf("PATAMAR\n");
    else if (curr > prev) 
      printf("ALTO %d km %d m\n",(curr-prev)/1000,(curr-prev)%1000);
    else
      printf("BAIXO %d km %d m\n",(prev-curr)/1000,(prev-curr)%1000);
    prev = curr;
    scanf("%d%d",&k,&m);
  } while(k!=0 || m != 0);

  return 0;
}
