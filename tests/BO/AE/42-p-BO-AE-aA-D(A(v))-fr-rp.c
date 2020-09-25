//Classification: p/BO/AE/aA/D(A(v))/fr/rp
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include <stdio.h>

float *func(float *q) {
    int i;
	for(i=0;i<32;i++) {
			q[i] = i; 
	}
	return q;
}

int main(void) 
{
	float a[32];
	printf("%f",*(func(a)+31));
	return 0;
}
