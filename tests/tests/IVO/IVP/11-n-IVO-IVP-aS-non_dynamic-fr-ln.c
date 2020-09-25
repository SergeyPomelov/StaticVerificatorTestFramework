//Classification: #specific_error/n/IVO/IVP/aS/non_dynamic/fr/ln
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment: free pointer to non-dynamical memory

#include <stdlib.h>
#include <stdio.h>

int a;

int *func ()
{
	int *p = &a;
	return p;
}

int main(void)
{
	int *p;
	a = 10;
	
	p = func();
	
	printf ("%d", *p);
	
	free(p);
	return 0;
}
