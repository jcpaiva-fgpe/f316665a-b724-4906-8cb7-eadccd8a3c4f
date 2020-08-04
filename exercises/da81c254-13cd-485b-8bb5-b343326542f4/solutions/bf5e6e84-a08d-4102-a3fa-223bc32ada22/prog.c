#include <stdio.h>

int main()
{
   int h1,m1,h2,m2;
   int minutos;

   scanf("%d %d %d %d", &h1, &m1, &h2, &m2);
   minutos = h2*60+m2-(h1*60+m1);

   if (minutos == 1) 
     printf("Passou apenas 1 minuto!\n");
   else printf("Passaram apenas %d minutos!\n",minutos);
   if (minutos < 60) printf("De facto!\n");
   else {
     h1 = minutos/60;  m1 = minutos%60;
     printf("Queres dizer, ");
     if (h1 == 1) 
       printf("1 hora");
     else printf("%d horas",h1);
     if (m1 == 1) printf(" e 1 minuto");
     else if (m1 > 1) printf(" e %d minutos",m1);
     printf("?!\n");
   }
   return 0;
}
