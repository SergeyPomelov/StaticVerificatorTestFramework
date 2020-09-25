//Classification: #default/n/ML/UPO/aS/D(D(v))/lc/ln
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment: 

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int *p, **q = &p;
	
	p = (int*)malloc(sizeof(int));
	if (p == 0) {
		return 1;
	}
	
	**q = 10;
	printf ("%d", **q);
	
	(*q) = (int*)malloc(sizeof(int));
	if (*q == 0) {
		return 1;
	}
	
	**q = 15;
	printf ("%d", **q);
	
	free(*q);

	return 0;
}
