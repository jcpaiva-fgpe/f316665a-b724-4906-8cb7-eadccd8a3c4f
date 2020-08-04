#include <stdio.h>


#ifndef APT 

int main()
{
  int n,i,resto;
  char *luzes[3]={"verde","laranja","vermelho"};
  scanf("%d\n",&n);

  for(i=0;i<4;i++)
    {
      resto = n%3;
      n=n/3;
      printf("%s\n",luzes[resto]);
    }
  return 0;
}

#endif




/*  ---------   ALTERNATIVE by apt  ------------ */

#ifdef APT 

int main()
{ int n, i;
  scanf("%d",&n);

  for (i=0; i< 4; i++) {
    switch (n%3) {
    case 0: printf("verde\n");
      break;
    case 1: printf("laranja\n");
      break; 
    case 2: printf("vermelho\n");
    }
    n = n/3;
  }
  return 0;
}

#endif
