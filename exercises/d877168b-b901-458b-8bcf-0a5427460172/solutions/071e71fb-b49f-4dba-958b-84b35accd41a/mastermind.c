
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100
char key[SIZE+1], guess[SIZE+1];


/* letras correctas na posição correcta */
int correct_pos(char *key, char *guess) {
  int n = 0;
  while (*key && *guess) {
    if (*key == *guess) n++;
    key++;
    guess++;
  }
  return n;
}


/* contar o número de ocorrencias */
int count(char c, char *str) {
  int n = 0;
  while (*str) {
    if (*str == c) n++;
    str++;
  }
  return n;
}

int min(int a, int b) {
  return (a<=b ? a : b);
}

/* letras correctas em qualquer posição */
int correct_any(char *key, char *guess) {
  int n=0, c;

  /* contar letras de 'a'..'f' */
  for (c='a'; c<='f'; c++) {
    n += min(count(c,key), count(c,guess));
  }
  return n;
}


/* remove trailing newline */
void trim(char *str) {
  int len = strlen(str);
  str[len-1] = 0;
}

int main () {
  int s1, s2;

  if (fgets(key, SIZE, stdin) == NULL ||
      fgets(guess, SIZE, stdin) == NULL) 
    exit(-1);

  trim(key);
  trim(guess);
  
  s1 = correct_pos(key, guess);
  s2 = correct_any(key, guess);

  printf("%d\n%d\n", s1, s2-s1);
  exit(0);
}
