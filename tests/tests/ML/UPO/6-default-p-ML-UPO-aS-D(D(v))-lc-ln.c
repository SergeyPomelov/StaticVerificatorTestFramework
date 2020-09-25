//Classification: #default/p/ML/UPO/aS/D(D(v))/lc/ln
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment: 

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int *p, **p1 = &p, *q, **q1 = &q;
	
	p = (int*)malloc(sizeof(int));
	if (p == 0) {
		return 1;
	}
	*p = 10;
	printf ("%d", **p1);
	
	q = (int*)malloc(sizeof(int));
	if (q == 0) {
		free(p);
		return 1;
	}
	*q = 10;
	printf ("%d", **q1);
	
	q1 = p1;
	
	free(q);
	free(*q1);

	return 0;
}
