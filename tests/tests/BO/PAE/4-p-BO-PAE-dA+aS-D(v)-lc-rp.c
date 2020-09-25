//Classification: #default/p/BO/PAE/dA+aS/D(v)/lc/rp
//Written by: Igor Eremeev
//Reviewed by: Pomelov Sergey
//Comment:  buffer overrun using pointer arithmetic

#include <stdlib.h>
#include <stdio.h>

int main (void)
{
	int *p, *q, i;
	q = (int*)malloc(sizeof(int)*50);
	if (q == 0) { return 1; }
	
	p = q;
	
	for(i = 0; i<50; i++) {
		(*p) = i;
		p++;
	}

	printf ("%d", q[1]+q[49]);
	free(q);
	return 0;
}
