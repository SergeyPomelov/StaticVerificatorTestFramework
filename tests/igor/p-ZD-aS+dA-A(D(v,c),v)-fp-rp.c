//Classification: p/ZD/aS+dA/A(D(v,c),v)/fp/rp
//Written by: Igor Eremeev

#include <malloc.h>

int func(int *p) {
	int a = 3, b = 2, c = 5, d;
	d = 1/(p[0]-a);
	d = 1/(p[1]-b);
	d = 1/(p[2]-c);
	return 0;
}

int main(void) {
	int *p;
	int a = 3;
	
	p = (int *)malloc(sizeof(int) * 3);

	p[0] = 6;
	p[1] = 5;
	
	while (a <= 4) {
		p[2] = a++;	
		func(p);
	}
	
	return 0;
}
