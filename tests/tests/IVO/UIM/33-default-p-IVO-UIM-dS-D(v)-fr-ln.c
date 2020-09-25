//Classification: #default/p/IVO/UIM/dS/D(v)/fr/ln
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment:

#include <stdio.h>
#include <stdlib.h>

int* func() {
	int *p;
	p = (int *)malloc(sizeof(int));
	if (p == 0) {
		return 0;
	}
	(*p) = 10;
	return p;
}

int main(void) 
{
	int *q = func();
	if (q==0) {
		return 1;
	}
	printf ("%d", *q);
	free(q);
	return 0;
}
