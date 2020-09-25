//Classification: n/BO/AE/dA/D(A(v))/fr/rp
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include <stdio.h>
#include <malloc.h>

float *func(float *q) {
    int b;
    int i;
	scanf("%d",&b);
	for(i=0;i<32;i++) {
		q[b+i] = i; 
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
