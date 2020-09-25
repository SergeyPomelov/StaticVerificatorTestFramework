//Classification: #specific_error/n/IVO/IVP/aS+dS/null_memory/lc/ln
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment: free null pointer

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int *p, *q;
	
	p = (int *)malloc(sizeof(int));
	if (p==0) {
		return 1;
	}
	
	(*p) = 10;
	printf ("%d", *p);
	
	q = p;
	
	printf ("%d", *q);
	free(q);
	free(p);
	
	return 0;
}
