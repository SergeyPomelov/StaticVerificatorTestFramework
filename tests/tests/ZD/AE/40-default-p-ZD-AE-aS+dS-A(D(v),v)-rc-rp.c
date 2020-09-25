//Classification: #default/p/ZD/AE/aS+dS/A(D(v),v)/rc/rp
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov

#include <malloc.h>
#include <stdio.h>

int recursion(int a) {
	if (a > 5) {
		return (a);
	}
	a++;
	return (recursion(a));
}

int main(void) {
	int *p;
	int a = -6;
	int b;
	
	p = (int *)malloc(sizeof(int));
	if (p == 0) {
		return 1;
	}
	*p = 4;

	a = recursion (a);

	while (*p < 5) {
		(*p)++;
		b = 1 / (a - *p);
		printf ("%d", b);
	}

	free(p);
	return 0;
}
