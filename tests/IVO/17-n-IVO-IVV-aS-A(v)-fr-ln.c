//Classification: n/IVO/IVV/aA/D(A(v))/fr/ln
//Written by: Sergey Pomelov
//Reviewed by:
//Comment:

#include <stdio.h>

int func(int a) 
{
	int b;
	return a + b;
}

int main(void) 
{
	int a = 1;
	scanf("%d",&a);
	a = func(a);
	printf("%d ",a); 
	return 0;
}
