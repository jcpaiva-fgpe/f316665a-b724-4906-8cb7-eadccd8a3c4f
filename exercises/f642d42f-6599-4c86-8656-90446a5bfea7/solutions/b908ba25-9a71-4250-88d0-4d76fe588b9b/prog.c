#include <stdio.h>

#define MAXDIM 200
#define MAIUSCULA(C)((C)>='A' && (C)<='Z')
#define MINUSCULA(C)((C)>='a' && (C)<='z')

void conta_letras(char *seq, int conta[])
{
  int i;
  for (i=0;i<26;i++) conta[i] = 0;
  while (*seq) {
    if (MAIUSCULA(*seq)) conta[(int)((*seq) - 'A')]++;
    else if (MINUSCULA(*seq)) conta[(int)((*seq) - 'a')]++;
    seq++;
  }
}
void ler_linha(char *s)
{ 
  while ((*s=getchar())!='\n') s++;
  *s = '\0';
}

int main()
{ int i, c1[26], c2[26];
  char seq1[MAXDIM], seq2[MAXDIM];

  ler_linha(seq1);
  ler_linha(seq2);
  conta_letras(seq1,c1);
  conta_letras(seq2,c2);
  for (i=0;i<26 && c1[i]==c2[i];i++) ;
  if (i == 26) printf("yes\n");
  else printf("no\n");
  return 0;
}
