//Classification: p/BO/AE/dA/D(A(v))/fr/rp
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include <stdio.h>
#include <malloc.h>

int *func(int *q) {
    int i;
	for(i=0;i<32;i++) {
			q[i] = i; 
	}
	return q;
}

int main(void) 
{
	int* a;
	if((a = (int*)malloc(32*sizeof(int)))==NULL) {
		printf("malloc error");	
		return 1;
	}
	printf("%d",*(func(a)+31));
	free(a);
	return 0;
}
