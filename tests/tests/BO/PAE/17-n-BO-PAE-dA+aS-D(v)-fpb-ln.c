//Classification: #default/n/BO/PAE/dA+aS/D(v)/fpb/ln
//Written by: Igor Eremeev
//Reviewed by: Pomelov Sergey
//Comment:  buffer overrun using pointer arithmetic

#include <stdlib.h>
#include <stdio.h>

int func(int **p) 
{
	(*p)++;
	return 0;
}


int main (void)
{
	int *p, *q;
	p = (int*)malloc(sizeof(int)*50);
	if (p == 0) { return 1; }
	q = p;

	q+=15;
	(*q) = 123;
	
	func(&q);
	
	q+=34;
	(*q) = 456;
	
	printf ("%d", p[15]+*q);
	free(p);
	return 0;
}
