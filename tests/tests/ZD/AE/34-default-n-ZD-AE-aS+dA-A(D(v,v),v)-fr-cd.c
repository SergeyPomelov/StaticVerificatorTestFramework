//Classification: #default/n/ZD/AE/aS+dA/A(D(v,v),v)/fr/cd
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov

#include <malloc.h>
#include <stdio.h>

int func (int c) {
	c+=2;
	return (c);
}

int main(void) {
	int a = 1;
	int b;
	int v = 2;

	int *p;
	p = (int *)malloc(sizeof(int) * 3);
	if (p == 0) {
		return 1;
	}
	p[1] = 5;
	p[2] = 6;
	
	v = func(v);
	
	if (a == 1) {
		b = 1 / (p[a]-v);
		printf ("%d", b);
	}

	free(p);
	return 0;
}
