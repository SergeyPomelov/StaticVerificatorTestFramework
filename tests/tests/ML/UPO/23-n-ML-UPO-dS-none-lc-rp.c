//Classification: #default/n/ML/UPO/dS/none/lc/rp
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment: we allocate many copies of 'p', but free it only once

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int *p, i;
	
	for (i = 0; i<10; i++) {
		p = (int *)malloc(sizeof(int));
		if (p==0) {
			return 1;
		}

		(*p) = i;
		printf ("%d", *p);
	}
	
	(*p) = 1234;
	printf ("%d", *p);
	free(p);
	
	return 0;
}
