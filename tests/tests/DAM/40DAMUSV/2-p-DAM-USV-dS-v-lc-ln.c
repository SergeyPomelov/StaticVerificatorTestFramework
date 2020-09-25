//Classification: #default/p/DAM/USV/dS/v/lc/ln
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>
#include <malloc.h>

int main(void) 
{
	int *p;
	p = (int*)malloc(sizeof(int));
		if (p==NULL) {
			printf("alloc error");
			return 1;
		}
	*p = 1;
	printf("%d",*p);
	free(p);
	return 0;
}
