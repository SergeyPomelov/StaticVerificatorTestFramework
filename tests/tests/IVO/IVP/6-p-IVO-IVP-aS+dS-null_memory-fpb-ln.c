//Classification: #specific_error/p/IVO/IVP/aS+dS/null_memory/fpb/ln
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment: free null pointer

#include <stdlib.h>
#include <stdio.h>

int func (int **p, int **q)
{
	*q=*p;
	return 0;
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
	
	func(&p, &q);
	
	printf ("%d", *q);
	free(q);
	
	return 0;
}
