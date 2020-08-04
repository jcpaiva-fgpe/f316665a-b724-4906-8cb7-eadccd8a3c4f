#include <stdio.h>

#include <math.h>

#define MAXPATTERN 10000



char converte(char *linha);
int  ok_pattern(int t,char *fita,int length);


char converte(char *linha)
{
  char v = 0;
  while (*linha != 'T') {
    v = 2*v;
    if (*linha == '*') v++;
    linha++;
  }
  return v;
}


int ok_pattern(int dimpattern,char *fita,int length)
{
  int ok = 1, i, j = dimpattern;
  
  while (ok && j < length) {
    for (i=0; i < dimpattern; i++,j++)
      if (fita[j] != fita[i]) {
	ok = 0; break;
      }
  }
  return ok;
}



int main()
{
  int width, length, dimpatt, ok, i;
  char linha[10], fita[MAXPATTERN*2];

  scanf("%d %d",&width,&length);
  
  
  for (i = 0; i < length; i++) {
    scanf("%s",linha);
    fita[i] = converte(linha);  // poderia não ler toda
  }


  dimpatt = 0; ok=0; 
  while (ok == 0 && dimpatt < length/2) {
    dimpatt++;
    if (length%dimpatt == 0) 
      ok = ok_pattern(dimpatt,fita,length);
  }
  if (!ok) printf("%d\n",1);
  else printf("%d\n",length/dimpatt);

  return 0;
}
