//Classification: n/ZD/aS+dA/A(D(v,v),c)/lc/cd
//Written by: Igor Eremeev

#include <malloc.h>

int main(void) {
	int a = 1;
	int b;

	int *p;
	p = (int *)malloc(sizeof(int) * 3);
	p[1] = 6;
	p[2] = 5;
	
	if (a == 1) {
		b = 1 / (p[a]-6);
	}

	return 0;
}
