#include <stdio.h>
#include <string.h>

#define MAX_STRING 501

int main() {  
  char rot[10]="012??59?86", s[MAX_STRING];
  int i,j,len,num;

  scanf("%d",&num);
  for (i=0;i<num;i++) {
    scanf("%s",s);
    len=strlen(s);
    for (j=0;2*j<=len;j++)
      if (rot[(int)(s[j]-'0')]!=s[len-j-1]) break;
    
    if (2*j<=len) puts("NAO");
    else          puts("SIM");
  }
  
  return 0;
}
