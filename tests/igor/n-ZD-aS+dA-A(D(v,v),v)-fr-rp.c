//Classification: n/ZD/aS+dA/A(D(v,v),v)/fr/rp
//Written by: Igor Eremeev

#include <malloc.h>

int func (int c) {
	c+=2;
	return (c);
}

int main(void) {
	int *p;
	int a = 0;
	int b;
	int v = 3;
	
	p = (int *)malloc(sizeof(int) * 3);
	p[2] = 5;
	p[1] = 6;
	p[0] = 4;
	
	v = func(v);
	
	while (a < 2) {
		a++;
		b = 1 / (p[a]-v);
	}

	return 0;
}
