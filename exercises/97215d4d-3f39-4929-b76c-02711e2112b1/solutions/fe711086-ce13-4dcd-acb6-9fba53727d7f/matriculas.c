#include <stdio.h>
int main(){
  int i, t, n1, n2, first, last;
  char l1, l2;

  scanf("%d", &t);
  for (i = 0; i < t; i++) {
    scanf("%d-%d-%c%c", &n1, &n2, &l1, &l2);
    if (l1 > 'W') l1 -= 3;
    else if (l1 > 'Y') l1 -= 2;
    else if (l1 > 'K') l1 -= 1;
    if (l2 > 'W') l2 -= 3;
    else if (l2 > 'Y') l2 -= 2;
    else if (l2 > 'K') l2 -= 1;
    first = n1 * 100 + n2 + 10000 * ((l1 - 'A') * 23 + l2 - 'A');
    
    scanf("%d-%d-%c%c", &n1, &n2, &l1, &l2);
    if (l1 > 'W') l1 -= 3;
    else if (l1 > 'Y') l1 -= 2;
    else if (l1 > 'K') l1 -= 1;
    if (l2 > 'W') l2 -= 3;
    else if (l2 > 'Y') l2 -= 2;
    else if (l2 > 'K') l2 -= 1;
    last = n1 * 100 + n2 + 10000 * ((l1 - 'A') * 23 + l2 - 'A');
    
    printf("%d\n", last - first + 1);
  }
  return 0;
}
