#include <stdio.h>

int bonus (char x_la, char x_lo, char y_la, char y_lo) {
	if (x_la != y_la && x_lo != y_lo) 
		return 4;
	if (x_la != y_la) 
		return 2;
	if (x_lo != y_lo) 
		return 1;
	return 0;
}

int main (void)
{
  int n, x, i,np;
  char la1, la2, lo1,lo2;

  np = 0;
  scanf ("%d", &n);
  for (i=0; i < n; i++){
	scanf ("%d %c %d %c %d %c %d %c", &x, &la1, &x, &lo1, &x, &la2, &x, &lo2);
	np += bonus(la1, lo1, la2, lo2);
  }
  printf ("%d\n", np);
  return 0;
}
