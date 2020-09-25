//Classification: #default/p/DEC/CG/aS+dS/v/fr/ln
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment:

#include <stdio.h>

int func (int a) {
	printf ("%d", a);
	return 0;
}

int f(int *p) {
	return *p - 1;
}

int main(void) {
	int a = 2;
	if (f(&a)) {
		func (a);
	}
	return 0;
}
