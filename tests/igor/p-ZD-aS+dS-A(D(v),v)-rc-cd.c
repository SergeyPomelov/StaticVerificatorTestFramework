//Classification: p/ZD/aS+dS/A(D(v),v)/rc/cd
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
	int a = -2;
	int b;
	
	p = (int *)malloc(sizeof(int));
	*p = 6;
	
	if (a < -3) {
		a = recursion (a);
	}

	b = 1 / (a - *p);

	return 0;
}
