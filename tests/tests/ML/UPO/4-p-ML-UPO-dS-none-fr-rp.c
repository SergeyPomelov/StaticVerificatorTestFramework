//Classification: #default/p/ML/UPO/dS/none/fr/rp
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment: we create dynamic copy of variable 'a' with function 'func' once and free it once

#include <stdlib.h>
#include <stdio.h>

int *func(int a) 
{
	int *p = (int *)malloc(sizeof(int));
	if (p == 0) {
		return NULL;
	}
	(*p) = a;
	return p;
}

int main(void)
{
	int *q, i, a = 1234;
	
	for (i = 0; i<1; i++) {
		q = func(a);
		a++;
		if (q == NULL) {
			return 1;
		}
		printf ("%d", *q+a);
	}
	
	printf ("%d", *q);
	free(q);
	
	return 0;
}
