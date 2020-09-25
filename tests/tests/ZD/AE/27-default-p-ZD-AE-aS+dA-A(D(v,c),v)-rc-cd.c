//Classification: #default/p/ZD/AE/aS+dA/A(D(v,c),v)/rc/cd
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov

#include <stdio.h>
#include <malloc.h>

int recursion(int a) {
	if (a > 5) {
		return (a);
	}
	a++;
	return (recursion(a));
}

int main(void) {
	int *p;
	int a = -2;
	int b;
	
	p = (int *)malloc(sizeof(int) * 3);
	if (p == 0) {
		return 1;
	}
	p[2] = 6;
	
	if (a < -3) {
		a = recursion (a);
	}

	b = 1 / (a - p[2]);
	printf ("%d", b);

	free(p);
	return 0;
}
