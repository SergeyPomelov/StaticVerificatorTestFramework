//Classification: p/BO/AE/aA/D(A(v))/fr/rp
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include <stdio.h>

int *func(int *q) {
    int i;
	for(i=0;i<32;i++) {
			q[i] = i; 
	}
	return q;
}

int main(void) 
{
	int a[32];
	printf("%d",*(func(a)+31));
	return 0;
}
