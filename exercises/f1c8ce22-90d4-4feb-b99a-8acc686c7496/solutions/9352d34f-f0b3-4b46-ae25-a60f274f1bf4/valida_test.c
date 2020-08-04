#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n=0, c;
  c=getchar();
  while(c!='.') {
    if(c>='A' && c<='Z') {
      putchar(c);
      n++;
      c=getchar();
      while(c>='a' && c<='z' ) {
	putchar(c);
	c=getchar();
	n++;
      }
      if (c=='0') {
	fprintf(stderr,"erro zero\n");
	exit(1);
      };
      while(c>='0' && c<='9' ) {
	putchar(c);
	n++;
	c= getchar();
      }
      
    } else {
      fprintf(stderr,"erro mais  %c\n",c);
      exit(1);
    }
  }
  putchar('.');
  putchar('\n');
  if (n < 1 || n >1000) {
    fprintf(stderr,"erro dime\n");
    exit(1);
  } else     fprintf(stderr,"n=%d\n",n);
  return 0;
}

