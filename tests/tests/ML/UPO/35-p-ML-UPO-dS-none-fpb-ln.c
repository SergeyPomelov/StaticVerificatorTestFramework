//Classification: #default/p/ML/UPO/dS/none/fpb/ln
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment: we allocate copy of 'p' with 'func' and free it in 'main'

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

	(*p) = 1234;
	printf ("%d", *p);
	free(p);
	
	return 0;
}
