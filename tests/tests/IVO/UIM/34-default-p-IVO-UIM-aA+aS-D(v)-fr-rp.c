//Classification: #default/p/IVO/UIM/aA+aS/D(v)/fr/rp
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment:

#include <stdio.h>

int* func() {
	int a[10], i, *p = &a[7];
	for (i = 0; i<10; i++) {
		a[i]=i;
	}
	return p;
}

int main(void) 
{
	printf ("%d", *func());
	return 0;
}
