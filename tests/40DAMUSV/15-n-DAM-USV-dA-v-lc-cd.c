//Classification: n/DAM/USV/dA/v/lc/cd
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>
#include <malloc.h>

int main(void) 
{
	const int size = 64;
	int *p;
	int c;
	p = (int*)malloc(size*sizeof(int));
		if (p==NULL) {
			printf("alloc error");
			return 1;
		}
	*(p+size-1) = 1;	
    scanf("%d",&c);
		if (c==1) {	
		free(p);
		printf("%d",*(p+size-1));
		} else {
		printf("%d",*(p+size-1));
		free(p);
		}
		return 0;
}
