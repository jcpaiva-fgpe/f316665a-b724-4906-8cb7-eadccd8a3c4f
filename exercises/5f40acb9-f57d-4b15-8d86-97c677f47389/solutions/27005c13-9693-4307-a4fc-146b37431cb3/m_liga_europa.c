#include <stdio.h>

// liga_europa, por pedro guerreiro, estilo topas.

int main (void)
{
  //---- mv by apt
  char equipa1[80];
  char equipa2[80];
  int x1, y1, x2, y2; // x golos em casa, y golos fora
  //---------------
  scanf ("%s%s", equipa1, equipa2);
  scanf ("%d%d", &x1, &y1);
  scanf ("%d%d", &x2, &y2);
  if (x1 + y2 > x2 + y1) 
    printf ("%s\n", equipa1);
  else if (x1 + y2 < x2 + y1) 
    printf ("%s\n", equipa2);
  // x1 + y2 == x2 + y1
  else if (y2 > y1)
    printf ("%s\n", equipa1);
  else if (y1 > y2)
    printf ("%s\n", equipa2);
  // x1 + y2 == x2 + y1 && y1 == y2
  else
    printf ("%s\n", "penaltis");
  return 0;
}
      
