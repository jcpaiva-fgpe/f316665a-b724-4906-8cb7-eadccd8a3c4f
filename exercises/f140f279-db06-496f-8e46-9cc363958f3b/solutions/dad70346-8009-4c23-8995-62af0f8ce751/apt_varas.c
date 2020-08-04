// by apt
#include <stdio.h>

int main() 
{
  int polegadas = 0, c[8] = {80,72,60,40,24,12,8,1}, n, i;

  for(i=0;i<8;i++){
    scanf("%d",&n);
    polegadas += n*c[i];
  }

  printf("%d %d %d\n",polegadas/40,(polegadas%40)/8,(polegadas%40)%8);
  return 0;
}
