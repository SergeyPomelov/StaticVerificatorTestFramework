//Classification: #default/n/ML/UUM/dA/A(v,c)/lc/cd
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment: the simplest case of unused memory  (unreachable branch)

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int *p[10], a;
	scanf ("%d", &a);
	
	p[5] = (int *)malloc(sizeof(int));
	if (p[5]==0) {
		return 1;
	}
	
	if (a*a+1 < 0) {
		*p[5] = 12;
		printf ("%d", *p[5]);
	}		

	free(p[5]);
	return 0;
}
