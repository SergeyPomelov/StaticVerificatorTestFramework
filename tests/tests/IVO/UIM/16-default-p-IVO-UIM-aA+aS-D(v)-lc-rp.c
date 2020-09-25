//Classification: #default/p/IVO/UIM/aA+aS/D(v)/lc/rp
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment:

#include <stdio.h>

int main(void) 
{
	int a[10], i, *p = &a[7];
	for (i = 0; i<10; i++) {
		a[i]=i;
	}
	printf ("%d", *p);
	return 0;
}
