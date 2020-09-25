//Classification: #default/p/IVO/UIM/dA/D(v,c)/fr/rp
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment:

#include <stdio.h>
#include <stdlib.h>

int* func() {
	int i, *p;
	p = (int *)malloc(sizeof(int)*10);
	if (p == 0) {
		return 0;
	}
	for (i = 0; i<10; i++) {
		(*(p+i)) = i;
	}
	return p;
}

int main(void) 
{
	int *q = func();
	if (q==0) {
		return 1;
	}
	printf ("%d", *(q+6));
	free(q);
	return 0;
}
