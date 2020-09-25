//Classification: #default/n/BO/PAE/dA+aS/D(v)/lc/ln
//Written by: Igor Eremeev
//Reviewed by: Pomelov Sergey
//Comment:  buffer overrun using pointer arithmetic

#include <stdlib.h>
#include <stdio.h>

int main (void)
{
	int *p, *q;
	p = (int*)malloc(sizeof(int)*50);
	if (p == 0) { return 1; }
	q = p;

	q+=15;
	(*q) = 123;
	
	q+=35;
	(*q) = 456;
	
	printf ("%d", p[15] + *q);
	free(p);
	return 0;
}
