#include <stdio.h>

#define TOTALDIAS 104
#define SETEMBRO_5 97
#define JUNHO_4  4
#define JUNHO_6  6

#define INDISPONIVEL -1

int Pontos[TOTALDIAS];

int converte(int,int);
void acumula(int, int, int, int, int);
int procuraSemana(int,int *);

int converte(int dia, int mes){
  int dias[3]={30,61,92};
  mes = mes-7;
  if (mes >= 0)
    dia = dia + dias[mes];
  return dia;
}

void acumula(int di, int mi, int df, int mf, int pref){
  di = converte(di,mi);
  df = converte(df,mf);
  if (pref == INDISPONIVEL) 
    for(; di <= df; di++)
      Pontos[di] = INDISPONIVEL;
  else
    for(; di <= df; di++)
      if(Pontos[di] != INDISPONIVEL) Pontos[di] += pref;
}

int procuraSemana(int dia,int *maximo) {
  int i,aux, imax = -1;
  do {
    for (i=0, aux=0; i <7 && Pontos[dia+i] != INDISPONIVEL; i++) 
      aux += Pontos[dia+i];
    if (i==7 && aux > *maximo) {
      *maximo = aux;
      imax = dia;
    }
    dia += 7;
    //    printf(">>> dia %d\n",dia);
  } while (dia <= SETEMBRO_5); // 5 de Setembro
  return imax;
}

void escreveDia(int dia)  {
  if (dia <= 30) printf("%d de Junho\n",dia);
  else if (dia <= 61) printf("%d de Julho\n",dia-30);
  else if (dia <=92)  printf("%d de Agosto\n",dia-61);
  else  printf("%d de Setembro\n",dia-92);
}
  

int main(){
  int n, p, maxSabado = -1, maxSegunda = -1;
  int di,mi,df,mf,pref, sabado, segunda;
  for(di=1;di <= TOTALDIAS; di++) Pontos[di] = 0;

  scanf("%d",&n);
  while (n--) {
    scanf("%d",&p);
    while(p--) {
      scanf("%d%d%d%d%d",&di,&mi,&df,&mf,&pref);
      acumula(di,mi,df,mf,pref);
    }
  }
  sabado = procuraSemana(JUNHO_4,&maxSabado);   // 4 de Junho
  segunda = procuraSemana(JUNHO_6,&maxSegunda); // 6 de Junho
  if (maxSabado > maxSegunda)  {
    maxSegunda = maxSabado;
    segunda = sabado;
  } else if (maxSabado == maxSegunda && sabado < segunda)
    segunda = sabado;
  if (maxSegunda == -1)
    printf("inconsistente\n");
  else escreveDia(segunda);
  return 0;
}
