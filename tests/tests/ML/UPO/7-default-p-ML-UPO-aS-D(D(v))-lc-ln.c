//Classification: #default/p/ML/UPO/aS/D(D(v))/lc/ln
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment: 

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int *p, **p1 = &p;
	
	p = (int*)malloc(sizeof(int));
	if (p == 0) {
		return 1;
	}
	*p = 10;
	printf ("%d", *p);
	
	free(*p1);

	return 0;
}
