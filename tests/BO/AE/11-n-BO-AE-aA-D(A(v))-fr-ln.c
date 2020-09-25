//Classification: n/BO/AE/aA/D(A(v))/fr/ln
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include <stdio.h>

int *func(int *q) {
    int b;
    int i = 31;
	scanf("%d",&b);
	q[b+i] = 2*i; 
	return q;
}

int main(void) 
{
	int a[32];
	printf("%d",*(func(a)+31));
	return 0;
}
