//Classification: n/ZD/aS+dA/A(D(v,v),v)/fr/cd
//Written by: Igor Eremeev

#include <malloc.h>

int func (int c) {
	c+=2;
	return (c);
}

int main(void) {
	int a = 1;
	int b;
	int v = 3;

	int *p;
	p = (int *)malloc(sizeof(int) * 3);
	p[1] = 5;
	p[2] = 6;
	
	v = func(v);
	
	if (a == 1) {
		b = 1 / (p[a]-v);
	}

	return 0;
}
