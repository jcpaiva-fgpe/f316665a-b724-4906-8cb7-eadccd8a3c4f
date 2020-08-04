#include <stdio.h>

int main()
{
   int nota1, nota2; 
   char* intervalo[ ] = {"oitava", "segunda", "terceira", "quarta", "quinta",
	   "sexta", "setima"};
   scanf ("%i",&nota1);
   scanf ("%i",&nota2);
   printf("intervalo de ");
   if (nota2>=nota1){
	   printf("%s\n",intervalo[(nota2-nota1)]);
   }
   else   { 
   printf("%s\n",intervalo[(7-(nota1-nota2))]);
   }
   return 0;
}
