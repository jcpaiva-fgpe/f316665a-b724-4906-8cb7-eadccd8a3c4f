/* Run-length enconding 
   Pedro Vasconcelos 2012
 */
#include <stdio.h>
#include <stdlib.h>

#define MIN(a,b) ((a)<=(b) ? (a) : (b))

void compress();
void emit(char, int);


int main (int argc, char **argv) {
  compress();
  return 0;
}


void compress() {
  int c, d, n;

  c = getchar();
  while (c!=EOF) {
    d = getchar(); 
    n = 1;
    while(d == c) {
      d = getchar();
      n++;
    }
    emit(c, n);
    c = d;
  }
}


void emit(char c, int n) {
  int q, r, i;
  q = n/12;
  r = n%12;
  
  while(q>0) {
    printf("%c%c%c9", c,c,c);
    q--;
  }

  i = MIN(r,3);
  while (i>0) {
    putchar(c);
    i--;
  }
  if(r>=3) {
    printf("%d",r-3);    
  } 
}
