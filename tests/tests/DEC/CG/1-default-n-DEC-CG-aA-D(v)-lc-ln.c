//Classification: #default/n/DEC/CG/aA/D(v)/lc/ln
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
	int b[1];
	b[0] = 0;
	if (b[0]) {
		func(b[0]);
	}
	return 0;
}
