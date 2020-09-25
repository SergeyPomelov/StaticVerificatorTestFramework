//Classification: #default/n/IVO/UIM/aS+aS/D(v)/fpb/ln
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment:

#include <stdio.h>

void func(int** p) {
	int a;
	(*p) = &a;
}

int main(void) 
{
	int *p;
	func(&p);
	printf ("%d", *p);
	return 0;
}
