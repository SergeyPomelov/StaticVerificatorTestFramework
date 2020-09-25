//Classification: #default/n/IVO/UIM/aS+aS/D(v)/fpb/cd
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment:

#include <stdio.h>

void func(int** p) {
	int a, b;
	(*p) = &a;
	scanf ("%d", &b);
	if (b>0) {
		a = 10;
	}
}

int main(void) 
{
	int *p;
	func(&p);
	printf ("%d", *p);
	return 0;
}
