#include <stdio.h>

char *msg[5] = {"GOOD LUCK", "BUENA SUERTE", "BONNE CHANCE", "BUONA FORTUNA","VIEL GLUECK"};

int main()
{
  int n, l;
  scanf("%d %d",&n,&l);

  while(n-- > 0) 
    printf("%s\n",msg[l-1]);

  return 0;
}
