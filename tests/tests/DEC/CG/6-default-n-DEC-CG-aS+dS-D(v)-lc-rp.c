//Classification: #default/n/DEC/CG/aS+dS/D(v)/lc/rp
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment:

#include <stdio.h>

int func (int a) {
	printf ("%d", a);
	return 0;
}

int main(void) {
	int a = 10;
	int *p = &a;
	int i;
	for (i = 0; i < 10; i++)
		(*p)--;
	if (*p) {
		func (a);
	}
	return 0;
}
