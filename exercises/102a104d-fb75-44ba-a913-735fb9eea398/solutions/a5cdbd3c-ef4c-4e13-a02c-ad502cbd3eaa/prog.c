#include <stdio.h>
#include <stdlib.h> /* ZP */


#define MAX 1001

char abre_parentesis(char c)
{ char cs;

  switch(c) {
  case ')':
    cs = '(';
    break;
  case '}':
    cs = '{';
    break;
  default:
    cs = '[';
  }
  return cs;
}



int main()
{
  char expr[MAX], par[MAX][2], c, cs;
  int pos[MAX], p, ok, ultimo, ps[MAX][2],t, pares;

  scanf("%s",expr);

  ok = 1; pares = 0;
  for (p=ultimo=0; (c=expr[p]) != '\0' && ok; p++) {
    if (c == '(' || c == '{' || c == '[') 
      pos[ultimo++] = p;
    else if  (c == ')' || c == '}' || c == ']') {
      cs = abre_parentesis(c);
      if (expr[pos[ultimo-1]] == cs) {
	par[pares][0] = cs;
	par[pares][1] = c;
        ps[pares][0] = pos[ultimo-1];
        ps[pares][1] = p;
        ultimo--; pares++;
      } else ok = 0;
    }
  }
  if (!ok || ultimo != 0) 
    printf("Pares mal formados\n");
  else if (pares == 0)
    printf("Sem noivos para casar\n");
  else
    for (p=0; p < pares; p++)
      printf("%c%c %d %d\n",par[p][0],par[p][1],ps[p][0],ps[p][1]);

  exit(0); /* ZP */
}
    
