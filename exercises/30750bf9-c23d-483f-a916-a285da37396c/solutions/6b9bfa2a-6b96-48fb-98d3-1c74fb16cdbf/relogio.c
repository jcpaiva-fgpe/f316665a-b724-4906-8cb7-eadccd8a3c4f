#include <stdio.h>

int main()
{
  int secs,horas,minutos,segs;
  scanf("%d",&secs);
  
  secs+=43200;
  horas = secs/3600;
  minutos = (secs-horas*3600)/60;
  segs = (secs-horas*3600)-minutos*60;
  if (horas<10) {printf("0");printf("%d:",horas);}
  else printf("%d:",horas);
  if (minutos<10) {printf("0");printf("%d:",minutos);}
  else printf("%d:",minutos);
  if (secs<10) {printf("0");printf("%d\n",segs);}
  else printf("%d\n",segs);

  return 0;
}
