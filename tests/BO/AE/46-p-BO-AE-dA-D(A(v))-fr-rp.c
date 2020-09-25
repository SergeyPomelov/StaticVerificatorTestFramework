//Classification: p/BO/AE/dA/D(A(v))/fr/rp
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include <stdio.h>
#include <malloc.h>

float *func(float *q) {
    int i;
	for(i=0;i<32;i++) {
			q[i] = i; 
	}
	return q;
}

int main(void) 
{
	float* a;
	if((a = (float*)malloc(32*sizeof(float)))==NULL) {
		printf("malloc error");	
		return 1;
	}
	printf("%f",*(func(a)+31));
	free(a);
	return 0;
}
