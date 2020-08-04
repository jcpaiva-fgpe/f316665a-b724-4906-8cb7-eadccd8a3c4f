#include <stdio.h>

int main()
{
  int a, b, sessoes, f, as, bs, i, s=0;
  char func[101] = {0};

  scanf("%d %d",&a,&b);

  scanf("%d",&sessoes);

  while (sessoes) {
    scanf("%d %d %d",&f,&as,&bs);
    if (as < b && bs > a) 
      func[f] = 1;
    sessoes--;
  }

  for (i=1; i<101; i++)
    s += func[i];
  
  printf("%d\n",s);
  return 0;
}
