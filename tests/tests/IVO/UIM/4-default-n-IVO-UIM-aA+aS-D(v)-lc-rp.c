//Classification: #default/n/IVO/UIM/aA+aS/D(v)/lc/rp
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment:

#include <stdio.h>

int main(void) 
{
	int a[10], i, *p = &a[7];
	for (i = 0; i<5; i++) {
		a[i]=i;
	}
	printf ("%d", *p);
	return 0;
}
