//Classification: #default/p/IVO/UIM/aS+aS/D(v)/lc/cd
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment:

#include <stdio.h>

int main(void) 
{
	int a, b, *p;
	p = &a;
	scanf ("%d", &b);
	if (b>0) {
		a = 10;
	}
	else {
		a = 20;
	}
	printf ("%d", *p);
	return 0;
}
