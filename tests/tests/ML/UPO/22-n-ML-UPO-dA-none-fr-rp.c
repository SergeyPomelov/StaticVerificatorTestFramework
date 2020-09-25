//Classification: #default/n/ML/UPO/dA/none/fr/rp
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment: we create dynamic copy of variable 'a' with function 'func' 10 times but free it once

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
	int *q[3], i, a = 1234;
	
	for (i = 0; i<10; i++) {
		q[1] = func(a);
		a++;
		if (q[1] == NULL) {
			return 1;
		}
		printf ("%d", *q[1]+a);
	}
	
	printf ("%d", *q[1]);
	free(q[1]);
	
	return 0;
}
