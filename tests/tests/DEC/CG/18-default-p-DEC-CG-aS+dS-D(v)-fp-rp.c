//Classification: #default/p/DEC/CG/aS+dS/D(v)/fp/rp
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment:

#include <stdio.h>

int func (int a) {
	printf ("%d", a);
	return 0;
}

void f(int *p, int c) {
	int i;
	for (i = 0; i < c; i++) {
		(*p)--;
	}
	if (*p) {
		func (c);
	}
}

int main(void) {
	int a = 10;
	f(&a, a-1);
	return 0;
}
