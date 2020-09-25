//Classification: n/BO/AE/dA/D(A(v))/fr/ln
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include <stdio.h>
#include <malloc.h>

float *func(float *q) {
    int b;
    int i = 31;
	scanf("%d",&b);
	q[b+i] = i; 
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
