//Classification: n/ZD/aS+dA/A(D(v,c),v)/rc/ln
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
	p[2] = 6;
	
	a = recursion (a);

	b = 1 / (a - p[2]);

	return 0;
}
