//Classification: #specific_error/p/IVO/IVP/aS+dS/null_memory/fr/ln
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment: free null pointer

#include <stdlib.h>
#include <stdio.h>

int *func(int *p)
{
	int *q = p;
	return q;
}

int main(void)
{
	int *p, *q;
	
	p = (int *)malloc(sizeof(int));
	if (p==0) {
		return 1;
	}
	
	(*p) = 10;
	printf ("%d", *p);
	
	q = func (p);
	
	printf ("%d", *q);
	free(q);
	
	return 0;
}
