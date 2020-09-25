//Classification: #specific_error/n/IVO/IVP/aS/non_dynamic/fpb/ln
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment: free pointer to non-dynamical memory

#include <stdlib.h>
#include <stdio.h>

int a;

int func (int **p)
{
	(*p) = &a;
	return 0;
}

int main(void)
{
	int *p;
	a = 10;
	
	func (&p);
	printf ("%d", *p);
	
	free(p);
	return 0;
}
