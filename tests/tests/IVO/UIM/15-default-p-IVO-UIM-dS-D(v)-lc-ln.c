//Classification: #default/p/IVO/UIM/dS/D(v)/lc/ln
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment:

#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
	int *p;
	p = (int *)malloc(sizeof(int));
	if (p==0) {
		return 1;
	}
	(*p)=10;
	printf ("%d", *p);
	free(p);
	return 0;
}
