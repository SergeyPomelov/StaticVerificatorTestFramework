//Classification: #default/p/BO/PAE/aA+aS/D(v)/lc/rp+cd
//Written by: Igor Eremeev
//Reviewed by: Pomelov Sergey
//Comment:  buffer overrun using pointer arithmetic

#include <stdlib.h>
#include <stdio.h>

int main (void)
{
	int *p, A[50], i, a;
	scanf("%d", &a);
	p = A;

	for (i = 0; i<50; i++) {
		(*p) = i;
		p++;
	}
	if (a > 10) {
		p = A;	
		(*p) = 1024;
	}
	

	
	printf ("%d", A[15] + A[0]);
	return 0;
}
