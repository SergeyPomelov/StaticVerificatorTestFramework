//Classification: #default/n/ML/UUM/dS/A(v,c)/lc/cd
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment: the simplest case of unused memory

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int *p, a;
	scanf ("%d", &a);
	
	p = (int *)malloc(sizeof(int));
	if (p==0) {
		return 1;
	}
	
	if (a*a+1 < 0) {
		(*p) = 12;
		printf ("%d", *p);
	}		

	free(p);
	return 0;
}
