//Classification: #default/p/BO/UVIA/aA/D(A(v))/fr/ln
//Written by: Sergey Pomelov
//Reviewed by: Igor Eremeev
//Comment:

#include <stdio.h>

int *func(int *q) {
    int i = 31;
	q[i] = 2*i; 
	return q;
}

int main(void) 
{
	int a[32];
	printf("%d",*(func(a)+31));
	return 0;
}
