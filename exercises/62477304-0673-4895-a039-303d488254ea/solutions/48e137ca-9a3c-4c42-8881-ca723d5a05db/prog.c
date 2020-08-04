#include <stdio.h>


int main()
{
  int locais[30], prox, fim, i;

  scanf("%d",&locais[0]);

  fim = 1;

  scanf("%d",&prox);
  do {
    for (i=0; i<fim; i++)
      if (prox == locais[i]) {
	fim = i;
	break;
      } 
    locais[fim++] = prox;
    scanf("%d",&prox);
  } while (prox != 0);

  for (i=0; i<fim; i++)
    printf("%d\n",locais[i]);
  return 0;
}
