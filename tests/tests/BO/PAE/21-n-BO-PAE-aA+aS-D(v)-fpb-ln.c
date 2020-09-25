//Classification: #default/n/BO/PAE/aA+aS/D(v)/fpb/ln
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
	int *p, A[50];
	p = A;
	
	p+= 15;
	(*p) = 123;
	
	func (123, &p);
	
	p+= 34;
	(*p) = 456;

	printf ("%d", *p);
	return 0;
}
