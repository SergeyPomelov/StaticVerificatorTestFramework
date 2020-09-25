//Classification: #default/p/IVO/UIM/aS+aS/D(v)/fr/cd
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment:

#include <stdio.h>

int* func() {
	int a, b, *p;
	p = &a;
	scanf ("%d", &b);
	if (b>0) {
		a = 10;
	}
	else {
		a = 20;
	}
	return p;
}

int main(void) 
{
	printf ("%d", *func());
	return 0;
}
