#include <stdio.h>

// gasolina, por pedro guerreiro, estilo topas.

int prezo [8];
int n_semanas;
int cont;

int main (void)
{
  int i, j;
  int n;
  scanf ("%d", &n_semanas);
  scanf ("%d", &prezo[7]);
  cont = 0;
  for (i = 0; i < n_semanas; i++)
  {
    prezo [0] = prezo [7];
    for (j = 1; j <= 7; j++)
      scanf ("%d", &prezo[j]);
    n = 0;
    for (j = 0; j < 7; j++)
      if (prezo[j] < prezo [j+1])
        n++;
    if (n > 0)
      cont++;
  }
  printf ("%d\n", cont);
  return 0;
}
