#include <stdio.h>
#include <stdlib.h>
#define N 1001
int p [N];

// alterado por APT (10 Maio)

int compute_value(int np, int n)
{
	int i,j,imax,result=0;
	for (i = 0; i < n ; i++){
		imax = 0;
		for (j = 0; j < np; j++)
			if (p[imax] < p[j])
				imax = j; 
		result += p[imax];
                p[imax] = 0;    
	}
	return result;
}

int main ()
{
	int i,ne,np,n,result=0;
	scanf ("%d %d", &ne, &np);
	for (i = 0; i < np; i++){
		scanf ("%d", &p[i]);
	}
	n = np/ne;
	result=compute_value(np,n);
	printf ("%d\n",result);
	return 0;
}
