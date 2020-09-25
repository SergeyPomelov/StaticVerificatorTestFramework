//Classification: #default/n/DEC/CG/aA/D(A(v, c))/fr/rp
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment:

#include <stdio.h>

int func (int a) {
	printf ("%d", a);
	return 0;
}

int f(void) {
	return 0;
}

int main(void) {
	int a[32];
	int i;
	for (i = 0; i < 32; i++) {
		a[i] = f();
	}
	if (a[3]) {
		func (a[6]);
	}
	return 0;
}
