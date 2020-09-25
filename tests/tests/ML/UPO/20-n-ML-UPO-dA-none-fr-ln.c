//Classification: #default/n/ML/UPO/dA/none/fr/ln
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment: we create dynamic copy of variable 'a' with function 'func' and don't free it

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
	
	int *q[3];
	
	q[1] = func(a);
	if (q[1] == NULL) {
		return 1;
	}
	
	printf ("%d", *q[1]);
	return 0;
}
