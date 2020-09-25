//Classification: #default/p/BO/PAE/aA+aS/D(v)/lc/rp
//Written by: Igor Eremeev
//Reviewed by: Pomelov Sergey
//Comment:  buffer overrun using pointer arithmetic

#include <stdlib.h>
#include <stdio.h>

int main (void)
{
	int *p, A[50], i;
	p = A;
	
	for(i = 0; i<50; i++) {
		(*p) = i;
		p++;
	}

	printf ("%d", A[0]+A[49]);
	return 0;
}
