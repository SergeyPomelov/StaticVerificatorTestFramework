//Classification: #default/p/ML/UPO/dA/none/lc/rp
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment: we allocate many copies of 'p', but free it only once

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int *p[3];
	int i;
	
	for (i = 0; i<1; i++) {
		p[1] = (int *)malloc(sizeof(int));
		if (p[1]==0) {
			return 1;
		}
		*p[1] = i+10;
		printf ("%d", *p[1]);
	}
	
	*p[1] = 2345;
	
	printf ("%d", *p[1]);
	free(p[1]);
	
	return 0;
}
