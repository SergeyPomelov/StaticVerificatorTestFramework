//Classification: #default/n/DEC/CG/aS/A(v)/lc/ln
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
	int a = 1, b = 1;
	if (a-b) {
		func (a);
	}
	return 0;
}
