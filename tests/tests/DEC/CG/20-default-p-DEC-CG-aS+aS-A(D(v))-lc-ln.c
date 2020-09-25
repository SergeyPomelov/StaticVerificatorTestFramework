//Classification: #default/p/DEC/CG/aS+aS/A(D(v))/lc/ln
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment:

#include <stdio.h>

int func (int a) {
	printf ("%d", a);
	return 0;
}

int main(void)
{
	int b = 1, *p = &b, *p1 = &b;
	if (*p - *p1 + 1) {
		func (b);
	}
	return 0;
}
