//Classification: #default/n/ML/UUM/dS/none/fpb/ln
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment: we allocate memory in func and don't use it

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

	free(p);
	return 0;
}
