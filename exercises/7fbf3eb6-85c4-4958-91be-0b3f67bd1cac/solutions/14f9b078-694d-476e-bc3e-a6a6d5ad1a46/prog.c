#include <stdio.h>

int valor(char c)
{
  switch(c) {
  case 'I': return 1;
  case 'V': return 5;
  case 'X': return 10;
  case 'L': return 50;
  case 'C': return 100;
  case 'D': return 500;
  case 'M': return 1000;
  default: return 0;
  }
}

int main()
{
  char romseq[20];
  int val, i, n, vdir, arabe = 0;

  scanf("%s",romseq);

  for(n=0; romseq[n] != '\0'; n++) ;

  n--; // assume string valida com pelo menos 1 letra

  vdir = 0;
  do {
    for (i=1; n-i>=0 && romseq[n-i]==romseq[n]; i++) ;
    val = valor(romseq[n])*i; 
    if (val > vdir) arabe += val;
    else arabe -= val;
    vdir = val;
    n = n-i;
  } while (n >= 0 );
  printf("%d\n",arabe);
  return 0;
}
