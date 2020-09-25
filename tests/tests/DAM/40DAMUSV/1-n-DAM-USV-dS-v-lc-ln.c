//Classification: #default/n/DAM/USV/dS/v/lc/ln
//Written by: Pomelov Sergey
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
	free(p);
	printf("%d",*p);
	return 0;
}
