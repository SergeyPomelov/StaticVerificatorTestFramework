//Classification: p/ZD/aS+dA/A(D(v,v),c)/lc/ln
//Written by: Igor Eremeev

#include <malloc.h>

int main(void) {
	int *p;
	int a = 1;
	int b;
	
	p = (int *)malloc(sizeof(int) * 3);
	p[2] = 6;
	p[1] = 7;

	b = 1 / (p[a]-6);

	return 0;
}
