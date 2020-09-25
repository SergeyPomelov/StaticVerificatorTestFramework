//Classification: #default/p/ML/UPO/dA/none/fpb/rp
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment: we allocate one copy of 'p' with a function 'func', and free it once

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
	int i;
	
	for (i = 0; i<1; i++) {
		if ( func(&p[1]) == 1 ) { return 1; }
		*p[1] = i+10;
		printf ("%d", *p[1]);
	}
	
	*p[1] = 2345;
	
	printf ("%d", *p[1]);
	free(p[1]);
	
	return 0;
}
