//Classification: #default/p/BO/PAE/aA+aS/D(v)/fp/rp
//Written by: Igor Eremeev
//Reviewed by: Pomelov Sergey
//Comment:  buffer overrun using pointer arithmetic

#include <stdlib.h>
#include <stdio.h>

int func (int *p)
{
	int i;
	for (i=0; i<50; i++) {
		(*p) = i;
		p++;
	}
	p--;
	(*p) = 1024;
	return 0;
}

int main (void)
{
	int *p, A[50];
	p = A;
	
	func (p);

	printf ("%d", A[0]+A[49]);
	return 0;
}
