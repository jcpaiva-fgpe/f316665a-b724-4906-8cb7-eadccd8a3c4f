#include <stdio.h>

int main()
{
  int c = getchar();
  while(c!='.') {
    putchar(c);
    c = getchar();
    while(c >='a' && c <='z') {
      putchar(c);
      c=getchar();
    }
    putchar(' ');
    if( c=='.' || (c >= 'A' && c <= 'Z')) 
      putchar('1');
    else {
      
      while (c >='0' && c <='9') {
	putchar(c);
	c=getchar();
      }
    }
    putchar('\n');
  }

  return 0;
}
    
    



    
