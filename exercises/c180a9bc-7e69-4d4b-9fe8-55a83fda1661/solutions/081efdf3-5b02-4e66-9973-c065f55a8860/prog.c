#include <stdio.h>


int main()
{
  int conta = 0, c;
  while ( (c=getchar())!='\n' ) 
    if (c == 'p' || c == 'P' ) conta++;
  printf("%d\n",conta);
  return 0;
}
