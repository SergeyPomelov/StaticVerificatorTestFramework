//Classification: #default/n/IVO/UIM/dA/D(v,c)/lc/rp
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment:

#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
	int i, *p;
	p = (int *)malloc(sizeof(int)*10);
	if (p==0) {
		return 1;
	}
	for (i = 0; i<5; i++) {
		(*(p+i)) = i;
	}
	printf ("%d", *(p+6));
	free(p);
	return 0;
}
