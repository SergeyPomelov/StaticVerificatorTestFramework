//Classification: p/BO/AE/aA/D(A(v))/fr/cd
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include <stdio.h>

int *func(int *q) {
    int i = 31;
	int b;
	scanf("%d",&b);
	if (b==0) {
		q[b+i] = 2*i; 
	} else {
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
