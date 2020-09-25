//Classification: #default/n/ML/UPO/dS/none/lc/ln
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment: the simplest case of memory leak

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int *p, a = 10;
	
	p = (int *)malloc(sizeof(int));
	if (p==0) {
		return 1;
	}
	
	(*p) = 1234;
	printf ("%d", *p);

	p = &a;
	printf ("%d", *p);

	return 0;
}
