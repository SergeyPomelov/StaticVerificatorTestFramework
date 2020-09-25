//Classification: #default/n/IVO/UIM/aA+aS/D(v)/fpb/rp
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment:

#include <stdio.h>

void func(int** p) {
	int a[10], i;
	(*p) = &a[7];
	for (i = 0; i<5; i++) {
		a[i]=i;
	}
}

int main(void) 
{
	int *p;
	func(&p);
	printf ("%d", *p);
	return 0;
}
