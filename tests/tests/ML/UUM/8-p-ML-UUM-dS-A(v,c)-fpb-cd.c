//Classification: #default/p/ML/UUM/dS/A(v,c)/fpb/cd
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment: we allocate memory in func and use it in one case

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
	int *p, a;
	scanf ("%d", &a);

	if ( func(&p) == 1 ) { return 1; }
	
	if (a > 10) {
		(*p) = 12;
		printf ("%d", *p);
	}	
	
	free(p);
	return 0;
}
