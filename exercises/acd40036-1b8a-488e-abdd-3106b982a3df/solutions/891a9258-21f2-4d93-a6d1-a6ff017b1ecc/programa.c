#include <stdio.h>

int main()
{ int ncadeiras[100];
  int nc, nh, pe, i, v, t,j;

  scanf("%d",&nc);

  for (i=0; i< nc; i++) {
    scanf("%d", &t);
    scanf("%d", &v);
    ncadeiras[t-1] = v;
  }
  scanf("%d",&nh);
  pe = nh;
  for (i=0; i<nh; i++) {
    scanf("%d", &v);
    for (j=0;j<v; j++) {
      scanf("%d", &t);
      if (ncadeiras[t-1] > 0) {
	ncadeiras[t-1]--;
	pe--;
	while(++j<v)  scanf("%d", &t);
      }
    }
  }
  for (i=v=0; i<nc; i++) 
    v += ncadeiras[i];
  printf("%d\n%d\n",pe,v);
  return 0;
}
