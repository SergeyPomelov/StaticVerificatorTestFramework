//Classification: #default/p/ML/UPO/aS/D(D(v))/fp/ln
//Written by: Igor Eremeev
//Reviewed by: Sergey Pomelov
//Comment: 

#include <stdlib.h>
#include <stdio.h>

void func_free(int **p) {
	free (*p);
}

int main(void)
{
	int *p;
	
	p = (int*)malloc(sizeof(int));
	if (p == 0) {
		return 1;
	}
	
	*p = 10;
	printf ("%d", *p);
	
	func_free(&p);

	return 0;
}
