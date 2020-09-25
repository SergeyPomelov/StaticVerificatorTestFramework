//Classification: n/ZD/aS+dA/A(D(v,c),v)/fp/cd+rp
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
	int a = 2;
	int b = 3;
	
	p = (int *)malloc(sizeof(int) * 3);

	p[0] = 6;
	p[1] = 5;
	
	while (b <= 5) {
		if (a == 2) {
			p[2] = b;
		}
		else {
			p[2] = b-1;
		}
		b++;
		func(p);
	}

	return 0;
}
