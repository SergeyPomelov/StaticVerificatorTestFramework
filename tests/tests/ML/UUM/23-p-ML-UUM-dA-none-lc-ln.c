//Classification: #default/p/ML/UUM/dA/none/lc/ln
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment: the simplest case of unused memory

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int *p[10];
	
	p[5] = (int *)malloc(sizeof(int));
	if (p[5]==0) {
		return 1;
	}
	
	*p[5] = 12;
	printf ("%d", *p[5]);

	free(p[5]);
	return 0;
}
