//Classification: #default/p/DAM/USV/dA/v/lc/rp
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>
#include <malloc.h>

int main(void) 
{
	const int size = 64;
	int *p;
	int i;
	p = (int*)malloc(size*sizeof(int));
		if (p==NULL) {
			printf("alloc error");
			return 1;
		}
		for(i=0; i<size; i++) {	
			*(p+i) = 1;
			printf("%d",*(p+i));
		}
	free(p);	
	return 0;
}
