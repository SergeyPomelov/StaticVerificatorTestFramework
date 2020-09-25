//Classification: #default/n/ML/UPO/dA/none/lc/ln
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment: the simplest case of memory leak

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int *p[3], a = 10;
	
	p[1] = (int *)malloc(sizeof(int));
	if (p[1]==0) {
		return 1;
	}
	
	*p[1] = 23456;
	
	printf ("%d", *p[1]);
	
	p[1] = &a;
	
	printf ("%d", *p[1]);

	return 0;
}
