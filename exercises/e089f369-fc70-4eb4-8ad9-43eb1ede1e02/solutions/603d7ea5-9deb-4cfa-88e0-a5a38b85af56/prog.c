#include <stdio.h>

#include <string.h>

#define MAXREGISTO 30

int foi_papagaio(char *registo);


int main()
{
  int n=0, min=0, max=0, npatas;
  char registo[MAXREGISTO];

  scanf("%d",&npatas);
  while (npatas) {
    n++;
    scanf("%s",registo);
    if (npatas == 2) {
      max++;
      min += foi_papagaio(registo);
    }
    scanf("%d",&npatas);
  }
  printf("%d %d %d\n",n,min,max);
  return 0;
}


int foi_papagaio(char *seq) 
{
  if (strcmp(seq,"piupiu") == 0 || strcmp(seq,"cocorocoo") == 0 ||
      strcmp(seq,"cacaraca") == 0 ||  strcmp(seq,"quaqua") == 0 ) return 0;
  return 1;
}

