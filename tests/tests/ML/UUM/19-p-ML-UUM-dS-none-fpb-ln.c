//Classification: #default/p/ML/UUM/dS/none/fpb/ln
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment: we allocate memory in func and use it

#include <stdlib.h>
#include <stdio.h>

int func (int **p)
{
	*p = (int *)malloc(sizeof(int));
	if ((*p)==0) {
		return 1;
	}
	return 0;
}

int main(void)
{
	int *p;

	if ( func(&p) == 1 ) { return 1; }
	
	(*p)=10;
	printf ("%d", *p);
	
	free(p);
	return 0;
}
