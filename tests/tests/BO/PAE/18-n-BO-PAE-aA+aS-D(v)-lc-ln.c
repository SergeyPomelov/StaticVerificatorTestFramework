//Classification: #default/n/BO/PAE/aA+aS/D(v)/lc/ln
//Written by: Igor Eremeev
//Reviewed by: Pomelov Sergey
//Comment:  buffer overrun using pointer arithmetic

#include <stdlib.h>
#include <stdio.h>

int main (void)
{
	int *p, A[50];
	p = A;
	
	p+= 15;
	(*p) = 123;
	
	p+= 35;
	(*p) = 456;

	printf ("%d", *p);
	return 0;
}
