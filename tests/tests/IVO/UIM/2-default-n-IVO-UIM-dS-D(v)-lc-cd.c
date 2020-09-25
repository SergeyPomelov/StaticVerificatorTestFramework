//Classification: #default/n/IVO/UIM/dS/D(v)/lc/cd
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment:

#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
	int b, *p;
	p = (int *)malloc(sizeof(int));
	if (p==0) {
		return 1;
	}
	scanf ("%d", &b);
	if (b>0) {
		(*p) = 10;
	}
	printf ("%d", *p);
	free(p);
	return 0;
}
