//Classification: #default/n/DEC/CG/aS+dS/D(v)/fp/ln
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment:

#include <stdio.h>

int func (int a) {
	printf ("%d", a);
	return 0;
}

void f(int *p) {
	if (*p) {
		func (10);
	}
}

int main(void) {
	int a = 0;
	f(&a);
	return 0;
}
