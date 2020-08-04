/*
                TOPAS'2007
---------------------------------------------
      Bart e a Matematica (Pedro Ribeiro)
---------------------------------------------
Solucao o mais bruta possivel
 - ver se um numero e primo
   . para saber se e primo, dividir por todos ate
     ao numero (nem sequer parar na raiz quadrada)
 - se for primo, ver se divide o outro numero
   . nem sequer ver se divide primeiro
 - se dividir, escrever
---------------------------------------------
*/
#include <stdio.h>

int isprime(int n) {
  int i;
  for (i=2;i<n;i++)
    if (n%i == 0) return 0;
  return 1;
}

void factorize(int n) {
  int i, first=1;
  
  printf("%d = ",n);

  for (i=2; i<=n; i++) {
    if (isprime(i) && n%i==0) {
      if (first) first = 0;
      else putchar('*');
      printf("%d",i);
      n /= i; i--;
    }
  }

  putchar('\n');
}

int main() {
  int i,ncases,num;

  scanf("%d",&ncases);
  for (i=0; i<ncases; i++) {
    scanf("%d",&num);
    factorize(num);
  }

  return 0;
}
