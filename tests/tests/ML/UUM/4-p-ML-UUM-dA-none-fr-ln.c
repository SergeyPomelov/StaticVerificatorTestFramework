//Classification: #default/p/ML/UUM/dA/none/fr/ln
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment: we create dynamic copy of variable 'a' with function 'func' and use it

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
	int a = 1234;
	int *p[10];
	
	p[5] = func(a);
	if (p[5] == NULL) {
		return 1;
	}

	printf ("%d", *p[5]);	
	
	free(p[5]);
	return 0;
}
