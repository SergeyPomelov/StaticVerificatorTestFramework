//Classification: #default/n/ML/UUM/dS/A(v,c)/fr/cd
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment: we create dynamic copy of variable 'a' with function 'func' and don't use it (unreachable branch)

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
	int *p, b;
	scanf ("%d", &b);
	
	p = func(a);
	if (p == NULL) {
		return 1;
	}
	
	if (b*b+1 < 0) {
		(*p) = 12;
		printf ("%d", *p);
	}		

	free(p);
	return 0;
}
