#include <stdio.h>
#include <stdlib.h>


int main()
{
  int q[6] = {200,100,50,20,10,5};
  int n[6], i, ntrans = 0, euros, cent, aux, pagar;
  int troco, moeda, nlesados = 0, retem = 0;

  for (i=0; i< 6; i++)
    scanf("%d",&n[i]);

  scanf("%d %d",&euros,&cent);
  pagar = euros*100+cent;
  while (pagar) {
    ntrans++;
    troco = 0;
    scanf("%d",&moeda);
    while (moeda) {
      if (moeda < 5) moeda *= 100;
      troco += moeda;
      switch(moeda) {
      case 200: n[0]++; break;
      case 100: n[1]++; break;
      case 50: n[2]++; break;
      case 20: n[3]++; break;
      case 10: n[4]++; break;
      default: n[5]++;
      }
      scanf("%d",&moeda);
    }
    if ( (troco -= pagar) < 0) return 1; 
    for (moeda = 0; troco &&  moeda < 6; moeda++) {
      aux = troco/q[moeda];
      if (aux > n[moeda]) aux = n[moeda];
      troco -= aux*q[moeda];
      n[moeda] -= aux;
    }
    if (troco) {
      nlesados++; retem += troco;
    }
    scanf("%d %d",&euros,&cent);
    pagar = euros*100+cent;
  }
  printf("%d %d\n%d/%d\n",retem/100,retem%100,nlesados,ntrans);
  return 0;
}
