//Classification: #default/p/BO/PAE/dA+aS/D(v)/fpb/rp
//Written by: Igor Eremeev
//Reviewed by: Pomelov Sergey
//Comment:  buffer overrun using pointer arithmetic

#include <stdlib.h>
#include <stdio.h>

int func(int i, int **p) 
{
	(**p) = i;
	(*p)++;
	return 0;
}


int main (void)
{
	int *p, *q, i;
	p = (int*)malloc(sizeof(int)*50);
	if (p == 0) { return 1; }
	q = p;

	for (i = 0; i<50; i++) {
		func(i, &q);
	}
	
	q--;
	(*q) = 1024;
	
	printf ("%d", p[0] + *q);
	free(p);
	return 0;
}
