//Classification: n/ZD/aS+dS/A(D(v),v)/fpb/cd+rp
//Written by: Igor Eremeev

#include <malloc.h>

int func(int *p) {
	(*p)+=2;
	return 0;
}

int main(void) {
	int *p;
	int a = 6;
	int b;
	
	p = (int *)malloc(sizeof(int));
	*p = 2;
	
	while (*p <= 7) {
		func(p);
		if (*p <= 5) {
			b = 1 / (a - *p);
		}
		else {
			b = 1 / (a + *p);
		}
	}
	
	return 0;
}
