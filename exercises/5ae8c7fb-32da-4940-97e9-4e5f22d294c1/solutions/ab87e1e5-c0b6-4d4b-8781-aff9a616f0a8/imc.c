#include <stdio.h>

int main(){
  int peso, altura;
  double imc;

  scanf("%d %d", &peso, &altura);
  imc = (double)(1000 * peso) / (double)(altura * altura);
    if (imc < 18.5) {
      printf("baixo peso\n");
    } else if(imc < 25) {
      printf("normal\n");
    } else if(imc < 30) {
      printf("pré obesidade\n");
    } else if(imc < 35) {
      printf("obesidade de grau I\n");
    } else if(imc < 40) {
      printf("obesidade de grau II\n");
    } else {
      printf("obesidade de grau III\n");
    }

    return 0;
}
