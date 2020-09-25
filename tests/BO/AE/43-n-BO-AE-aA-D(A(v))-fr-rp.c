//Classification: n/BO/AE/aA/D(A(v))/fr/rp
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include <stdio.h>

int *func(int *q) {
    int b;
    int i;
	scanf("%d",&b);
	for(i=0;i<32;i++) {
		q[b+i] = 2*i; 
	}
	return q;
}

int main(void) 
{
	int a[32];
	printf("%d",*(func(a)+31));
	return 0;
}
