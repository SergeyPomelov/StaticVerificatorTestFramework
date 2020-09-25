//Classification: #default/n/DEC/CG/aS/v/lc/ln
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
	int a = 0;
	if (a) {
		func (a);
	}
	return 0;
}
