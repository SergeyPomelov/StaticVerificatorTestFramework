//Classification: #default/p/ML/UPO/dS/none/lc/rp
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment: we allocate one copy of 'p', and free it once

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int *p, i;
	
	for (i = 0; i<1; i++) {
		p = (int *)malloc(sizeof(int));
		if (p==0) {
			return 1;
		}
		(*p) = i+10;
		printf ("%d", *p);
	}
	
	(*p) = 1234;
	printf ("%d", *p);
	free(p);
	
	return 0;
}
