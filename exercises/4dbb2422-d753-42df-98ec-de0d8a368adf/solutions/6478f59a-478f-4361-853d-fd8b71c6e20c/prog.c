#include <stdio.h>

int main()
{
	int a,b;
	scanf("%d %d", &a, &b);
	if (a != b) {
	  printf("The perimeter of the rectangle is %d m.\n", 2*a+2*b);
	  printf("The area of the rectangle is %d m2.\n", a*b);
	} else {
	  printf("The perimeter of the square is %d m.\n", 2*a+2*b);
	  printf("The area of the square is %d m2.\n", a*b);
	}
	return 0;
}
