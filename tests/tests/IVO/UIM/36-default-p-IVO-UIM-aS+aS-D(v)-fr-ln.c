//Classification: #default/p/IVO/UIM/aS+aS/D(v)/fr/ln
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment:

#include <stdio.h>

int* func() {
	int a=10, *p;
	p = &a;
	return p;
}

int main(void) 
{
	printf ("%d", *func());
	return 0;
}
