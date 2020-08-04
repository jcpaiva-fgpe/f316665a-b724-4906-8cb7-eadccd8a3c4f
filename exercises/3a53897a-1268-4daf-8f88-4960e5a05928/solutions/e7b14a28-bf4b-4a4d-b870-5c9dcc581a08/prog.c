#include <stdio.h>


#define NLOCAIS 9
#define MAXNOME 12

//#define DEBUG


char Nomes[NLOCAIS][MAXNOME] = {"Atenas","Barcelona","Frankfurt","Funchal","Lisboa","Londres","Madrid","Paris","Porto"};

int Coords[NLOCAIS][2] = {{12779, 20557},{1113, 22779},{4445,22779},{-8887, 17779},{-4999,21113}, {1, 28335}, {-1665, 22223}, {1113, 26667}, {-4443,22779}};



int  afecta(int i,int a,int b,int c,int d,int hu,int vu,int m)
{
  int x = Coords[i][0], y = Coords[i][1], ok=0;
  
  while (m >= 0 && !ok) {
    // ineficiente
    if (a <= x && x <= c && b <= y && y <= d) ok = 1;
    x = x -hu; y = y-vu; 
    m -= 1;
  }
#ifdef DEBUG
  if (ok) printf(">> afecta  %s\n",Nomes[i]);
#endif
  return ok;
}

void normaliza(int *h,int *v,int *m)
{
  if (*h == 0) {
    if (*v > 0) *m = *v;
    else *m = - (*v);
  } else {
    if (*h > 0) *m = *h;
    else *m = - (*h);
  }
  *h = (*h)/(*m);
  *v = (*v)/(*m);
#ifdef DEBUG
  if (*h != 0 && *h != 1 && *h != -1) {
    printf("erro exemplo\n");
  }
  if (*v != 0 && *v != 1 && *v != -1) {
    printf("erro exemplo\n");
  }
#endif

}



int main()
{
  int a,b,c,d,np,h,v,m,vu,hu,i, nivel[NLOCAIS];

  scanf("%d %d %d %d",&a,&b,&c,&d);

  scanf("%d",&np);

  for (i=0; i < NLOCAIS; i++)
    nivel[i] = 0;

  while(np > 0) {

    scanf("%d %d",&h,&v);
    
    hu = h; vu = v;
    normaliza(&hu,&vu,&m);

    for (i=0; i < NLOCAIS; i++)
      nivel[i] += afecta(i,a,b,c,d,hu,vu,m);
    
    a = a+h; b = b+v; 
    c = c+h; d = d+v; 
#ifdef DEBUG
    printf(">>> %d %d %d %d\n",a,b,c,d);
#endif
    np--;
  }

  for (i=0,a=0; i < NLOCAIS; i++)
    if (nivel[i] > 0) a++;

  printf("%d\n",a);
  if (a == 0)   printf("Foi para o Polo Norte?\n");
  else
    for (i=0; a && i < NLOCAIS; i++)
      if (nivel[i] > 0) {
	a--;
	printf("%s %d\n",Nomes[i],nivel[i]);
      }
  return 0;
}
