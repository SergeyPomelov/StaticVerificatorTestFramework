//Classification: #default/p/ML/UUM/dA/A(v,c)/fpb/cd
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment: we allocate memory and use it in one case

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
	int *p[10], a;
	scanf ("%d", &a);

	if ( func(&p[5]) == 1 ) { return 1; }
	
	if (a > 10) {
		*p[5] = 12;
		printf ("%d", *p[5]);
	}		

	free(p[5]);
	return 0;
}
