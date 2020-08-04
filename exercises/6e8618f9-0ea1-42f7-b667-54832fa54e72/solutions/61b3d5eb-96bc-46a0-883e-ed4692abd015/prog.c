#include <stdio.h>


int main()
{
  int a[100], max, c, aux, n, i, inicio;

  scanf("%d",&n);
  for (i = 0; i < n; i++)
    scanf("%d",&a[i]);

  inicio = 0;
  max = 0;
  while (inicio < n) {
    i = inicio; c = 0;
    do {
      c++;
      aux = i; // printf("%d ",a[i]);
      i = a[i]-1; 
      a[aux] = -1;
    } while (i != inicio);
    if (c > max) max = c;
    inicio++;
    while(inicio < n && a[inicio] == -1) inicio++;
  }
  printf("%d\n", max);   // para qualquer incluindo com 1 e 2
  return 0;
}
