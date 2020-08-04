#include <stdio.h>
#include <stdlib.h>


int main()
{ 
  int n, azul = 0, verde = 0, amarelo = 0;

  scanf("%d",&n);
  while(n != -1) {
    if (n >= 1 && n <= 10) azul++;
    else if( n >= 11 && n <= 23) verde++;
    else  if( n <=40 &&  n >= 24) amarelo++;
    else { printf("BAD fic\n"); exit(1);}
    scanf("%d",&n);
  }
  
  printf("azul: %d\namarelo: %d\nverde: %d\n", azul,amarelo,verde);
  return 0;
}
