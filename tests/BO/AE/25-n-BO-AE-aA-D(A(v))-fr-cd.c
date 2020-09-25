//Classification: n/BO/AE/aA/D(A(v))/fr/cd
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include <stdio.h>

float *func(float *q) {
    int i = 31;
	int b;
	scanf("%d",&b);
	if (b==0) {
		q[b+i] = i; 
	} else {
		q[b] = i; 
	}
	return q;
}

int main(void) 
{
	float a[32];
	printf("%f",*(func(a)+31));
	return 0;
}
