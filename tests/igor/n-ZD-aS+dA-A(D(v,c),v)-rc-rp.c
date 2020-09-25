//Classification: n/ZD/aS+dA/A(D(v,c),v)/rc/rp
//Written by: Igor Eremeev

#include <malloc.h>

int recursion(int p) {
	if (p > 5) {
		return (p);
	}
	p++;
	return (recursion(p));
}

int main(void) {
	int *p;
	int a = -6;
	int b;
	
	p = (int *)malloc(sizeof(int) * 3);
	p[2] = 4;
	
	a = recursion (a);

	while (p[2] < 8) {
		p[2]++;
		b = 1 / (a - p[2]);
	}

	return 0;
}
