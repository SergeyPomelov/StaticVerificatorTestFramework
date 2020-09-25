//Classification: #default/n/BO/PAE/dA+aS/D(v)/fp/rp
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
	(*p) = 1024;
	return 0;
}

int main (void)
{
	int *p;
	p = (int*)malloc(sizeof(int)*50);
	if (p==0) { return 1; }
	
	func (p);

	printf ("%d", p[0]+p[49]);
	free(p);
	return 0;
}
