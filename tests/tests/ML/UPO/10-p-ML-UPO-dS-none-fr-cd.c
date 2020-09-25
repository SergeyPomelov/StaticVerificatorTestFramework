//Classification: #default/p/ML/UPO/dS/none/fr/cd
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment: if b > 10 , we create dynamic copy of variable 'a' with function 'func' and free it

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
	int b, *q;

	scanf ("%d", &b);
	
	if (b > 10) {
		q = func(a);
		if (q == NULL) {
			return 1;
		}
		printf ("%d", *q);
		free(q);
	}
	
	printf ("%d", a);
	return 0;
}
