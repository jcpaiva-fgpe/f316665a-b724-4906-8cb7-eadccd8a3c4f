#include <stdio.h>

#define FALSE 0
#define TRUE 1

int v[10];

int preco_ok(int quantia,int nmoedas,int n){
  int nmin, i;   // moeda mais alta

  if (quantia == 0) return TRUE;

  nmin = quantia/v[n];

  if (nmin > nmoedas) return FALSE;
  if (nmin == nmoedas) {
    if (quantia%v[n] == 0) return TRUE;
    return FALSE;
  }

  // nmin < nmoedas

  for (i = nmin; i > 0; i--) 
    if (preco_ok(quantia-v[n]*i, nmoedas-i,n)) return TRUE;

  if (n!=0)  return preco_ok(quantia, nmoedas,n-1);
  return FALSE;
}
  

int main() {
   
  int quantia, n, i;

  scanf("%d",&quantia);
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&v[i]);

  while (!preco_ok(quantia,4,n-1)) quantia++;
  
  printf("%d\n",quantia);
  return 0;
}


    
