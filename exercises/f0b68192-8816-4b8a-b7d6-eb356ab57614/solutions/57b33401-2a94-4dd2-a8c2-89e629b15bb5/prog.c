#include <stdio.h>

#define MAXBITS 1024

int main() {
  char c;
  int m, n, i, zero[MAXBITS]={0}, um[MAXBITS]={0};
  scanf("%d %d\n",&n,&m);
  while(n--) {
    for(i=0;i<m;i++) {
      c = getchar();
      if (c == '0') zero[i]++;
      else um[i]++;
    }
    getchar();
  }
  for (i=0; i<m;i++)
    if (zero[i] >= um[i])
      putchar('0');
    else putchar('1');
  putchar('\n');
  return 0;
}

