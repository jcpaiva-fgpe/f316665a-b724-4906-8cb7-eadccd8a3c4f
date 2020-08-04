#include <stdio.h>

#define MAX 102

int main()
{
  char seq[MAX];
  int n = 0, i;
  
  scanf("%s",seq);

  for (i=0; seq[i]!='o' && seq[i]!='O' && seq[i]!='\0'; i++) ;

  for (; seq[i]=='o' || seq[i]=='O'; i++) n++;

  printf("%d\n",n);
  return 0;
}
