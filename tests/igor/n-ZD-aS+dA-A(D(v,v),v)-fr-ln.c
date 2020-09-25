//Classification: n/ZD/aS+dA/A(D(v,v),v)/fr/ln
//Written by: Igor Eremeev

#include <malloc.h>

int func (int c) {
	c+=2;
	return (c);
}

int main(void) {
	int *p;
	int a = 2;
	int v = 3;
	int b;
	
	p = (int *)malloc(sizeof(int) * 3);
	p[2] = 5;
	
	v = func(v);

	b = 1 / (p[a]-v);

	return 0;
}
