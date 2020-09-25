//Classification: n/BO/AE/aA/D(A(v))/fr/ln
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include <stdio.h>

float *func(float *q) {
    int b;
    int i = 31;
	scanf("%d",&b);
	q[b+i] = i; 
	return q;
}

int main(void) 
{
	float a[32];
	printf("%f",*(func(a)+31));
	return 0;
}
