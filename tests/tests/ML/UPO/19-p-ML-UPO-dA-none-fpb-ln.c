//Classification: #default/p/ML/UPO/dA/none/fpb/ln
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
	int *p[3];
	
	if ( func(&p[0]) == 1 ) { return 1; }
	if ( func(&p[1]) == 1 ) { return 1; }
	if ( func(&p[2]) == 1 ) { return 1; }

	*p[0] = 1234;
	*p[1] = 2345;
	*p[2] = 3456;
	
	printf ("%d", *p[0]+*p[1]+*p[2]);
	free(p[0]);
	free(p[1]);
	free(p[2]);
	
	return 0;
}
