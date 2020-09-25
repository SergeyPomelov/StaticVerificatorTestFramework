//Classification: #default/n/ML/UUM/dS/none/lc/ln
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment: the simplest case of unused memory

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int *p;
	
	p = (int *)malloc(sizeof(int));
	if (p==0) {
		return 1;
	}

	free(p);
	return 0;
}
