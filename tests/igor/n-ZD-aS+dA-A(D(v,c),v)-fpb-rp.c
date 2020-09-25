//Classification: n/ZD/aS+dA/A(D(v,c),v)/fpb/rp
//Written by: Igor Eremeev

#include <malloc.h>

int func(int *p) {
	p[0]+=1;
	p[1]+=2;
	p[2]+=3;
	return 0;
}

int main(void) {
	int *p;
	int a = 6;
	int b;

	p = (int *)malloc(sizeof(int) * 3);
	p[0] = 3;
	p[1] = 4;
	p[2] = 5;

	while (p[1] <= 7) {
		func(p);
		b = 1 / (a - p[1]);
	}

	return 0;
}
