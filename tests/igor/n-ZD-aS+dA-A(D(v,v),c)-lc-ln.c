//Classification: n/ZD/aS+dA/A(D(v,v),c)/lc/ln
//Written by: Igor Eremeev

#include <malloc.h>

int main(void) {
	int *p;
	int a = 2;
	int b;
	
	p = (int *)malloc(sizeof(int) * 3);
	p[2] = 6;

	b = 1 / (p[a]-6);

	return 0;
}
