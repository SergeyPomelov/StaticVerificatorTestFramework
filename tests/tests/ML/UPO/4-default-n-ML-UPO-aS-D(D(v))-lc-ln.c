//Classification: #default/n/ML/UPO/aS/D(D(v))/lc/ln
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment: 

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int **p;
	
	p = (int**)malloc(sizeof(int*));
	if (p == 0) {
		return 1;
	}
	(*p) = (int*)malloc(sizeof(int));
	if (*p == 0) {
		free(p);
		return 1;
	}

	**p = 10;
	printf("%d", **p);
	
	free(p);

	return 0;
}
