//Classification: #default/n/BO/PAE/dA+aS/D(v)/lc/rp+cd
//Written by: Igor Eremeev
//Reviewed by: Pomelov Sergey
//Comment:  buffer overrun using pointer arithmetic

#include <stdlib.h>
#include <stdio.h>

int main (void)
{
	int *p, *q, i, a;
	scanf("%d", &a);
	
	p = (int*)malloc(sizeof(int)*50);
	if (p == 0) { return 1; }
	q = p;

	for (i = 0; i<50; i++) {
		(*q) = i;
		q++;
	}
	
	if (a > 10) {
		q = p;
	}
	(*q) = 1024;
	
	printf ("%d", p[25] + *q);
	free(p);
	return 0;
}
