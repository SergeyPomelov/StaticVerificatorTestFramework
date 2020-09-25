//Classification: #default/p/DEC/CG/aS+dS/v/fpb/ln
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment:

#include <stdio.h>

int func (int a) {
	printf ("%d", a);
	return 0;
}

void f(int *p) {
	*p = 1;
}

int main(void) {
	int a = 1;
	f(&a);
	if (a) {
		func (a);
	}
	return 0;
}
