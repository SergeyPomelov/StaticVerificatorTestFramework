//Classification: #default/n/ML/UUM/dS/A(v,c)/fpb/cd
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment: we allocate memory in func and don't use it (unreachable branch)

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
	
	if (a*a+1 < 0) {
		(*p) = 12;
		printf ("%d", *p);
	}		

	free(p);
	return 0;
}
