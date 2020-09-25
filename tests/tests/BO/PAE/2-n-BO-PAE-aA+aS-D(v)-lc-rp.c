//Classification: #default/n/BO/PAE/aA+aS/D(v)/lc/rp
//Written by: Igor Eremeev
//Reviewed by: Pomelov Sergey
//Comment:  buffer overrun using pointer arithmetic

#include <stdlib.h>
#include <stdio.h>

int main (void)
{
	int *p, A[50], i;
	p = A;

	for (i = 0; i<50; i++) {
		(*p) = i;
		p++;
	}
	(*p) = 1024;
	
	printf ("%d", A[0] + *p);
	return 0;
}
