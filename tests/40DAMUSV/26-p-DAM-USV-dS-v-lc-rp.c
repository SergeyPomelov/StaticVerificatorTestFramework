//Classification: p/DAM/USV/dS/v/lc/rp
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>
#include <malloc.h>

int main(void) 
{
	int *p;
	int i;
	p = (int*)malloc(sizeof(int));
		if (p==NULL) {
			printf("alloc error");
			return 1;
		}
	*p = 1;	
		for(i=1; i<100; i++) {	
			printf("%d",*p);
		}
	free(p);	
	return 0;
}
