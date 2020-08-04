// by apt
#include <stdio.h>

#define MAX 101

int main()
{

  char p[MAX], q[MAX];
  int i, j, conta = 0;

  scanf("%s",p);
  scanf("%s",q);

  for (i=0; q[i] != '\0'; i++) {
    for (j=0; p[j] != '\0' && q[i+j] == p[j]; j++);
    if (p[j] == '\0') conta++;
  }
      
  printf("%d\n",conta);
  return 0;
}
