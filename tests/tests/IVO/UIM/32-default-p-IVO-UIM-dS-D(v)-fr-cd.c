//Classification: #default/p/IVO/UIM/dS/D(v)/fr/cd
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment:

#include <stdio.h>
#include <stdlib.h>

int* func() {
	int b, *p;
	p = (int *)malloc(sizeof(int));
	if (p==0) {
		return 0;
	}
	scanf ("%d", &b);
	if (b>0) {
		(*p) = 10;
	}
	else {
		(*p) = 20;
	}
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
