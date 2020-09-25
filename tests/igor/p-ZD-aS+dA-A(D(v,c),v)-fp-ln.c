//Classification: p/ZD/aS+dA/A(D(v,c),v)/fp/ln
//Written by: Igor Eremeev

#include <malloc.h>

int func(int *p) {
	int a = 3, b = 2, c = 1, d;
	d = 1/(p[0]-a);
	d = 1/(p[1]-b);
	d = 1/(p[2]-c);
	return 0;
}

int main(void) {
	int *p;
	
	p = (int *)malloc(sizeof(int) * 3);

	p[0] = 6;
	p[1] = 5;
	p[2] = 2;
	
	func(p);

	return 0;
}
