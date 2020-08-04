#include <stdio.h>

#define MAXL 30

void my_getline(char linha[]);

void my_getline(char linha[]) {
  int i=-1;
  do {
    i++;
    linha[i] = getchar();
  } while (linha[i] != '\n');
  linha[i] = '\0';
}

void traduz(char linha[]){
  if (linha[0] == 'b' || linha[0] == 'c')
    printf("%s\n", linha);
  else if (linha[0] == 'i')
    printf("clap your hands\n");
  else
    printf("bata palmas\n");
}

int main() {
  char linha[MAXL];
  my_getline(linha);
  traduz(linha);
  my_getline(linha);
  traduz(linha);
  return 0;
}
