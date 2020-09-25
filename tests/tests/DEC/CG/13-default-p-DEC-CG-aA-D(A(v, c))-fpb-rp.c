//Classification: #default/p/DEC/CG/aA/D(A(v, c))/fpb/rp
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment:

#include <stdio.h>

int func (int a) {
	printf ("%d", a);
	return 0;
}

void f(int a[]) {
	int i;
	for (i = 0; i < 32; i++)
		a[i] = 1;
}

int main(void) {
	int a[32];
	f(a);
	if (a[3]) {
		func (a[3]);
	}
	return 0;
}
