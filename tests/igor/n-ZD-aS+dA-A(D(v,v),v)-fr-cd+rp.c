//Classification: n/ZD/aS+dA/A(D(v,v),v)/fr/cd+rp
//Written by: Igor Eremeev

#include <malloc.h>

int func (int c) {
	c+=2;
	return (c);
}

int main(void) {
	
	int a = 0;
	int b;
	int v = 3;
	
	int *p;
	p = (int *)malloc(sizeof(int) * 3);
	p[2] = 5;
	p[1] = 4;
	p[0] = 7;

	v = func (v);
	
	while (a < 2) {
		a++;
		if (a == 2) {
			b = 1 / (p[a]-v);
		}
	}
	
	return 0;
}
