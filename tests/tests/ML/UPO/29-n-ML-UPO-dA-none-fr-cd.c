//Classification: #default/n/ML/UPO/dA/none/fr/cd
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment: if b > 10 , we create dynamic copy of variable 'a' with function 'func' and don't free it

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
	
	int b, *q[3];
	scanf ("%d", &b);
	
	if (b > 10) {
		q[1] = func(a);
		if (q[1] == NULL) {
			return 1;
		}
		printf ("%d", *q[1]);
	}
	
	printf ("%d", a);
	return 0;
}
